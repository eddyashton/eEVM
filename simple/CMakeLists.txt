cmake_minimum_required(VERSION 3.10)

project(eevm_simple)

add_library(${PROJECT_NAME} SHARED)
add_library(eevm::simple ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_sources(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/src/simpleaccount.cpp
    ${PROJECT_SOURCE_DIR}/src/simpleglobalstate.cpp
    ${PROJECT_SOURCE_DIR}/src/simplestorage.cpp
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    eevm::core
)