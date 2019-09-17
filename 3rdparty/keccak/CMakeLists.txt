cmake_minimum_required(VERSION 3.10)

project(keccak)

file(GLOB KECCAK_SOURCES
  keccak/*.c
)

add_library(keccak INTERFACE)
add_library(keccak::keccak ALIAS keccak)

target_sources(keccak
  INTERFACE
    ${KECCAK_SOURCES}
)

target_include_directories(keccak INTERFACE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
)
