# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\AOC-2021\day8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\AOC-2021\day8\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/day8.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/day8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/day8.dir/flags.make

CMakeFiles/day8.dir/main.cpp.obj: CMakeFiles/day8.dir/flags.make
CMakeFiles/day8.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\AOC-2021\day8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/day8.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\day8.dir\main.cpp.obj -c F:\AOC-2021\day8\main.cpp

CMakeFiles/day8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/day8.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\AOC-2021\day8\main.cpp > CMakeFiles\day8.dir\main.cpp.i

CMakeFiles/day8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/day8.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\AOC-2021\day8\main.cpp -o CMakeFiles\day8.dir\main.cpp.s

# Object files for target day8
day8_OBJECTS = \
"CMakeFiles/day8.dir/main.cpp.obj"

# External object files for target day8
day8_EXTERNAL_OBJECTS =

day8.exe: CMakeFiles/day8.dir/main.cpp.obj
day8.exe: CMakeFiles/day8.dir/build.make
day8.exe: CMakeFiles/day8.dir/linklibs.rsp
day8.exe: CMakeFiles/day8.dir/objects1.rsp
day8.exe: CMakeFiles/day8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\AOC-2021\day8\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable day8.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\day8.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/day8.dir/build: day8.exe
.PHONY : CMakeFiles/day8.dir/build

CMakeFiles/day8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\day8.dir\cmake_clean.cmake
.PHONY : CMakeFiles/day8.dir/clean

CMakeFiles/day8.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\AOC-2021\day8 F:\AOC-2021\day8 F:\AOC-2021\day8\cmake-build-debug F:\AOC-2021\day8\cmake-build-debug F:\AOC-2021\day8\cmake-build-debug\CMakeFiles\day8.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/day8.dir/depend

