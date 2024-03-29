set(BINARY ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false *.hpp *.cpp)



set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

function(add_module name)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
          if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            # using Clang
            add_custom_target(${name}.pcm
                    COMMAND
                        ${CMAKE_CXX_COMPILER}
                        -std=c++20
                        -c
                        ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
                        -Xclang -emit-module-interface
                        -o ${PREBUILT_MODULE_PATH}/${name}.pcm
                    )
            elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            # using GCC
				add_custom_target(${name}.pcm
                    COMMAND
                        ${CMAKE_CXX_COMPILER}
                        -std=c++2a
                        -fmodules-ts
                        -c
                        ${CMAKE_CURRENT_SOURCE_DIR}/${ARGN}
                        -o ${name}.pcm
                    )
				#g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
            else()
                message( FATAL_ERROR "Your compiler is not supported!" )
                #  find setting for other compiler here
                # https://www.steinzone.de/wordpress/modules-in-c20-and-cmake/
          endif()
endfunction()

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
  add_compile_options(-fprebuilt-module-path=${PREBUILT_MODULE_PATH})

  add_module(math math1.icx)
  add_executable(${BINARY}_app ${SOURCES})
  add_dependencies(${BINARY}_app math.pcm)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
  add_compile_options(-fmodules-ts)
  add_module(math math1.cpp)
  add_module(coroutines coroutines.cpp)
  add_executable(${BINARY}_app main.cpp)

  add_custom_target(math math1.cpp)
  add_custom_target(coroutines coroutines.cpp)

  target_link_options(${BINARY}_app  PUBLIC "LINKER:math.pcm;coroutines.pcm")
  add_dependencies(${BINARY}_app  math.pcm coroutines.pcm)

else()
  message( FATAL_ERROR "Your compiler is not supported!" )
  #  find setting for other compiler here
  # https://www.steinzone.de/wordpress/modules-in-c20-and-cmake/

endif()



