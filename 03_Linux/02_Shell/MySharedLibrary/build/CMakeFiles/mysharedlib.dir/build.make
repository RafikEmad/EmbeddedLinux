# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build

# Include any dependencies generated for this target.
include CMakeFiles/mysharedlib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mysharedlib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mysharedlib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mysharedlib.dir/flags.make

CMakeFiles/mysharedlib.dir/calc.cpp.o: CMakeFiles/mysharedlib.dir/flags.make
CMakeFiles/mysharedlib.dir/calc.cpp.o: ../calc.cpp
CMakeFiles/mysharedlib.dir/calc.cpp.o: CMakeFiles/mysharedlib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mysharedlib.dir/calc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mysharedlib.dir/calc.cpp.o -MF CMakeFiles/mysharedlib.dir/calc.cpp.o.d -o CMakeFiles/mysharedlib.dir/calc.cpp.o -c /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/calc.cpp

CMakeFiles/mysharedlib.dir/calc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mysharedlib.dir/calc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/calc.cpp > CMakeFiles/mysharedlib.dir/calc.cpp.i

CMakeFiles/mysharedlib.dir/calc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mysharedlib.dir/calc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/calc.cpp -o CMakeFiles/mysharedlib.dir/calc.cpp.s

# Object files for target mysharedlib
mysharedlib_OBJECTS = \
"CMakeFiles/mysharedlib.dir/calc.cpp.o"

# External object files for target mysharedlib
mysharedlib_EXTERNAL_OBJECTS =

libmysharedlib.so.1.0: CMakeFiles/mysharedlib.dir/calc.cpp.o
libmysharedlib.so.1.0: CMakeFiles/mysharedlib.dir/build.make
libmysharedlib.so.1.0: CMakeFiles/mysharedlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmysharedlib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mysharedlib.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library libmysharedlib.so.1.0 libmysharedlib.so.1 libmysharedlib.so

libmysharedlib.so.1: libmysharedlib.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate libmysharedlib.so.1

libmysharedlib.so: libmysharedlib.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate libmysharedlib.so

# Rule to build all files generated by this target.
CMakeFiles/mysharedlib.dir/build: libmysharedlib.so
.PHONY : CMakeFiles/mysharedlib.dir/build

CMakeFiles/mysharedlib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mysharedlib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mysharedlib.dir/clean

CMakeFiles/mysharedlib.dir/depend:
	cd /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build /home/rafik/Desktop/EmbeddedLinux/03_Linux/02_Shell/MySharedLibrary/build/CMakeFiles/mysharedlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mysharedlib.dir/depend
