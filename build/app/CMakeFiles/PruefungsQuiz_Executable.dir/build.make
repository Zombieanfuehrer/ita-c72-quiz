# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build

# Include any dependencies generated for this target.
include app/CMakeFiles/PruefungsQuiz_Executable.dir/depend.make

# Include the progress variables for this target.
include app/CMakeFiles/PruefungsQuiz_Executable.dir/progress.make

# Include the compile flags for this target's objects.
include app/CMakeFiles/PruefungsQuiz_Executable.dir/flags.make

app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj: app/CMakeFiles/PruefungsQuiz_Executable.dir/flags.make
app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj: app/CMakeFiles/PruefungsQuiz_Executable.dir/includes_C.rsp
app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj: ../app/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj"
	cd /d C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app && C:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\PruefungsQuiz_Executable.dir\main.c.obj -c C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\app\main.c

app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PruefungsQuiz_Executable.dir/main.c.i"
	cd /d C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app && C:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\app\main.c > CMakeFiles\PruefungsQuiz_Executable.dir\main.c.i

app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PruefungsQuiz_Executable.dir/main.c.s"
	cd /d C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app && C:\Qt\Tools\mingw810_64\bin\x86_64-w64-mingw32-gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\app\main.c -o CMakeFiles\PruefungsQuiz_Executable.dir\main.c.s

# Object files for target PruefungsQuiz_Executable
PruefungsQuiz_Executable_OBJECTS = \
"CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj"

# External object files for target PruefungsQuiz_Executable
PruefungsQuiz_Executable_EXTERNAL_OBJECTS = \
"C:/Projekte/Cpp/dev/techniker-pruefung-quiz-2021/build/src/CMakeFiles/Hauptmenu.dir/menue.c.obj" \
"C:/Projekte/Cpp/dev/techniker-pruefung-quiz-2021/build/src/CMakeFiles/Quiz_Fragen_Gen.dir/generator.c.obj"

app/PruefungsQuiz_Executable.exe: app/CMakeFiles/PruefungsQuiz_Executable.dir/main.c.obj
app/PruefungsQuiz_Executable.exe: src/CMakeFiles/Hauptmenu.dir/menue.c.obj
app/PruefungsQuiz_Executable.exe: src/CMakeFiles/Quiz_Fragen_Gen.dir/generator.c.obj
app/PruefungsQuiz_Executable.exe: app/CMakeFiles/PruefungsQuiz_Executable.dir/build.make
app/PruefungsQuiz_Executable.exe: app/CMakeFiles/PruefungsQuiz_Executable.dir/linklibs.rsp
app/PruefungsQuiz_Executable.exe: app/CMakeFiles/PruefungsQuiz_Executable.dir/objects1.rsp
app/PruefungsQuiz_Executable.exe: app/CMakeFiles/PruefungsQuiz_Executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PruefungsQuiz_Executable.exe"
	cd /d C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PruefungsQuiz_Executable.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
app/CMakeFiles/PruefungsQuiz_Executable.dir/build: app/PruefungsQuiz_Executable.exe

.PHONY : app/CMakeFiles/PruefungsQuiz_Executable.dir/build

app/CMakeFiles/PruefungsQuiz_Executable.dir/clean:
	cd /d C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app && $(CMAKE_COMMAND) -P CMakeFiles\PruefungsQuiz_Executable.dir\cmake_clean.cmake
.PHONY : app/CMakeFiles/PruefungsQuiz_Executable.dir/clean

app/CMakeFiles/PruefungsQuiz_Executable.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021 C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\app C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app C:\Projekte\Cpp\dev\techniker-pruefung-quiz-2021\build\app\CMakeFiles\PruefungsQuiz_Executable.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : app/CMakeFiles/PruefungsQuiz_Executable.dir/depend

