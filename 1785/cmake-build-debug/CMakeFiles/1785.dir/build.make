# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /home/lzx/CLionProjects/Context/1785

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lzx/CLionProjects/Context/1785/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1785.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1785.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1785.dir/flags.make

CMakeFiles/1785.dir/main.cpp.o: CMakeFiles/1785.dir/flags.make
CMakeFiles/1785.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lzx/CLionProjects/Context/1785/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1785.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1785.dir/main.cpp.o -c /home/lzx/CLionProjects/Context/1785/main.cpp

CMakeFiles/1785.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1785.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lzx/CLionProjects/Context/1785/main.cpp > CMakeFiles/1785.dir/main.cpp.i

CMakeFiles/1785.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1785.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lzx/CLionProjects/Context/1785/main.cpp -o CMakeFiles/1785.dir/main.cpp.s

# Object files for target 1785
1785_OBJECTS = \
"CMakeFiles/1785.dir/main.cpp.o"

# External object files for target 1785
1785_EXTERNAL_OBJECTS =

1785: CMakeFiles/1785.dir/main.cpp.o
1785: CMakeFiles/1785.dir/build.make
1785: CMakeFiles/1785.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lzx/CLionProjects/Context/1785/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1785"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1785.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1785.dir/build: 1785

.PHONY : CMakeFiles/1785.dir/build

CMakeFiles/1785.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1785.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1785.dir/clean

CMakeFiles/1785.dir/depend:
	cd /home/lzx/CLionProjects/Context/1785/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lzx/CLionProjects/Context/1785 /home/lzx/CLionProjects/Context/1785 /home/lzx/CLionProjects/Context/1785/cmake-build-debug /home/lzx/CLionProjects/Context/1785/cmake-build-debug /home/lzx/CLionProjects/Context/1785/cmake-build-debug/CMakeFiles/1785.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1785.dir/depend

