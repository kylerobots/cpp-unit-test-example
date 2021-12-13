cmake_minimum_required(VERSION 3.0.0)
project(cpp_unit_test_example
  VERSION 1.0.0
  DESCRIPTION "An example of unit test utilities in C++"
  LANGUAGES CXX
)

add_library(triangle_classifier
  SHARED
  src/classify_triangle.cpp
)
target_include_directories(triangle_classifier
  PUBLIC
    include
)

add_executable(example
  src/example.cpp
)
target_link_libraries(example
  triangle_classifier
)
