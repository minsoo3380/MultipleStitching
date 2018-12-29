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

# Utility rule file for pch_Generate_opencv_core.

# Include the progress variables for this target.
include modules/core/CMakeFiles/pch_Generate_opencv_core.dir/progress.make

modules/core/CMakeFiles/pch_Generate_opencv_core: modules/core/precomp.hpp.gch/opencv_core_Release.gch


modules/core/precomp.hpp.gch/opencv_core_Release.gch: modules/core/src/precomp.hpp
modules/core/precomp.hpp.gch/opencv_core_Release.gch: modules/core/precomp.hpp
modules/core/precomp.hpp.gch/opencv_core_Release.gch: lib/libopencv_core_pch_dephelp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating precomp.hpp.gch/opencv_core_Release.gch"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core && /usr/bin/cmake -E make_directory /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/precomp.hpp.gch
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG -fPIC "-D__OPENCV_BUILD=1" "-DCVAPI_EXPORTS" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/include/opencl/1.2" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/include/opencl/1.2" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/src" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/include" -isystem"/usr/include" -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -DCVAPI_EXPORTS -x c++-header -o /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/precomp.hpp.gch/opencv_core_Release.gch /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/precomp.hpp

modules/core/precomp.hpp: modules/core/src/precomp.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating precomp.hpp"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core && /usr/bin/cmake -E copy_if_different /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/src/precomp.hpp /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/precomp.hpp

pch_Generate_opencv_core: modules/core/CMakeFiles/pch_Generate_opencv_core
pch_Generate_opencv_core: modules/core/precomp.hpp.gch/opencv_core_Release.gch
pch_Generate_opencv_core: modules/core/precomp.hpp
pch_Generate_opencv_core: modules/core/CMakeFiles/pch_Generate_opencv_core.dir/build.make

.PHONY : pch_Generate_opencv_core

# Rule to build all files generated by this target.
modules/core/CMakeFiles/pch_Generate_opencv_core.dir/build: pch_Generate_opencv_core

.PHONY : modules/core/CMakeFiles/pch_Generate_opencv_core.dir/build

modules/core/CMakeFiles/pch_Generate_opencv_core.dir/clean:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_core.dir/cmake_clean.cmake
.PHONY : modules/core/CMakeFiles/pch_Generate_opencv_core.dir/clean

modules/core/CMakeFiles/pch_Generate_opencv_core.dir/depend:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/CMakeFiles/pch_Generate_opencv_core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/core/CMakeFiles/pch_Generate_opencv_core.dir/depend

