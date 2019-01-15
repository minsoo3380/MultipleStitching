#include "opencv2/opencv.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "opencv2/nonfree/features2d.hpp"

#include <iostream>

using namespace std;
using namespace cv;

int minHessian;
char *img1;
char *img2;

int _singleMain(int, char*[]);
