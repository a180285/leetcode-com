cmake_minimum_required(VERSION 3.10)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(Tutorial VERSION 1.0)

file(GLOB_RECURSE source_list "src/*.cpp")

# add the executable
add_executable(Tutorial ${source_list})

add_subdirectory(third-party/googletest-release-1.10.0)

target_link_libraries(Tutorial PUBLIC gtest)


target_include_directories(Tutorial PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/third-party/googletest-release-1.10.0/googletest/include"
        )