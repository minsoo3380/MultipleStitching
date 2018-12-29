#include "cvstc.hpp"

void readImg(void){
	Mat		leftimage;
	Mat		rightimage;
	Size		size;

	//stitching images load
	leftimage = imread("../images/bryce_left_02.png", IMREAD_COLOR);
	rightimage = imread("../images/bryce_right_02.png", IMREAD_COLOR);

	imshow("left", leftimage);
	imshow("right", rightimage);
	waitKey();

}
