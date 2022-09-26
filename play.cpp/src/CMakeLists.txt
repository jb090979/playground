set(BINARY ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.hpp *.cpp)
add_executable(${BINARY}_app ${SOURCES})
