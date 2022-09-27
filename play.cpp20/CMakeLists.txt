cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME playcpp20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)

add_subdirectory(src)

