# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\User\Desktop\FEUP\AED\TP 3_4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug"

# Include any dependencies generated for this target.
include lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/progress.make

# Include the compile flags for this target's objects.
include lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/flags.make

lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/flags.make
lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/includes_CXX.rsp
lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj: C:/Users/User/Desktop/FEUP/AED/TP\ 3_4/lib/benchmark/test/report_aggregates_only_test.cc
lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj"
	cd /d C:\Users\User\Desktop\FEUP\AED\TP3_4~1\CMAKE-~1\lib\BENCHM~1\test && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj -MF CMakeFiles\report_aggregates_only_test.dir\report_aggregates_only_test.cc.obj.d -o CMakeFiles\report_aggregates_only_test.dir\report_aggregates_only_test.cc.obj -c "C:\Users\User\Desktop\FEUP\AED\TP 3_4\lib\benchmark\test\report_aggregates_only_test.cc"

lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.i"
	cd /d C:\Users\User\Desktop\FEUP\AED\TP3_4~1\CMAKE-~1\lib\BENCHM~1\test && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\User\Desktop\FEUP\AED\TP 3_4\lib\benchmark\test\report_aggregates_only_test.cc" > CMakeFiles\report_aggregates_only_test.dir\report_aggregates_only_test.cc.i

lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.s"
	cd /d C:\Users\User\Desktop\FEUP\AED\TP3_4~1\CMAKE-~1\lib\BENCHM~1\test && C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\User\Desktop\FEUP\AED\TP 3_4\lib\benchmark\test\report_aggregates_only_test.cc" -o CMakeFiles\report_aggregates_only_test.dir\report_aggregates_only_test.cc.s

# Object files for target report_aggregates_only_test
report_aggregates_only_test_OBJECTS = \
"CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj"

# External object files for target report_aggregates_only_test
report_aggregates_only_test_EXTERNAL_OBJECTS =

lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/report_aggregates_only_test.cc.obj
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/build.make
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/liboutput_test_helper.a
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/src/libbenchmark_main.a
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/src/libbenchmark.a
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/linkLibs.rsp
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/objects1.rsp
lib/benchmark/test/report_aggregates_only_test.exe: lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable report_aggregates_only_test.exe"
	cd /d C:\Users\User\Desktop\FEUP\AED\TP3_4~1\CMAKE-~1\lib\BENCHM~1\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\report_aggregates_only_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/build: lib/benchmark/test/report_aggregates_only_test.exe
.PHONY : lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/build

lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/clean:
	cd /d C:\Users\User\Desktop\FEUP\AED\TP3_4~1\CMAKE-~1\lib\BENCHM~1\test && $(CMAKE_COMMAND) -P CMakeFiles\report_aggregates_only_test.dir\cmake_clean.cmake
.PHONY : lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/clean

lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\User\Desktop\FEUP\AED\TP 3_4" "C:\Users\User\Desktop\FEUP\AED\TP 3_4\lib\benchmark\test" "C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug" "C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug\lib\benchmark\test" "C:\Users\User\Desktop\FEUP\AED\TP 3_4\cmake-build-debug\lib\benchmark\test\CMakeFiles\report_aggregates_only_test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/benchmark/test/CMakeFiles/report_aggregates_only_test.dir/depend

