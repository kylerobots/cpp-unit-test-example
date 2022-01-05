cmake_minimum_required(VERSION 3.14)
project(cpp_unit_test_example
  VERSION 1.0.0
  DESCRIPTION "An example of unit test utilities in C++"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)

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

### UNIT TESTING WITH GOOGLE TEST ###
# This also enables testing for this package.
include(CTest)
# Only do all the testing if requested (i.e. BUILD_TESTING=ON). Default is ON.
if(BUILD_TESTING)
  # Use FetchContent to retrieve the Google Test source code.
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
  )
  FetchContent_MakeAvailable(googletest)
  # After Google Test is available, it still needs included in the project.
  include(GoogleTest)
  # Create the testing executable.
  add_executable(test_classifyTriangle
    test/test_classifyTriangle.cpp
  )
  target_link_libraries(test_classifyTriangle
    gtest_main
    triangle_classifier
  )
  # Tell CTest about the testing code. This is preferable to add_test as it
  # provides more information at test time to CTest.
  gtest_discover_tests(test_classifyTriangle)
endif(BUILD_TESTING)
