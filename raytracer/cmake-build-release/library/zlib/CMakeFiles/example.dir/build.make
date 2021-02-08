# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alan/Desktop/sinogram/raytracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alan/Desktop/sinogram/raytracer/cmake-build-release

# Include any dependencies generated for this target.
include library/zlib/CMakeFiles/example.dir/depend.make

# Include the progress variables for this target.
include library/zlib/CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include library/zlib/CMakeFiles/example.dir/flags.make

library/zlib/CMakeFiles/example.dir/test/example.o: library/zlib/CMakeFiles/example.dir/flags.make
library/zlib/CMakeFiles/example.dir/test/example.o: ../library/zlib/test/example.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alan/Desktop/sinogram/raytracer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object library/zlib/CMakeFiles/example.dir/test/example.o"
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/example.dir/test/example.o -c /home/alan/Desktop/sinogram/raytracer/library/zlib/test/example.c

library/zlib/CMakeFiles/example.dir/test/example.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example.dir/test/example.i"
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/alan/Desktop/sinogram/raytracer/library/zlib/test/example.c > CMakeFiles/example.dir/test/example.i

library/zlib/CMakeFiles/example.dir/test/example.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example.dir/test/example.s"
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/alan/Desktop/sinogram/raytracer/library/zlib/test/example.c -o CMakeFiles/example.dir/test/example.s

# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/test/example.o"

# External object files for target example
example_EXTERNAL_OBJECTS =

../bin/example: library/zlib/CMakeFiles/example.dir/test/example.o
../bin/example: library/zlib/CMakeFiles/example.dir/build.make
../bin/example: library/zlib/libz.so.1.2.11
../bin/example: library/zlib/CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alan/Desktop/sinogram/raytracer/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../bin/example"
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/zlib/CMakeFiles/example.dir/build: ../bin/example

.PHONY : library/zlib/CMakeFiles/example.dir/build

library/zlib/CMakeFiles/example.dir/clean:
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib && $(CMAKE_COMMAND) -P CMakeFiles/example.dir/cmake_clean.cmake
.PHONY : library/zlib/CMakeFiles/example.dir/clean

library/zlib/CMakeFiles/example.dir/depend:
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alan/Desktop/sinogram/raytracer /home/alan/Desktop/sinogram/raytracer/library/zlib /home/alan/Desktop/sinogram/raytracer/cmake-build-release /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib /home/alan/Desktop/sinogram/raytracer/cmake-build-release/library/zlib/CMakeFiles/example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/zlib/CMakeFiles/example.dir/depend

