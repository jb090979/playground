# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jens/project/playground

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jens/project/playground

# Include any dependencies generated for this target.
include HelloWorld/CMakeFiles/Tutorial.dir/depend.make

# Include the progress variables for this target.
include HelloWorld/CMakeFiles/Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include HelloWorld/CMakeFiles/Tutorial.dir/flags.make

HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.o: HelloWorld/CMakeFiles/Tutorial.dir/flags.make
HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.o: HelloWorld/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jens/project/playground/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.o"
	cd /home/jens/project/playground/HelloWorld && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tutorial.dir/hello.cpp.o -c /home/jens/project/playground/HelloWorld/hello.cpp

HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tutorial.dir/hello.cpp.i"
	cd /home/jens/project/playground/HelloWorld && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jens/project/playground/HelloWorld/hello.cpp > CMakeFiles/Tutorial.dir/hello.cpp.i

HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tutorial.dir/hello.cpp.s"
	cd /home/jens/project/playground/HelloWorld && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jens/project/playground/HelloWorld/hello.cpp -o CMakeFiles/Tutorial.dir/hello.cpp.s

# Object files for target Tutorial
Tutorial_OBJECTS = \
"CMakeFiles/Tutorial.dir/hello.cpp.o"

# External object files for target Tutorial
Tutorial_EXTERNAL_OBJECTS =

HelloWorld/Tutorial: HelloWorld/CMakeFiles/Tutorial.dir/hello.cpp.o
HelloWorld/Tutorial: HelloWorld/CMakeFiles/Tutorial.dir/build.make
HelloWorld/Tutorial: HelloWorld/CMakeFiles/Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jens/project/playground/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tutorial"
	cd /home/jens/project/playground/HelloWorld && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
HelloWorld/CMakeFiles/Tutorial.dir/build: HelloWorld/Tutorial

.PHONY : HelloWorld/CMakeFiles/Tutorial.dir/build

HelloWorld/CMakeFiles/Tutorial.dir/clean:
	cd /home/jens/project/playground/HelloWorld && $(CMAKE_COMMAND) -P CMakeFiles/Tutorial.dir/cmake_clean.cmake
.PHONY : HelloWorld/CMakeFiles/Tutorial.dir/clean

HelloWorld/CMakeFiles/Tutorial.dir/depend:
	cd /home/jens/project/playground && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jens/project/playground /home/jens/project/playground/HelloWorld /home/jens/project/playground /home/jens/project/playground/HelloWorld /home/jens/project/playground/HelloWorld/CMakeFiles/Tutorial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : HelloWorld/CMakeFiles/Tutorial.dir/depend

