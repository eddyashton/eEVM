project(eevm_core)

set(Boost_ADDITIONAL_VERSIONS "1.67" "1.67.0")
find_package(Boost 1.60.0 REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)
add_library(eevm::core ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  INTERFACE
    ${PROJECT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIR}
)

target_sources(${PROJECT_NAME}
  INTERFACE
    ${PROJECT_SOURCE_DIR}/src/disassembler.cpp
    ${PROJECT_SOURCE_DIR}/src/processor.cpp
    ${PROJECT_SOURCE_DIR}/src/stack.cpp
    ${PROJECT_SOURCE_DIR}/src/transaction.cpp
    ${PROJECT_SOURCE_DIR}/src/util.cpp
)

target_link_libraries(${PROJECT_NAME}
  INTERFACE
    fmt::fmt-header-only
    keccak::keccak
    nlohmann_json::nlohmann_json
)