# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeremie/OpenGL/projet1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeremie/OpenGL/projet1/build

# Include any dependencies generated for this target.
include CMakeFiles/interpollation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/interpollation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpollation.dir/flags.make

CMakeFiles/interpollation.dir/src/Main.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/interpollation.dir/src/Main.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/Main.cpp.o -c /home/jeremie/OpenGL/projet1/src/Main.cpp

CMakeFiles/interpollation.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/Main.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/Main.cpp > CMakeFiles/interpollation.dir/src/Main.cpp.i

CMakeFiles/interpollation.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/Main.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/Main.cpp -o CMakeFiles/interpollation.dir/src/Main.cpp.s

CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o: ../src/graphic/SDLWindowManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o -c /home/jeremie/OpenGL/projet1/src/graphic/SDLWindowManager.cpp

CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/graphic/SDLWindowManager.cpp > CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.i

CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/graphic/SDLWindowManager.cpp -o CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.s

CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o: ../src/graphic/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o -c /home/jeremie/OpenGL/projet1/src/graphic/Shader.cpp

CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/graphic/Shader.cpp > CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.i

CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/graphic/Shader.cpp -o CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.s

CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o: ../src/object/Sphere.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o -c /home/jeremie/OpenGL/projet1/src/object/Sphere.cpp

CMakeFiles/interpollation.dir/src/object/Sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/object/Sphere.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/object/Sphere.cpp > CMakeFiles/interpollation.dir/src/object/Sphere.cpp.i

CMakeFiles/interpollation.dir/src/object/Sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/object/Sphere.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/object/Sphere.cpp -o CMakeFiles/interpollation.dir/src/object/Sphere.cpp.s

CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o: ../src/object/Vertex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o -c /home/jeremie/OpenGL/projet1/src/object/Vertex.cpp

CMakeFiles/interpollation.dir/src/object/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/object/Vertex.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/object/Vertex.cpp > CMakeFiles/interpollation.dir/src/object/Vertex.cpp.i

CMakeFiles/interpollation.dir/src/object/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/object/Vertex.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/object/Vertex.cpp -o CMakeFiles/interpollation.dir/src/object/Vertex.cpp.s

CMakeFiles/interpollation.dir/src/tool/Program.cpp.o: CMakeFiles/interpollation.dir/flags.make
CMakeFiles/interpollation.dir/src/tool/Program.cpp.o: ../src/tool/Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/interpollation.dir/src/tool/Program.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/interpollation.dir/src/tool/Program.cpp.o -c /home/jeremie/OpenGL/projet1/src/tool/Program.cpp

CMakeFiles/interpollation.dir/src/tool/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/interpollation.dir/src/tool/Program.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeremie/OpenGL/projet1/src/tool/Program.cpp > CMakeFiles/interpollation.dir/src/tool/Program.cpp.i

CMakeFiles/interpollation.dir/src/tool/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/interpollation.dir/src/tool/Program.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeremie/OpenGL/projet1/src/tool/Program.cpp -o CMakeFiles/interpollation.dir/src/tool/Program.cpp.s

# Object files for target interpollation
interpollation_OBJECTS = \
"CMakeFiles/interpollation.dir/src/Main.cpp.o" \
"CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o" \
"CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o" \
"CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o" \
"CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o" \
"CMakeFiles/interpollation.dir/src/tool/Program.cpp.o"

# External object files for target interpollation
interpollation_EXTERNAL_OBJECTS =

interpollation: CMakeFiles/interpollation.dir/src/Main.cpp.o
interpollation: CMakeFiles/interpollation.dir/src/graphic/SDLWindowManager.cpp.o
interpollation: CMakeFiles/interpollation.dir/src/graphic/Shader.cpp.o
interpollation: CMakeFiles/interpollation.dir/src/object/Sphere.cpp.o
interpollation: CMakeFiles/interpollation.dir/src/object/Vertex.cpp.o
interpollation: CMakeFiles/interpollation.dir/src/tool/Program.cpp.o
interpollation: CMakeFiles/interpollation.dir/build.make
interpollation: /usr/lib/x86_64-linux-gnu/libSDLmain.a
interpollation: /usr/lib/x86_64-linux-gnu/libSDL.so
interpollation: /usr/lib/x86_64-linux-gnu/libOpenGL.so
interpollation: /usr/lib/x86_64-linux-gnu/libGLX.so
interpollation: /usr/lib/x86_64-linux-gnu/libGLU.so
interpollation: /usr/lib/x86_64-linux-gnu/libGLEW.so
interpollation: CMakeFiles/interpollation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeremie/OpenGL/projet1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable interpollation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/interpollation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpollation.dir/build: interpollation

.PHONY : CMakeFiles/interpollation.dir/build

CMakeFiles/interpollation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/interpollation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/interpollation.dir/clean

CMakeFiles/interpollation.dir/depend:
	cd /home/jeremie/OpenGL/projet1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeremie/OpenGL/projet1 /home/jeremie/OpenGL/projet1 /home/jeremie/OpenGL/projet1/build /home/jeremie/OpenGL/projet1/build /home/jeremie/OpenGL/projet1/build/CMakeFiles/interpollation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/interpollation.dir/depend
