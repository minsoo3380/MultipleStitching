# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0

# Include any dependencies generated for this target.
include modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/depend.make

# Include the progress variables for this target.
include modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/progress.make

# Include the compile flags for this target's objects.
include modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/flags.make

modules/flann/opencv_flann_pch_dephelp.cxx: modules/flann/src/precomp.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating opencv_flann_pch_dephelp.cxx"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo \#include\ \"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/src/precomp.hpp\" > /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo int\ testfunction\(\)\; >> /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo int\ testfunction\(\) >> /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo { >> /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo \ \ \ \ \return\ 0\; >> /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/cmake -E echo } >> /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/flags.make
modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o: modules/flann/opencv_flann_pch_dephelp.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o -c /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.i"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx > CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.i

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.s"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/opencv_flann_pch_dephelp.cxx -o CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.s

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.requires:

.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.requires

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.provides: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.requires
	$(MAKE) -f modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/build.make modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.provides.build
.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.provides

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.provides.build: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o


# Object files for target opencv_flann_pch_dephelp
opencv_flann_pch_dephelp_OBJECTS = \
"CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o"

# External object files for target opencv_flann_pch_dephelp
opencv_flann_pch_dephelp_EXTERNAL_OBJECTS =

lib/libopencv_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o
lib/libopencv_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/build.make
lib/libopencv_flann_pch_dephelp.a: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../lib/libopencv_flann_pch_dephelp.a"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && $(CMAKE_COMMAND) -P CMakeFiles/opencv_flann_pch_dephelp.dir/cmake_clean_target.cmake
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_flann_pch_dephelp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/build: lib/libopencv_flann_pch_dephelp.a

.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/build

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/requires: modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/opencv_flann_pch_dephelp.cxx.o.requires

.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/requires

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/clean:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann && $(CMAKE_COMMAND) -P CMakeFiles/opencv_flann_pch_dephelp.dir/cmake_clean.cmake
.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/clean

modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/depend: modules/flann/opencv_flann_pch_dephelp.cxx
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/flann/CMakeFiles/opencv_flann_pch_dephelp.dir/depend

