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

# Utility rule file for pch_Generate_opencv_imgcodecs.

# Include the progress variables for this target.
include modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/progress.make

modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs: modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch


modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch: modules/imgcodecs/src/precomp.hpp
modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch: modules/imgcodecs/precomp.hpp
modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch: lib/libopencv_imgcodecs_pch_dephelp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating precomp.hpp.gch/opencv_imgcodecs_Release.gch"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs && /usr/bin/cmake -E make_directory /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/precomp.hpp.gch
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG -fPIC "-D__OPENCV_BUILD=1" "-DHAVE_WEBP" "-DCVAPI_EXPORTS" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libjasper" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libtiff" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libtiff" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libwebp" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libjpeg" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -isystem"/usr/include" -isystem"/usr/include" -isystem"/usr/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Half" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Iex" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/IlmThread" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Imath" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/IlmImf" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libjasper" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libtiff" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libtiff" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libwebp" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/libjpeg" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -isystem"/usr/include" -isystem"/usr/include" -isystem"/usr/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Half" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Iex" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/IlmThread" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/Imath" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/openexr/IlmImf" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/src" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgproc/include" -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -DCVAPI_EXPORTS -x c++-header -o /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/precomp.hpp

modules/imgcodecs/precomp.hpp: modules/imgcodecs/src/precomp.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating precomp.hpp"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs && /usr/bin/cmake -E copy_if_different /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/src/precomp.hpp /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/precomp.hpp

pch_Generate_opencv_imgcodecs: modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs
pch_Generate_opencv_imgcodecs: modules/imgcodecs/precomp.hpp.gch/opencv_imgcodecs_Release.gch
pch_Generate_opencv_imgcodecs: modules/imgcodecs/precomp.hpp
pch_Generate_opencv_imgcodecs: modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/build.make

.PHONY : pch_Generate_opencv_imgcodecs

# Rule to build all files generated by this target.
modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/build: pch_Generate_opencv_imgcodecs

.PHONY : modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/build

modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/clean:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_imgcodecs.dir/cmake_clean.cmake
.PHONY : modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/clean

modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/depend:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/imgcodecs/CMakeFiles/pch_Generate_opencv_imgcodecs.dir/depend

