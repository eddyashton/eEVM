enable_testing()

add_executable(eevm_tests
  ${CMAKE_CURRENT_SOURCE_DIR}/harness.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/rlp.cpp
)

target_link_libraries(eevm_tests
  eevm::simple
  doctest::doctest
)

add_test(
  eevm_tests eevm_tests
)

if(NOT ENV{TEST_DIR}) 
  set_tests_properties(eevm_tests
    PROPERTIES
      ENVIRONMENT TEST_DIR=${PROJECT_SOURCE_DIR}/3rdparty/test_cases
  )
endif()
