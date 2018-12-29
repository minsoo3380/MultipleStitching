#include "cvstc.hpp"

int main(int argc, char *argv[]){
	Mat		leftimage;
	Mat		rightimage;
	Size		size;

	//stitching images load
	leftimage = imread("../images/bryce_left_02.png", IMREAD_COLOR);

	imshow("left", leftimage);
	waitKey();


	return 0;
}
