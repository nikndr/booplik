# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OOP_Marhal_04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OOP_Marhal_04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OOP_Marhal_04.dir/flags.make

CMakeFiles/OOP_Marhal_04.dir/main.cpp.o: CMakeFiles/OOP_Marhal_04.dir/flags.make
CMakeFiles/OOP_Marhal_04.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OOP_Marhal_04.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP_Marhal_04.dir/main.cpp.o -c /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/main.cpp

CMakeFiles/OOP_Marhal_04.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP_Marhal_04.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/main.cpp > CMakeFiles/OOP_Marhal_04.dir/main.cpp.i

CMakeFiles/OOP_Marhal_04.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP_Marhal_04.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/main.cpp -o CMakeFiles/OOP_Marhal_04.dir/main.cpp.s

CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.requires

CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.provides: CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OOP_Marhal_04.dir/build.make CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.provides

CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.provides.build: CMakeFiles/OOP_Marhal_04.dir/main.cpp.o


CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o: CMakeFiles/OOP_Marhal_04.dir/flags.make
CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o -c /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Point.cpp

CMakeFiles/OOP_Marhal_04.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP_Marhal_04.dir/Point.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Point.cpp > CMakeFiles/OOP_Marhal_04.dir/Point.cpp.i

CMakeFiles/OOP_Marhal_04.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP_Marhal_04.dir/Point.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Point.cpp -o CMakeFiles/OOP_Marhal_04.dir/Point.cpp.s

CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.requires:

.PHONY : CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.requires

CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.provides: CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/OOP_Marhal_04.dir/build.make CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.provides.build
.PHONY : CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.provides

CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.provides.build: CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o


CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o: CMakeFiles/OOP_Marhal_04.dir/flags.make
CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o: ../Segment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o -c /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Segment.cpp

CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Segment.cpp > CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.i

CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Segment.cpp -o CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.s

CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.requires:

.PHONY : CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.requires

CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.provides: CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.requires
	$(MAKE) -f CMakeFiles/OOP_Marhal_04.dir/build.make CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.provides.build
.PHONY : CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.provides

CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.provides.build: CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o


CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o: CMakeFiles/OOP_Marhal_04.dir/flags.make
CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o: ../Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o -c /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Triangle.cpp

CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Triangle.cpp > CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.i

CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/Triangle.cpp -o CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.s

CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.requires:

.PHONY : CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.requires

CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.provides: CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/OOP_Marhal_04.dir/build.make CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.provides.build
.PHONY : CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.provides

CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.provides.build: CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o


# Object files for target OOP_Marhal_04
OOP_Marhal_04_OBJECTS = \
"CMakeFiles/OOP_Marhal_04.dir/main.cpp.o" \
"CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o" \
"CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o" \
"CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o"

# External object files for target OOP_Marhal_04
OOP_Marhal_04_EXTERNAL_OBJECTS =

OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/main.cpp.o
OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o
OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o
OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o
OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/build.make
OOP_Marhal_04: CMakeFiles/OOP_Marhal_04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable OOP_Marhal_04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OOP_Marhal_04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OOP_Marhal_04.dir/build: OOP_Marhal_04

.PHONY : CMakeFiles/OOP_Marhal_04.dir/build

CMakeFiles/OOP_Marhal_04.dir/requires: CMakeFiles/OOP_Marhal_04.dir/main.cpp.o.requires
CMakeFiles/OOP_Marhal_04.dir/requires: CMakeFiles/OOP_Marhal_04.dir/Point.cpp.o.requires
CMakeFiles/OOP_Marhal_04.dir/requires: CMakeFiles/OOP_Marhal_04.dir/Segment.cpp.o.requires
CMakeFiles/OOP_Marhal_04.dir/requires: CMakeFiles/OOP_Marhal_04.dir/Triangle.cpp.o.requires

.PHONY : CMakeFiles/OOP_Marhal_04.dir/requires

CMakeFiles/OOP_Marhal_04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OOP_Marhal_04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OOP_Marhal_04.dir/clean

CMakeFiles/OOP_Marhal_04.dir/depend:
	cd /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug /Users/nickmarhal/CLionProjects/BOOPLIK/OOP_04_Marhal/cmake-build-debug/CMakeFiles/OOP_Marhal_04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OOP_Marhal_04.dir/depend

