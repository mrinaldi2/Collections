cmake_minimum_required(VERSION 3.16)

#set the project name
project(Collections VERSION 1.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${PROJECT_SOURCE_DIR}/include")
add_executable(Collections "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")