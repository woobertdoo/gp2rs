# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/jamieharris/gp-2-rsxml

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jamieharris/gp-2-rsxml

# Include any dependencies generated for this target.
include CMakeFiles/GP2RSXML.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GP2RSXML.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GP2RSXML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GP2RSXML.dir/flags.make

CMakeFiles/GP2RSXML.dir/codegen:
.PHONY : CMakeFiles/GP2RSXML.dir/codegen

CMakeFiles/GP2RSXML.dir/main.cpp.o: CMakeFiles/GP2RSXML.dir/flags.make
CMakeFiles/GP2RSXML.dir/main.cpp.o: main.cpp
CMakeFiles/GP2RSXML.dir/main.cpp.o: CMakeFiles/GP2RSXML.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jamieharris/gp-2-rsxml/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GP2RSXML.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GP2RSXML.dir/main.cpp.o -MF CMakeFiles/GP2RSXML.dir/main.cpp.o.d -o CMakeFiles/GP2RSXML.dir/main.cpp.o -c /home/jamieharris/gp-2-rsxml/main.cpp

CMakeFiles/GP2RSXML.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/GP2RSXML.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jamieharris/gp-2-rsxml/main.cpp > CMakeFiles/GP2RSXML.dir/main.cpp.i

CMakeFiles/GP2RSXML.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/GP2RSXML.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jamieharris/gp-2-rsxml/main.cpp -o CMakeFiles/GP2RSXML.dir/main.cpp.s

# Object files for target GP2RSXML
GP2RSXML_OBJECTS = \
"CMakeFiles/GP2RSXML.dir/main.cpp.o"

# External object files for target GP2RSXML
GP2RSXML_EXTERNAL_OBJECTS =

GP2RSXML: CMakeFiles/GP2RSXML.dir/main.cpp.o
GP2RSXML: CMakeFiles/GP2RSXML.dir/build.make
GP2RSXML: CMakeFiles/GP2RSXML.dir/compiler_depend.ts
GP2RSXML: src/libgp2rs.a
GP2RSXML: CMakeFiles/GP2RSXML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jamieharris/gp-2-rsxml/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GP2RSXML"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GP2RSXML.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GP2RSXML.dir/build: GP2RSXML
.PHONY : CMakeFiles/GP2RSXML.dir/build

CMakeFiles/GP2RSXML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GP2RSXML.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GP2RSXML.dir/clean

CMakeFiles/GP2RSXML.dir/depend:
	cd /home/jamieharris/gp-2-rsxml && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jamieharris/gp-2-rsxml /home/jamieharris/gp-2-rsxml /home/jamieharris/gp-2-rsxml /home/jamieharris/gp-2-rsxml /home/jamieharris/gp-2-rsxml/CMakeFiles/GP2RSXML.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/GP2RSXML.dir/depend

