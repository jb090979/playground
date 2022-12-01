cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME playcpp)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_subdirectory(src)



# exten compile options
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
#set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")