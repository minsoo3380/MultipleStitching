# CMake generated Testfile for 
# Source directory: /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/stitching
# Build directory: /home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/modules/stitching
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_stitching "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/bin/opencv_test_stitching" "--gtest_output=xml:opencv_test_stitching.xml")
set_tests_properties(opencv_test_stitching PROPERTIES  LABELS "Main;opencv_stitching;Accuracy" WORKING_DIRECTORY "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/test-reports/accuracy")
add_test(opencv_perf_stitching "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/bin/opencv_perf_stitching" "--gtest_output=xml:opencv_perf_stitching.xml")
set_tests_properties(opencv_perf_stitching PROPERTIES  LABELS "Main;opencv_stitching;Performance" WORKING_DIRECTORY "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/test-reports/performance")
add_test(opencv_sanity_stitching "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/bin/opencv_perf_stitching" "--gtest_output=xml:opencv_perf_stitching.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_stitching PROPERTIES  LABELS "Main;opencv_stitching;Sanity" WORKING_DIRECTORY "/home/kms/SWPRO/MultipleStitching/external/opencv-3.1.0/test-reports/sanity")
