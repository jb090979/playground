cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME roman_number)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
