cmake_minimum_required(VERSION 3.0)
project(cppa)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Pylene REQUIRED)

add_subdirectory(include/pybind11)

pybind11_add_module(cppa src/main.cc)
target_link_libraries(cppa PRIVATE Pylene::Pylene)
