cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(fibonacci_sum                # Mandatory
    VERSION 1.0
    DESCRIPTION "fibonacci_sum"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)                         # Use c++17
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "runTests" to be built from the source files listed in the command invocation.
# add_executable(runTests
#     test/gtest_main.cc
#     src/fibonacci_sum.h
#     src/fibonacci_sum.cc
#     test/test_fibonacci_sum.cc)

# Adds an executable target called "fibonacci_sum_main" to be built from the source files listed in the command invocation.
add_executable(fibonacci_sum_main
    src/fibonacci_sum.h
    src/fibonacci_sum.cc
        src/fibonacci_sum_main.cc)

# target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add expected compiler features to a target.
# target_compile_features(runTests PRIVATE cxx_std_17)

# Add compile options to a target.
# target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
target_compile_options(fibonacci_sum_main PRIVATE -Wall -Wextra -Wpedantic -Weffc++)