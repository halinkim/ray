# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\halin\Documents\GitHub\ray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\halin\Documents\GitHub\ray\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ray.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/main.cpp.obj: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/main.cpp.obj: ../main.cpp
CMakeFiles/ray.dir/main.cpp.obj: CMakeFiles/ray.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\halin\Documents\GitHub\ray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ray.dir/main.cpp.obj"
	"C:\PROGRA~1\JETBRA~1\CLion 2022.2.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ray.dir/main.cpp.obj -MF CMakeFiles\ray.dir\main.cpp.obj.d -o CMakeFiles\ray.dir\main.cpp.obj -c C:\Users\halin\Documents\GitHub\ray\main.cpp

CMakeFiles/ray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/main.cpp.i"
	"C:\PROGRA~1\JETBRA~1\CLion 2022.2.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\halin\Documents\GitHub\ray\main.cpp > CMakeFiles\ray.dir\main.cpp.i

CMakeFiles/ray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/main.cpp.s"
	"C:\PROGRA~1\JETBRA~1\CLion 2022.2.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\halin\Documents\GitHub\ray\main.cpp -o CMakeFiles\ray.dir\main.cpp.s

# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/main.cpp.obj"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray.exe: CMakeFiles/ray.dir/main.cpp.obj
ray.exe: CMakeFiles/ray.dir/build.make
ray.exe: CMakeFiles/ray.dir/linklibs.rsp
ray.exe: CMakeFiles/ray.dir/objects1.rsp
ray.exe: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\halin\Documents\GitHub\ray\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ray.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ray.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray.exe
.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ray.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\halin\Documents\GitHub\ray C:\Users\halin\Documents\GitHub\ray C:\Users\halin\Documents\GitHub\ray\cmake-build-debug C:\Users\halin\Documents\GitHub\ray\cmake-build-debug C:\Users\halin\Documents\GitHub\ray\cmake-build-debug\CMakeFiles\ray.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend
