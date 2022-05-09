set(BINARY ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.hpp *.cpp)
#add_executable(${BINARY}_run ${SOURCES})
#target_compile_definitions(${BINARY}_run PUBLIC -DMAIN)

add_library(${BINARY}_lib STATIC ${SOURCES})
set_property(TARGET ${BINARY}_lib PROPERTY CXX_STANDARD 20)

