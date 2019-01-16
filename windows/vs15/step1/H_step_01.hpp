#include "opencv2/opencv.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int stitching_single(void);
int stitching_good(Mat[], int);
int stitching_multi(Mat [], int);
int MinimumROIStitching(Mat [], int);

void test(void);
