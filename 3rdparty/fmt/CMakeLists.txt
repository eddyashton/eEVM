cmake_minimum_required(VERSION 3.10)

project(fmt)

add_library(fmt-header-only INTERFACE)
add_library(fmt::fmt-header-only ALIAS fmt-header-only)

target_compile_definitions(fmt-header-only INTERFACE FMT_HEADER_ONLY=1)

target_include_directories(fmt-header-only INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)
