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
CMAKE_BINARY_DIR = C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/Sixth.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Sixth.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Sixth.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sixth.dir/flags.make

CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj: CMakeFiles/Sixth.dir/flags.make
CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj: ../6/ex1_variadicFunctions.cpp
CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj: CMakeFiles/Sixth.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj -MF CMakeFiles\Sixth.dir\6\ex1_variadicFunctions.cpp.obj.d -o CMakeFiles\Sixth.dir\6\ex1_variadicFunctions.cpp.obj -c C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\6\ex1_variadicFunctions.cpp

CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\6\ex1_variadicFunctions.cpp > CMakeFiles\Sixth.dir\6\ex1_variadicFunctions.cpp.i

CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\6\ex1_variadicFunctions.cpp -o CMakeFiles\Sixth.dir\6\ex1_variadicFunctions.cpp.s

# Object files for target Sixth
Sixth_OBJECTS = \
"CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj"

# External object files for target Sixth
Sixth_EXTERNAL_OBJECTS =

Sixth.exe: CMakeFiles/Sixth.dir/6/ex1_variadicFunctions.cpp.obj
Sixth.exe: CMakeFiles/Sixth.dir/build.make
Sixth.exe: CMakeFiles/Sixth.dir/linklibs.rsp
Sixth.exe: CMakeFiles/Sixth.dir/objects1.rsp
Sixth.exe: CMakeFiles/Sixth.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sixth.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sixth.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sixth.dir/build: Sixth.exe
.PHONY : CMakeFiles/Sixth.dir/build

CMakeFiles/Sixth.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sixth.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sixth.dir/clean

CMakeFiles/Sixth.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release C:\Users\sch03\Documents\GitHub\EffectiveModernCPPCourse\cmake-build-release\CMakeFiles\Sixth.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sixth.dir/depend

