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
CMAKE_BINARY_DIR = /home/alan/Desktop/sinogram/raytracer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sinogram.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sinogram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sinogram.dir/flags.make

CMakeFiles/sinogram.dir/main.cpp.o: CMakeFiles/sinogram.dir/flags.make
CMakeFiles/sinogram.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alan/Desktop/sinogram/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sinogram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sinogram.dir/main.cpp.o -c /home/alan/Desktop/sinogram/raytracer/main.cpp

CMakeFiles/sinogram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sinogram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alan/Desktop/sinogram/raytracer/main.cpp > CMakeFiles/sinogram.dir/main.cpp.i

CMakeFiles/sinogram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sinogram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alan/Desktop/sinogram/raytracer/main.cpp -o CMakeFiles/sinogram.dir/main.cpp.s

# Object files for target sinogram
sinogram_OBJECTS = \
"CMakeFiles/sinogram.dir/main.cpp.o"

# External object files for target sinogram
sinogram_EXTERNAL_OBJECTS =

sinogram: CMakeFiles/sinogram.dir/main.cpp.o
sinogram: CMakeFiles/sinogram.dir/build.make
sinogram: CMakeFiles/sinogram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alan/Desktop/sinogram/raytracer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sinogram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sinogram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sinogram.dir/build: sinogram

.PHONY : CMakeFiles/sinogram.dir/build

CMakeFiles/sinogram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sinogram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sinogram.dir/clean

CMakeFiles/sinogram.dir/depend:
	cd /home/alan/Desktop/sinogram/raytracer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alan/Desktop/sinogram/raytracer /home/alan/Desktop/sinogram/raytracer /home/alan/Desktop/sinogram/raytracer/cmake-build-debug /home/alan/Desktop/sinogram/raytracer/cmake-build-debug /home/alan/Desktop/sinogram/raytracer/cmake-build-debug/CMakeFiles/sinogram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sinogram.dir/depend

