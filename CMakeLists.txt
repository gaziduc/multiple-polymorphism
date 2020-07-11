cmake_minimum_required(VERSION 3.0)
project(cppa)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Pylene REQUIRED)

add_subdirectory(include/pybind11)

add_library(core STATIC src/convert.cc)
set_target_properties(core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_link_libraries(core PRIVATE Pylene::Pylene)

pybind11_add_module(pylene src/main.cc)
target_link_libraries(pylene PRIVATE core)
