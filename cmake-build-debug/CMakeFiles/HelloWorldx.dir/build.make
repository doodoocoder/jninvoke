# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\HelloWorld

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\HelloWorld\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HelloWorldx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HelloWorldx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HelloWorldx.dir/flags.make

CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj: CMakeFiles/HelloWorldx.dir/flags.make
CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj: CMakeFiles/HelloWorldx.dir/includes_CXX.rsp
CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj: ../HelloWorld.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\HelloWorld\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj"
	C:\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HelloWorldx.dir\HelloWorld.cpp.obj -c G:\HelloWorld\HelloWorld.cpp

CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\HelloWorld\HelloWorld.cpp > CMakeFiles\HelloWorldx.dir\HelloWorld.cpp.i

CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\HelloWorld\HelloWorld.cpp -o CMakeFiles\HelloWorldx.dir\HelloWorld.cpp.s

# Object files for target HelloWorldx
HelloWorldx_OBJECTS = \
"CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj"

# External object files for target HelloWorldx
HelloWorldx_EXTERNAL_OBJECTS =

HelloWorldx.exe: CMakeFiles/HelloWorldx.dir/HelloWorld.cpp.obj
HelloWorldx.exe: CMakeFiles/HelloWorldx.dir/build.make
HelloWorldx.exe: CMakeFiles/HelloWorldx.dir/linklibs.rsp
HelloWorldx.exe: CMakeFiles/HelloWorldx.dir/objects1.rsp
HelloWorldx.exe: CMakeFiles/HelloWorldx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\HelloWorld\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWorldx.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HelloWorldx.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HelloWorldx.dir/build: HelloWorldx.exe

.PHONY : CMakeFiles/HelloWorldx.dir/build

CMakeFiles/HelloWorldx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HelloWorldx.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HelloWorldx.dir/clean

CMakeFiles/HelloWorldx.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\HelloWorld G:\HelloWorld G:\HelloWorld\cmake-build-debug G:\HelloWorld\cmake-build-debug G:\HelloWorld\cmake-build-debug\CMakeFiles\HelloWorldx.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HelloWorldx.dir/depend
