cmake_minimum_required(VERSION 3.10)

project(eevm)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0076 NEW)

add_subdirectory(3rdparty/doctest)
add_subdirectory(3rdparty/fmt)
add_subdirectory(3rdparty/keccak)
add_subdirectory(3rdparty/nlohmann)

add_subdirectory(core)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#add_library(eevm_simple SHARED)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
add_executable(disassembler
  samples/disassembler/main.cpp
)

target_link_libraries(disassembler
  eevm::core
)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#add_executable(hello_world
#  samples/hello_world/main.cpp
#)
#
#target_link_libraries(hello_world
#  eevm::core
#)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# eevm_tests executable
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
## Adds BUILD_TESTING option
#include(CTest)
#
#if(BUILD_TESTING)
#  add_executable(eevm_tests
#    tests/harness.cpp
#    tests/main.cpp
#    tests/rlp.cpp
#  )
#
#  target_link_libraries(eevm_tests
#    eevm::core
#    doctest::doctest
#  )
#endif()
#
#add_test(
#  NAME eevm_tests
#  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit_test_wrapper.sh eevm_tests
#)
#
#if(NOT ENV{TEST_DIR}) 
#  set_tests_properties(eevm_tests
#    PROPERTIES
#      ENVIRONMENT TEST_DIR=${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/test_cases
#  )
#endif()