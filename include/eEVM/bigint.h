// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include <boost/endian/conversion.hpp>
#include <boost/functional/hash/hash.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <fmt/format.h>
#include <limits>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

/* Boosts big integers behave (sort of) unexpected in the following sense.
numeric_limits<int256_t>::max() == numeric_limits<uint256_t>::max() == (1 <<
256) -1 I.e., the sign is stored in a separate bit.
*/

using uint256_t = boost::multiprecision::uint256_t;
using uint512_t = boost::multiprecision::uint512_t;

inline auto from_hex_str(const std::string& s)
{
  std::stringstream ss;
  ss << std::hex << s;
  uint256_t v;
  ss >> v;
  return v;
}

inline auto to_hex_str(const uint256_t& v)
{
  std::stringstream ss;
  ss << "0x" << std::hex << v;
  return ss.str();
}

inline auto to_lower_hex_str(const uint256_t& v)
{
  auto s = to_hex_str(v);
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

template <typename Iterator>
auto from_big_endian(const Iterator begin, const Iterator end)
{
  uint256_t v;
  // imports in big endian by default
  boost::multiprecision::import_bits(
    v, begin, end, std::numeric_limits<uint8_t>::digits, true);
  return v;
}

inline void to_big_endian(uint256_t v, uint8_t* out)
{
  // boost::multiprecision::export_bits() does not work here, because it doesn't
  // support fixed width export.

  if ((uintptr_t)out % alignof(uint64_t) == 0)
  {
    // If the target is aligned, we can work faster by writing 64 bits at a time
    uint64_t* o = reinterpret_cast<uint64_t*>(out);
    constexpr uint64_t mask64 = 0xffffffff'ffffffff;

    for (size_t i = 4; i-- > 0;)
    {
      uint64_t n = static_cast<uint64_t>(v & mask64);
      v >>= 64;
      o[i] = boost::endian::native_to_big(n);
    }
  }
  else
  {
    // Else we do it the slow way, byte-by-byte
    uint8_t* o = out;
    constexpr uint8_t mask8 = 0xff;
    for (size_t i = 32; i-- > 0;)
    {
      uint8_t n = static_cast<uint8_t>(v & mask8);
      v >>= 8;
      o[i] = boost::endian::native_to_big(n);
    }
  }
}

inline int get_sign(uint256_t v)
{
  return (v >> 255) ? -1 : 1;
}

inline auto power(uint256_t b, uint64_t e)
{
  return boost::multiprecision::pow(b, static_cast<unsigned int>(e));
}

namespace boost
{
  namespace multiprecision
  {
    inline void to_json(nlohmann::json& j, const uint256_t& v)
    {
      j = to_lower_hex_str(v);
    }

    inline void from_json(const nlohmann::json& j, uint256_t& v)
    {
      v = from_hex_str(j);
    }
  } // namespace multiprecision
} // namespace boost
