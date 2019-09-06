cmake_minimum_required(VERSION 3.10)

project(eevm)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0076 NEW)

# Vendored dependencies
add_subdirectory(3rdparty/doctest)
add_subdirectory(3rdparty/fmt)
add_subdirectory(3rdparty/keccak)
add_subdirectory(3rdparty/nlohmann)

# Core libraries
add_subdirectory(core)
add_subdirectory(simple)

# Samples
add_subdirectory(samples/disassembler)
add_subdirectory(samples/erc20)
add_subdirectory(samples/hello_world)
add_subdirectory(samples/sum)

# Tests
enable_testing()
add_subdirectory(tests)
