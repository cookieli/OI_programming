# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/lzx/ide/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lzx/ide/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lzx/CLionProjects/Context/codeForces_590B

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/codeForces_590B.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/codeForces_590B.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/codeForces_590B.dir/flags.make

CMakeFiles/codeForces_590B.dir/main.cpp.o: CMakeFiles/codeForces_590B.dir/flags.make
CMakeFiles/codeForces_590B.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/codeForces_590B.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/codeForces_590B.dir/main.cpp.o -c /home/lzx/CLionProjects/Context/codeForces_590B/main.cpp

CMakeFiles/codeForces_590B.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/codeForces_590B.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzx/CLionProjects/Context/codeForces_590B/main.cpp > CMakeFiles/codeForces_590B.dir/main.cpp.i

CMakeFiles/codeForces_590B.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/codeForces_590B.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzx/CLionProjects/Context/codeForces_590B/main.cpp -o CMakeFiles/codeForces_590B.dir/main.cpp.s

# Object files for target codeForces_590B
codeForces_590B_OBJECTS = \
"CMakeFiles/codeForces_590B.dir/main.cpp.o"

# External object files for target codeForces_590B
codeForces_590B_EXTERNAL_OBJECTS =

codeForces_590B: CMakeFiles/codeForces_590B.dir/main.cpp.o
codeForces_590B: CMakeFiles/codeForces_590B.dir/build.make
codeForces_590B: CMakeFiles/codeForces_590B.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable codeForces_590B"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/codeForces_590B.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/codeForces_590B.dir/build: codeForces_590B

.PHONY : CMakeFiles/codeForces_590B.dir/build

CMakeFiles/codeForces_590B.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/codeForces_590B.dir/cmake_clean.cmake
.PHONY : CMakeFiles/codeForces_590B.dir/clean

CMakeFiles/codeForces_590B.dir/depend:
	cd /home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzx/CLionProjects/Context/codeForces_590B /home/lzx/CLionProjects/Context/codeForces_590B /home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug /home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug /home/lzx/CLionProjects/Context/codeForces_590B/cmake-build-debug/CMakeFiles/codeForces_590B.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/codeForces_590B.dir/depend

