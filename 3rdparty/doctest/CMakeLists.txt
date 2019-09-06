cmake_minimum_required(VERSION 3.10)

project(doctest)

add_library(doctest INTERFACE)
add_library(doctest::doctest ALIAS doctest)

target_include_directories(doctest INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)
