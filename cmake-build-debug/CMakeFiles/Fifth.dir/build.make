# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fifth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Fifth.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Fifth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fifth.dir/flags.make

CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj: CMakeFiles/Fifth.dir/flags.make
CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj: ../fifth/ex3_dynamicVector.cpp
CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj: CMakeFiles/Fifth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj -MF CMakeFiles\Fifth.dir\fifth\ex3_dynamicVector.cpp.obj.d -o CMakeFiles\Fifth.dir\fifth\ex3_dynamicVector.cpp.obj -c C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\fifth\ex3_dynamicVector.cpp

CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\fifth\ex3_dynamicVector.cpp > CMakeFiles\Fifth.dir\fifth\ex3_dynamicVector.cpp.i

CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\fifth\ex3_dynamicVector.cpp -o CMakeFiles\Fifth.dir\fifth\ex3_dynamicVector.cpp.s

# Object files for target Fifth
Fifth_OBJECTS = \
"CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj"

# External object files for target Fifth
Fifth_EXTERNAL_OBJECTS =

Fifth.exe: CMakeFiles/Fifth.dir/fifth/ex3_dynamicVector.cpp.obj
Fifth.exe: CMakeFiles/Fifth.dir/build.make
Fifth.exe: CMakeFiles/Fifth.dir/linklibs.rsp
Fifth.exe: CMakeFiles/Fifth.dir/objects1.rsp
Fifth.exe: CMakeFiles/Fifth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Fifth.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fifth.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fifth.dir/build: Fifth.exe
.PHONY : CMakeFiles/Fifth.dir/build

CMakeFiles/Fifth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fifth.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fifth.dir/clean

CMakeFiles/Fifth.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-debug\CMakeFiles\Fifth.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fifth.dir/depend
