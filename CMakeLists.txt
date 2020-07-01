cmake_minimum_required(VERSION 3.0)
project(cppa)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

add_executable(cppa src/main.cc)

find_package(Pylene REQUIRED)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(cppa PRIVATE ${PYTHON_LIBRARIES} Pylene::Pylene)
