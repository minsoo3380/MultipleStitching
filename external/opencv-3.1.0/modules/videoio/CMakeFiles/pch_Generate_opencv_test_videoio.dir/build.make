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

# Utility rule file for pch_Generate_opencv_test_videoio.

# Include the progress variables for this target.
include modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/progress.make

modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio: modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch


modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch: modules/videoio/test/test_precomp.hpp
modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch: modules/videoio/test_precomp.hpp
modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch: lib/libopencv_test_videoio_pch_dephelp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating test_precomp.hpp.gch/opencv_test_videoio_Release.gch"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio && /usr/bin/cmake -E make_directory /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test_precomp.hpp.gch
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio && /usr/bin/c++ -O3 -DNDEBUG -DNDEBUG "-D__OPENCV_BUILD=1" "-DVIDEOIO_EXPORTS" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -isystem"/usr/include/gtk-3.0" -isystem"/usr/include/at-spi2-atk/2.0" -isystem"/usr/include/at-spi-2.0" -isystem"/usr/include/dbus-1.0" -isystem"/usr/lib/x86_64-linux-gnu/dbus-1.0/include" -isystem"/usr/include/gtk-3.0" -isystem"/usr/include/gio-unix-2.0" -isystem"/usr/include/mirclient" -isystem"/usr/include/mircore" -isystem"/usr/include/mircookie" -isystem"/usr/include/cairo" -isystem"/usr/include/pango-1.0" -isystem"/usr/include/harfbuzz" -isystem"/usr/include/pango-1.0" -isystem"/usr/include/atk-1.0" -isystem"/usr/include/cairo" -isystem"/usr/include/pixman-1" -isystem"/usr/include/freetype2" -isystem"/usr/include/libpng12" -isystem"/usr/include/gdk-pixbuf-2.0" -isystem"/usr/include/libpng12" -isystem"/usr/include/glib-2.0" -isystem"/usr/lib/x86_64-linux-gnu/glib-2.0/include" -isystem"/usr/include/glib-2.0" -isystem"/usr/lib/x86_64-linux-gnu/glib-2.0/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/3rdparty/ippicv/unpack/ippicv_lnx/include" -isystem"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0" -isystem"/usr/include/gtk-3.0" -isystem"/usr/include/at-spi2-atk/2.0" -isystem"/usr/include/at-spi-2.0" -isystem"/usr/include/dbus-1.0" -isystem"/usr/lib/x86_64-linux-gnu/dbus-1.0/include" -isystem"/usr/include/gtk-3.0" -isystem"/usr/include/gio-unix-2.0" -isystem"/usr/include/mirclient" -isystem"/usr/include/mircore" -isystem"/usr/include/mircookie" -isystem"/usr/include/cairo" -isystem"/usr/include/pango-1.0" -isystem"/usr/include/harfbuzz" -isystem"/usr/include/pango-1.0" -isystem"/usr/include/atk-1.0" -isystem"/usr/include/cairo" -isystem"/usr/include/pixman-1" -isystem"/usr/include/freetype2" -isystem"/usr/include/libpng12" -isystem"/usr/include/gdk-pixbuf-2.0" -isystem"/usr/include/libpng12" -isystem"/usr/include/glib-2.0" -isystem"/usr/lib/x86_64-linux-gnu/glib-2.0/include" -isystem"/usr/include/glib-2.0" -isystem"/usr/lib/x86_64-linux-gnu/glib-2.0/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/ts/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgproc/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/core/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgproc/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/imgcodecs/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/highgui/include" -I"/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test" -fsigned-char -W -Wall -Werror=return-type -Werror=non-virtual-dtor -Werror=address -Werror=sequence-point -Wformat -Werror=format-security -Wmissing-declarations -Wundef -Winit-self -Wpointer-arith -Wshadow -Wsign-promo -Wno-narrowing -Wno-delete-non-virtual-dtor -fdiagnostics-show-option -Wno-long-long -pthread -fomit-frame-pointer -msse -msse2 -mno-avx -msse3 -mno-ssse3 -mno-sse4.1 -mno-sse4.2 -ffunction-sections -fvisibility=hidden -fvisibility-inlines-hidden -Wno-deprecated-declarations -x c++-header -o /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test_precomp.hpp

modules/videoio/test_precomp.hpp: modules/videoio/test/test_precomp.hpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating test_precomp.hpp"
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio && /usr/bin/cmake -E copy_if_different /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test/test_precomp.hpp /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/test_precomp.hpp

pch_Generate_opencv_test_videoio: modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio
pch_Generate_opencv_test_videoio: modules/videoio/test_precomp.hpp.gch/opencv_test_videoio_Release.gch
pch_Generate_opencv_test_videoio: modules/videoio/test_precomp.hpp
pch_Generate_opencv_test_videoio: modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/build.make

.PHONY : pch_Generate_opencv_test_videoio

# Rule to build all files generated by this target.
modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/build: pch_Generate_opencv_test_videoio

.PHONY : modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/build

modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/clean:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio && $(CMAKE_COMMAND) -P CMakeFiles/pch_Generate_opencv_test_videoio.dir/cmake_clean.cmake
.PHONY : modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/clean

modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/depend:
	cd /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0 /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : modules/videoio/CMakeFiles/pch_Generate_opencv_test_videoio.dir/depend

