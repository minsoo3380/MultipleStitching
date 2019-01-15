#include "H_step_01.hpp"

int main(int argc, char *argv[]) {
	//return code
	int code = 3;
	/*
	//image file name & size
	string img[] = {
		"..\\images\\p986.jpg", "..\\images\\p987.jpg", "..\\images\\p988.jpg", "..\\images\\p989.jpg", 
		"..\\images\\p990.jpg", "..\\images\\p991.jpg", "..\\images\\p992.jpg", "..\\images\\p993.jpg" 
	};
	int size = 8;

	Mat images[8];

	for (int i = 0; i < size; i++) {
		images[i] = imread(img[i], IMREAD_COLOR);
	}
	*/
	//code = stitching_good(images, size);
	//code = stitching_single();
	//code = stitching_multi(images, size);
	//code = stitching_single();
	test();
	return 0;
}
