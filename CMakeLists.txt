cmake_minimum_required(VERSION 3.10)

project(eevm)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0076 NEW)

set(Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")
find_package(Boost 1.60.0 REQUIRED)

add_subdirectory(3rdparty/fmt)
add_subdirectory(3rdparty/nlohmann)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# eevm_core library
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
add_library(eevm_core STATIC)

target_include_directories(eevm_core
  PUBLIC
    include
    ${Boost_INCLUDE_DIR}
)

target_sources(eevm_core
  PUBLIC
    src/processor.cpp
    src/stack.cpp
    src/transaction.cpp
    src/util.cpp
)

target_link_libraries(eevm_core
  fmt::fmt-header-only
  nlohmann_json::nlohmann_json
)