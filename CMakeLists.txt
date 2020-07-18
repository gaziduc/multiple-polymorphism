cmake_minimum_required(VERSION 3.0)
project(cppa)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

find_package(Pylene REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(pylene MODULE
                            src/main.cc
                            src/convert.cc
                            include/pln/core/se.cc
                            include/pln/morpho/dilation.cc
                            include/pln/morpho/erosion.cc
                            include/pln/morpho/opening.cc
                            include/pln/morpho/closing.cc
                    )

target_link_libraries(pylene PRIVATE Pylene::Pylene)

add_custom_target(test make && python3 ../tests/testsuite.py)