# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/patrick/Desktop/CS302/CS-302/Project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/patrick/Desktop/CS302/CS-302/Project2/build

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/Main.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/Main.cpp.o: ../Main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/patrick/Desktop/CS302/CS-302/Project2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/out.dir/Main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/out.dir/Main.cpp.o -c /home/patrick/Desktop/CS302/CS-302/Project2/Main.cpp

CMakeFiles/out.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/Main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/patrick/Desktop/CS302/CS-302/Project2/Main.cpp > CMakeFiles/out.dir/Main.cpp.i

CMakeFiles/out.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/Main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/patrick/Desktop/CS302/CS-302/Project2/Main.cpp -o CMakeFiles/out.dir/Main.cpp.s

CMakeFiles/out.dir/Main.cpp.o.requires:
.PHONY : CMakeFiles/out.dir/Main.cpp.o.requires

CMakeFiles/out.dir/Main.cpp.o.provides: CMakeFiles/out.dir/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/Main.cpp.o.provides.build
.PHONY : CMakeFiles/out.dir/Main.cpp.o.provides

CMakeFiles/out.dir/Main.cpp.o.provides.build: CMakeFiles/out.dir/Main.cpp.o

CMakeFiles/out.dir/Product.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/Product.cpp.o: ../Product.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/patrick/Desktop/CS302/CS-302/Project2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/out.dir/Product.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/out.dir/Product.cpp.o -c /home/patrick/Desktop/CS302/CS-302/Project2/Product.cpp

CMakeFiles/out.dir/Product.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/Product.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/patrick/Desktop/CS302/CS-302/Project2/Product.cpp > CMakeFiles/out.dir/Product.cpp.i

CMakeFiles/out.dir/Product.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/Product.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/patrick/Desktop/CS302/CS-302/Project2/Product.cpp -o CMakeFiles/out.dir/Product.cpp.s

CMakeFiles/out.dir/Product.cpp.o.requires:
.PHONY : CMakeFiles/out.dir/Product.cpp.o.requires

CMakeFiles/out.dir/Product.cpp.o.provides: CMakeFiles/out.dir/Product.cpp.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/Product.cpp.o.provides.build
.PHONY : CMakeFiles/out.dir/Product.cpp.o.provides

CMakeFiles/out.dir/Product.cpp.o.provides.build: CMakeFiles/out.dir/Product.cpp.o

CMakeFiles/out.dir/Inventory.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/Inventory.cpp.o: ../Inventory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/patrick/Desktop/CS302/CS-302/Project2/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/out.dir/Inventory.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/out.dir/Inventory.cpp.o -c /home/patrick/Desktop/CS302/CS-302/Project2/Inventory.cpp

CMakeFiles/out.dir/Inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/Inventory.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/patrick/Desktop/CS302/CS-302/Project2/Inventory.cpp > CMakeFiles/out.dir/Inventory.cpp.i

CMakeFiles/out.dir/Inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/Inventory.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/patrick/Desktop/CS302/CS-302/Project2/Inventory.cpp -o CMakeFiles/out.dir/Inventory.cpp.s

CMakeFiles/out.dir/Inventory.cpp.o.requires:
.PHONY : CMakeFiles/out.dir/Inventory.cpp.o.requires

CMakeFiles/out.dir/Inventory.cpp.o.provides: CMakeFiles/out.dir/Inventory.cpp.o.requires
	$(MAKE) -f CMakeFiles/out.dir/build.make CMakeFiles/out.dir/Inventory.cpp.o.provides.build
.PHONY : CMakeFiles/out.dir/Inventory.cpp.o.provides

CMakeFiles/out.dir/Inventory.cpp.o.provides.build: CMakeFiles/out.dir/Inventory.cpp.o

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/Main.cpp.o" \
"CMakeFiles/out.dir/Product.cpp.o" \
"CMakeFiles/out.dir/Inventory.cpp.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

../bin/out: CMakeFiles/out.dir/Main.cpp.o
../bin/out: CMakeFiles/out.dir/Product.cpp.o
../bin/out: CMakeFiles/out.dir/Inventory.cpp.o
../bin/out: CMakeFiles/out.dir/build.make
../bin/out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: ../bin/out
.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/requires: CMakeFiles/out.dir/Main.cpp.o.requires
CMakeFiles/out.dir/requires: CMakeFiles/out.dir/Product.cpp.o.requires
CMakeFiles/out.dir/requires: CMakeFiles/out.dir/Inventory.cpp.o.requires
.PHONY : CMakeFiles/out.dir/requires

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	cd /home/patrick/Desktop/CS302/CS-302/Project2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/patrick/Desktop/CS302/CS-302/Project2 /home/patrick/Desktop/CS302/CS-302/Project2 /home/patrick/Desktop/CS302/CS-302/Project2/build /home/patrick/Desktop/CS302/CS-302/Project2/build /home/patrick/Desktop/CS302/CS-302/Project2/build/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend
