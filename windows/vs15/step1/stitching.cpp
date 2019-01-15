#include "H_step_01.hpp"

int MinimumROIStitching(Mat images[], int length) {

}

void test(void) {
	Mat		images[3];
	string img[] = {
		"..\\images\\p986.jpg", "..\\images\\p987.jpg", "..\\images\\p988.jpg",
	};

	images[0] = imread(img[0], IMREAD_COLOR);
	images[1] = imread(img[1], IMREAD_COLOR);
	images[2] = imread(img[2], IMREAD_COLOR);
	//imshow("1", images[0]);
	//imshow("2", images[1]);
	//imshow("3", images[2]);

	SurfFeatureDetector	detector(400);
	vector<KeyPoint>	features1, features2, features3;

	detector.detect(images[0], features1);
	detector.detect(images[1], features2);
	detector.detect(images[2], features3);

	SurfDescriptorExtractor	extractor;
	Mat		des[3];
	extractor.compute(images[0], features1, des[0]);
	extractor.compute(images[1], features2, des[1]);
	extractor.compute(images[2], features3, des[2]);

	FlannBasedMatcher	matcher;
	vector<DMatch>		matches12, matches21, matches23, matches32;

	matcher.match(des[1], des[2], matches23);
	matcher.match(des[2], des[1], matches32);

	vector<DMatch>		good_matches;

	cout << "matches" << endl;

	for (int i = 0; i < matches23.size(); i++) {
		DMatch	forward = matches23[i];
		DMatch	backward = matches32[forward.trainIdx];
		if (backward.trainIdx == forward.queryIdx)
			good_matches.push_back(forward);
	}

	vector<Point2f>		ptLeft, ptRight;

	cout << "pt" << endl;
	for (int i = 0; i < good_matches.size(); i++) {
		ptLeft.push_back(features2[good_matches[i].queryIdx].pt);
		ptRight.push_back(features3[good_matches[i].trainIdx].pt);
	}

	cout << "homo" << endl;

	Mat		Homo;
	Homo = findHomography(ptRight, ptLeft, CV_RANSAC);

	Mat		result;
	warpPerspective(images[2], result, Homo, Size(images[1].cols * 2, images[1].rows), INTER_CUBIC);

	Mat		result_clone;
	result_clone = result.clone();

	imshow("11", result_clone);

	Mat ROI(result_clone, Rect(0, 0, images[2].cols, images[2].rows));

	images[1].copyTo(ROI);
	imshow("12", result_clone);
	waitKey();

	good_matches.clear();
	ptLeft.clear();
	ptRight.clear();

	vector<KeyPoint>	features4;
	Mat					des4;
	detector.detect(result_clone, features4);
	extractor.compute(result_clone, features4, des4);

	matcher.match(des[0], des4, matches12);
	matcher.match(des4, des[0], matches21);

	cout << "matches 2" << endl;

	for (int i = 0; i < matches12.size(); i++) {
		DMatch	forward = matches12[i];
		DMatch	backward = matches21[forward.trainIdx];
		if (backward.trainIdx == forward.queryIdx)
			good_matches.push_back(forward);
	}

	cout << "good_matches find 2" << endl;
	
	for (int i = 0; i < good_matches.size(); i++) {
		ptLeft.push_back(features1[good_matches[i].queryIdx].pt);
		ptRight.push_back(features4[good_matches[i].trainIdx].pt);
	}

	cout << "homo" << endl;

	Mat		Homo2;
	Homo2 = findHomography(ptRight, ptLeft, CV_RANSAC);
	 
	cout << "result" << endl;

	Mat		result2;
	warpPerspective(result_clone, result2, Homo2, Size(images[0].cols * 3, images[0].rows), INTER_CUBIC);

	Mat		result2_clone;
	result2_clone = result2.clone();

	Mat		ROI2(result2_clone, Rect(0, 0, images[0].cols, images[0].rows));

	images[0].copyTo(ROI2);
	imshow("4321", result2_clone);
	waitKey();
}


int stitching_good(Mat images[], int size) {
	int minhessian = 400;
	SurfFeatureDetector detector(minhessian);
	vector<KeyPoint>	features[5];

	cout << "key point detect" << endl;

	for (int i = 0; i < size; i++) {
		detector.detect(images[i], features[i]);
	}
	
	cout << "descriptor compute" << endl;

	SurfDescriptorExtractor	extractor;
	Mat	descriptor[5];
	
	for (int i = 0; i < size; i++) {
		extractor.compute(images[i], features[i], descriptor[i]);
	}
	
	cout << "matching" << endl;

	FlannBasedMatcher	matcher;
	vector<DMatch>		matches[5][5];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j)
				continue;
			matcher.match(descriptor[i], descriptor[j], matches[i][j]);
		}
	}

	cout << "cross checking" << endl;

	vector<DMatch> good_matches[5][5];
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matches[i][j].empty())
				continue;
			for (int k = 0; k < matches[i][j].size(); k++) {
				DMatch	forward = matches[i][j][k];
				DMatch	backward = matches[j][i][forward.trainIdx];

				if (backward.trainIdx == forward.queryIdx) {
					good_matches[i][j].push_back(forward);
				}
			}
		}
	}

	cout << "wirte file" << endl;

	FILE *f;
	f = fopen("multi good matching value test", "w");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			fprintf(f, "%d <-> %d : %d\n", i, j, good_matches[i][j].size());
		}
	}

	fclose(f);

	return 0;
}


int stitching_multi(Mat images[], int size) {
	SurfFeatureDetector		detector(400);
	SurfDescriptorExtractor	extractor;
	FlannBasedMatcher		matcher;
	vector<KeyPoint>		featuresL, featuresR;
	vector<DMatch>			matches12, matches21;
	vector<DMatch>			good_matches;
	vector<Point2f>			ptLeft, ptRight;
	Mat						descriptorL, descriptorR;
	Mat						Homo;
	Mat						working, working_gray, bind, bind_gray;
	Mat						result;
	int						rows, cols;
	int						bindcnt = 1;

	cout << "start" << endl;

	working = images[0];
	rows = working.rows;
	cols = working.cols;
	for (int i = 0; i < size - 1; i++, bindcnt++, featuresL.clear(), featuresR.clear(), matches12.clear(), matches21.clear(), good_matches.clear()) {
		cout << "cur bind : " << bindcnt << endl;
		bind = images[bindcnt];

		cout << "convert gray" << endl;
		cvtColor(working, working_gray, CV_RGB2GRAY);
		cvtColor(bind, bind_gray, CV_RGB2GRAY);
		imshow("workingGray", working_gray);
		imshow("bindGray", bind_gray);

		//detecting features
		cout << "detecting features" << endl;
		detector.detect(working_gray, featuresL);
		detector.detect(bind_gray, featuresR);
		
		Mat	kpL, kpR;
		drawKeypoints(working_gray, featuresL, kpL, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
		drawKeypoints(bind_gray, featuresR, kpR, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
		imshow("keypoint L", kpL);
		imshow("keypoint R", kpR);

		//extract descriptor
		cout << "compute descriptor" << endl;
		extractor.compute(working_gray, featuresL, descriptorL);
		extractor.compute(bind_gray, featuresR, descriptorR);

		//left -> right : matches[0], right->left : matches[1]
		cout << "matching" << endl;
		matcher.match(descriptorL, descriptorR, matches12);
		matcher.match(descriptorR, descriptorL, matches21);

		for (size_t j = 0; j < matches12.size(); j++) {
			DMatch forward = matches12[j];
			DMatch backward = matches21[forward.trainIdx];

			if (backward.trainIdx == forward.queryIdx) {
				good_matches.push_back(forward);
			}
		}

		Mat	mcLR;
		drawMatches(working_gray, featuresL, bind_gray, featuresR, good_matches, mcLR, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::DEFAULT);
		imshow("good matching drawing", mcLR);

		cout << "find best matches" << endl;
		for (int j = 0; j < good_matches.size(); j++) {
			ptLeft.push_back(featuresL[good_matches[j].queryIdx].pt);
			ptRight.push_back(featuresR[good_matches[j].trainIdx].pt);
		}

		Homo = findHomography(ptRight, ptLeft, CV_RANSAC);

		Mat		tmp;
		warpPerspective(images[bindcnt], tmp, Homo, Size(cols * 3, rows * 3), INTER_CUBIC);
		imshow("bind images convert Homo", tmp);

		Mat		clone;
		clone = tmp.clone();

		Mat	ROI(clone, Rect(0, 0, working.cols, working.rows));
		imshow("current roi", ROI);

		working.copyTo(ROI);
		imshow("bind working", clone);
		
		vector<Point>	nonBlackList;
		nonBlackList.reserve(tmp.rows * tmp.cols);

		for (int j = 0; j < clone.rows; j++) {
			for (int k = 0; k < clone.cols; k++) {
				if (clone.at<Vec3b>(j, k) != Vec3b(0, 0, 0)) {
					nonBlackList.push_back(Point(k, j));
				}
			}
		}

		cout << "save working image" << endl;

		Rect	rtBound = boundingRect(nonBlackList);
		working = clone(rtBound).clone();
		imshow("nonblack working", working);
		waitKey();
	}

	return 0;
}

int stitching_single(void) {
	Mat				matLeftImage;
	Mat				matRightImage;
	Mat				matHalfLeftImage;
	Mat				matHalfRightImage;
	Mat				matGrayLImage;
	Mat				matGrayRImage;

	//FILE			*fp1, *fp2;


	//이미지 불러옴
	matLeftImage = imread("..\\images\\bryce_left_01.png", IMREAD_COLOR);
	matRightImage = imread("..\\images\\bryce_left_02.png", IMREAD_COLOR);

	/*
	imshow("Original Image_L", matLeftImage);
	imshow("Original Image_R", matRightImage);
	waitKey();

	
	//original image surf를 이용한 키포인트 추출
	vector<KeyPoint> LeftKeyPoint_Color, RightKeyPoint_Color;
	SurfFeatureDetector detector_color(400);
	detector_color.detect(matLeftImage, LeftKeyPoint_Color);
	detector_color.detect(matRightImage, RightKeyPoint_Color);

	fp1 = fopen("Original Image Keypoint_L.txt", "w");
	fp2 = fopen("Original Image Keypoint_R.txt", "w");

	fprintf(fp1, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < LeftKeyPoint_Color.size(); i++) {
		fprintf(fp1, "%10d%10.2f\t%10.2f\n", i, LeftKeyPoint_Color[i].pt.x, LeftKeyPoint_Color[i].pt.y);
	}
	fclose(fp1);

	fprintf(fp2, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < RightKeyPoint_Color.size(); i++) {
		fprintf(fp2, "%10d%10.2f\t%10.2f\n", i, RightKeyPoint_Color[i].pt.x, RightKeyPoint_Color[i].pt.y);
	}
	fclose(fp2);

	Mat				matKeyPointOri_L, matKeyPointOri_R;
	drawKeypoints(matLeftImage, LeftKeyPoint_Color, matKeyPointOri_L, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	drawKeypoints(matRightImage, RightKeyPoint_Color, matKeyPointOri_R, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	imshow("Original KeyPoint_L", matKeyPointOri_L);
	imshow("Original KeyPoint_R", matKeyPointOri_R);
	waitKey();


	//original image surf 기술자 추출
	SurfDescriptorExtractor Extractor_Original;
	Mat				matDesLeft_Ori, matDesRight_Ori;

	Extractor_Original.compute(matLeftImage, LeftKeyPoint_Color, matDesLeft_Ori);
	Extractor_Original.compute(matRightImage, RightKeyPoint_Color, matDesRight_Ori);

	//original matching
	FlannBasedMatcher Matcher_Ori;
	vector<DMatch>	matches12_ori;

	Matcher_Ori.match(matDesLeft_Ori, matDesRight_Ori, matches12_ori);

	fp1 = fopen("discriptor match Original L_R.txt", "w");

	fprintf(fp1, "%10s%10s%10s%10s\n", "distance", "queryIdx", "trainIdx", "imgIdx");

	for (int i = 0; i < matches12_ori.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d%10d\n", matches12_ori[i].distance, matches12_ori[i].queryIdx, matches12_ori[i].trainIdx, matches12_ori[i].imgIdx);
	}
	fclose(fp1);

	//최소 거리 측정
	double dMaxDist_Ori = 0;
	double dMinDist_Ori = 100;
	double dDistance_Ori;

	for (int i = 0; i < matches12_ori.size(); i++) {
		dDistance_Ori = matches12_ori[i].distance;

		if (dDistance_Ori < dMinDist_Ori) {
			dMinDist_Ori = dDistance_Ori;
		}
		if (dDistance_Ori > dMaxDist_Ori) {
			dMaxDist_Ori = dDistance_Ori;
		}
	}

	printf("Max Dist : %f\n", dMaxDist_Ori);
	printf("Min Dist : %f\n", dMinDist_Ori);

	vector<DMatch>	good_matches_Ori;

	for (int i = 0; i < matDesLeft_Ori.rows; i++) {
		if (matches12_ori[i].distance < 3 * dMinDist_Ori) {
			good_matches_Ori.push_back(matches12_ori[i]);
		}
	}

	fp1 = fopen("good matches Original - keypoint.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches_Ori.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches_Ori[i].distance, good_matches_Ori[i].queryIdx, good_matches_Ori[i].trainIdx);
	}
	fclose(fp1);

	Mat				matGoodMatch_Ori;
	drawMatches(matLeftImage, LeftKeyPoint_Color, matRightImage, RightKeyPoint_Color, good_matches_Ori, matGoodMatch_Ori, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Original good match", matGoodMatch_Ori);
	waitKey();

	*/

	//크기 변경
	Size			size(matLeftImage.cols / 2, matLeftImage.rows / 2);
	resize(matLeftImage, matHalfLeftImage, size);
	resize(matRightImage, matHalfRightImage, size);
	

	imshow("Half Image_L", matHalfLeftImage);
	imshow("Half Image_R", matHalfRightImage);
	waitKey();

	/*
	//half image surf를 이용한 키포인트 추출
	vector<KeyPoint> LeftKeyPoint_Color_Half, RightKeyPoint_Color_Half;
	SurfFeatureDetector detector_color_half(400);
	detector_color.detect(matHalfLeftImage, LeftKeyPoint_Color_Half);
	detector_color.detect(matHalfRightImage, RightKeyPoint_Color_Half);

	fp1 = fopen("Half Image Keypoint_L.txt", "w");
	fp2 = fopen("Half Image Keypoint_R.txt", "w");

	fprintf(fp1, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < LeftKeyPoint_Color_Half.size(); i++) {
		fprintf(fp1, "%10d%10.2f\t%10.2f\n", i, LeftKeyPoint_Color_Half[i].pt.x, LeftKeyPoint_Color_Half[i].pt.y);
	}
	fclose(fp1);

	fprintf(fp2, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < RightKeyPoint_Color_Half.size(); i++) {
		fprintf(fp2, "%10d%10.2f\t%10.2f\n", i, RightKeyPoint_Color_Half[i].pt.x, RightKeyPoint_Color_Half[i].pt.y);
	}
	fclose(fp2);

	Mat				matKeyPointHalf_L, matKeyPointHalf_R;
	drawKeypoints(matHalfLeftImage, LeftKeyPoint_Color_Half, matKeyPointHalf_L, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	drawKeypoints(matHalfRightImage, RightKeyPoint_Color_Half, matKeyPointHalf_R, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	imshow("Half KeyPoint_L", matKeyPointHalf_L);
	imshow("Half KeyPoint_R", matKeyPointHalf_R);
	waitKey();

	//기술자 추출
	SurfDescriptorExtractor Extractor_half;
	Mat				matDesLeft_half, matDesRight_half;

	Extractor_half.compute(matHalfLeftImage, LeftKeyPoint_Color_Half, matDesLeft_half);
	Extractor_half.compute(matHalfRightImage, RightKeyPoint_Color_Half, matDesRight_half);

	//half 매칭
	FlannBasedMatcher Matcher_Half;
	vector<DMatch>	matches12_half;

	Matcher_Half.match(matDesLeft_half, matDesRight_half, matches12_half);

	fp1 = fopen("discriptor match Half L_R.txt", "w");

	fprintf(fp1, "%10s%10s%10s%10s\n", "distance", "queryIdx", "trainIdx", "imgIdx");

	for (int i = 0; i < matches12_half.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d%10d\n", matches12_half[i].distance, matches12_half[i].queryIdx, matches12_half[i].trainIdx, matches12_half[i].imgIdx);
	}
	fclose(fp1);

	double dMaxDist_Half = 0;
	double dMinDist_Half = 100;
	double dDistance_Half;

	for (int i = 0; i < matches12_half.size(); i++) {
		dDistance_Half = matches12_half[i].distance;

		if (dDistance_Half < dMinDist_Half) {
			dMinDist_Half = dDistance_Half;
		}
		if (dDistance_Half > dMaxDist_Half) {
			dMaxDist_Half = dDistance_Half;
		}
	}

	printf("Max Dist : %f\n", dMaxDist_Half);
	printf("Min Dist : %f\n", dMinDist_Half);

	Mat				matGoodMatch_Half;
	vector<DMatch>	good_matches_Half;

	for (int i = 0; i < matDesLeft_half.rows; i++) {
		if (matches12_half[i].distance < 3 * dMinDist_Half) {
			good_matches_Half.push_back(matches12_half[i]);
		}
	}

	fp1 = fopen("good matches Half - keypoint.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches_Half.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches_Half[i].distance, good_matches_Half[i].queryIdx, good_matches_Half[i].trainIdx);
	}
	fclose(fp1);

	drawMatches(matHalfLeftImage, LeftKeyPoint_Color_Half, matHalfRightImage, RightKeyPoint_Color_Half, good_matches_Half, matGoodMatch_Half, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Half Good Match", matGoodMatch_Half);
	waitKey();
	*/
	//그레이 스케일 변환
	cvtColor(matHalfLeftImage, matGrayLImage, CV_RGB2GRAY);
	cvtColor(matHalfRightImage, matGrayRImage, CV_RGB2GRAY);

	imshow("Gray image_L", matGrayLImage);
	imshow("Gray image_R", matGrayRImage);
	waitKey();

	//Gray Scale Image SURF 특징점 추출
	int MinHessian = 400;
	SurfFeatureDetector detector(MinHessian);

	vector<KeyPoint> LeftKeyPoint, RightKeyPoint;
	detector.detect(matGrayLImage, LeftKeyPoint);
	detector.detect(matGrayRImage, RightKeyPoint);
	/*
	fp1 = fopen("Gray Image Keypoint_L.txt", "w");
	fp2 = fopen("Gray Image Keypoint_R.txt", "w");

	fprintf(fp1, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < LeftKeyPoint.size(); i++) {
		fprintf(fp1, "%10d%10.2f\t%10.2f\n", i, LeftKeyPoint[i].pt.x, LeftKeyPoint[i].pt.y);
	}
	fclose(fp1);

	fprintf(fp2, "%10s%10s%10s\n", "index", "Pt.x", "Pt.y");
	for (int i = 0; i < RightKeyPoint.size(); i++) {
		fprintf(fp2, "%10d%10.2f\t%10.2f\n", i, RightKeyPoint[i].pt.x, RightKeyPoint[i].pt.y);
	}
	fclose(fp2);
	*/
	//특징점을 이미지에 표시
	Mat				matKeyPointImage_L;
	Mat				matKeyPointImage_R;

	drawKeypoints(matGrayLImage, LeftKeyPoint, matKeyPointImage_L, Scalar::all(-1), DrawMatchesFlags::DEFAULT);
	drawKeypoints(matGrayRImage, RightKeyPoint, matKeyPointImage_R, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	imshow("KeyPoint Image_L", matKeyPointImage_L);
	imshow("KeyPoint Image_R", matKeyPointImage_R);
	waitKey();

	//기술자 추출
	SurfDescriptorExtractor Extractor;
	Mat				matDesLeft, matDesRight;

	Extractor.compute(matGrayLImage, LeftKeyPoint, matDesLeft);
	Extractor.compute(matGrayRImage, RightKeyPoint, matDesRight);

	//기술자 Mat 클래스 내부를 보기 위해 저장
	//FileStorage		file("descriptor.txt", FileStorage::WRITE);
	//file << "matDesLeft" << matDesLeft;

	//기술자를 이용해서 매칭시킴
	FlannBasedMatcher Matcher;
	vector<DMatch>	matches12, matches21;
	Matcher.match(matDesLeft, matDesRight, matches12);
	Matcher.match(matDesRight, matDesLeft, matches21);
	/*
	fp1 = fopen("discriptor match L_R.txt", "w");
	fp2 = fopen("discriptor match R_L.txt", "w");

	fprintf(fp1, "%10s%10s%10s%10s\n", "distance", "queryIdx", "trainIdx", "imgIdx");
	fprintf(fp2, "%10s%10s%10s%10s\n", "distance", "queryIdx", "trainIdx", "imgIdx");

	for (int i = 0; i < matches12.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d%10d\n", matches12[i].distance, matches12[i].queryIdx, matches12[i].trainIdx, matches12[i].imgIdx);
	}
	fclose(fp1);

	for (int i = 0; i < matches21.size(); i++) {
		fprintf(fp2, "%10.2f%10d%10d%10d\n", matches21[i].distance, matches21[i].queryIdx, matches21[i].trainIdx, matches21[i].imgIdx);
	}
	fclose(fp2);
	*/
	//필터링을 하지 않고 매칭결과 표시
	
	Mat				matNotFilter12, matNotFilter21;

	drawMatches(matGrayLImage, LeftKeyPoint, matGrayRImage, RightKeyPoint, matches12, matNotFilter12, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	drawMatches(matGrayRImage, RightKeyPoint, matGrayLImage, LeftKeyPoint, matches21, matNotFilter21, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	//imshow("matches not filter_12", matNotFilter12);
	//waitKey();
	//imshow("matches not filter_21", matNotFilter21);
	//waitKey();

	//cross-checking을 이용한 방법
	vector<DMatch> good_matches;

	for (size_t i = 0; i < matches12.size(); i++) {
		DMatch forward = matches12[i];
		DMatch backward = matches21[forward.trainIdx];

		if (backward.trainIdx == forward.queryIdx) {
			good_matches.push_back(forward);
		}
	}
	
	/*
	fp1 = fopen("good matches - keypoint.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches[i].distance, good_matches[i].queryIdx, good_matches[i].trainIdx);
	}
	fclose(fp1);
	*/
	//good match 매칭결과 표시
	
	Mat				matGoodMatch;

	drawMatches(matGrayLImage, LeftKeyPoint, matGrayRImage, RightKeyPoint, good_matches, matGoodMatch, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Good Match", matGoodMatch);
	waitKey();
	
	//distance를 이용한 방법
	vector<DMatch> good_matches_dist;

	double dMaxDist = 0;
	double dMinDist = 100;
	double dDistance;

	for (int i = 0; i < matDesLeft.rows; i++) {
		dDistance = matches12[i].distance;

		if (dDistance < dMinDist) {
			dMinDist = dDistance;
		}
		if (dDistance > dMaxDist) {
			dMaxDist = dDistance;
		}
	}

	printf("Max Dist : %f\n", dMaxDist);
	printf("Min Dist : %f\n", dMinDist);

	for (int i = 0; i < matDesLeft.rows; i++) {
		if (matches12[i].distance < 3 * dMinDist) {
			good_matches_dist.push_back(matches12[i]);
		}
	}
	/*
	fp1 = fopen("good matches - keypoint use distance.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches_dist.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches_dist[i].distance, good_matches_dist[i].queryIdx, good_matches_dist[i].trainIdx);
	}
	fclose(fp1);
	*/
	//good match 결과 표시
	Mat				matGoodMatchDist;

	drawMatches(matGrayLImage, LeftKeyPoint, matGrayRImage, RightKeyPoint, good_matches_dist, matGoodMatchDist, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Good Match Distance", matGoodMatchDist);
	waitKey();

	//이미지 결합을 위한 기하학적 변형 <호모그래피 사용>
	vector<Point2f> ptLeft, ptRight;
	vector<Point2f> ptLeft_cross, ptRight_cross;

	for (int i = 0; i < good_matches_dist.size(); i++) {
		ptLeft.push_back(LeftKeyPoint[good_matches_dist[i].queryIdx].pt);
		ptRight.push_back(RightKeyPoint[good_matches_dist[i].trainIdx].pt);
	}

	for (int i = 0; i < good_matches.size(); i++) {
		ptLeft_cross.push_back(LeftKeyPoint[good_matches[i].queryIdx].pt);
		ptRight_cross.push_back(RightKeyPoint[good_matches[i].trainIdx].pt);
	}

	Mat				HomoMatrix, HomoMatrix_cross;
	HomoMatrix = findHomography(ptRight, ptLeft, CV_RANSAC);
	HomoMatrix_cross = findHomography(ptRight_cross, ptLeft_cross, CV_RANSAC);

	cout << HomoMatrix << endl;

	//homography 행렬을 하용해 warp
	Mat				matResult, matResult_cross;
	warpPerspective(matHalfRightImage, matResult, HomoMatrix, Size(matHalfRightImage.cols * 2, matHalfRightImage.rows * 2), INTER_CUBIC);
	warpPerspective(matHalfRightImage, matResult_cross, HomoMatrix_cross, Size(matHalfRightImage.cols * 2, matHalfRightImage.rows * 2), INTER_CUBIC);

	imshow("homography right image cross", matResult_cross);

	Mat				matResultClone;
	matResultClone = matResult.clone();

	imshow("Homography right image", matResultClone);
	waitKey();

	Mat				matROI(matResultClone, Rect(0, 0, matHalfLeftImage.cols, matHalfLeftImage.rows));
	Mat				matROI_corss(matResult_cross, Rect(0, 0, matHalfLeftImage.cols, matHalfLeftImage.rows));
	
	imshow("mat ROI", matROI);
	waitKey();

	matHalfLeftImage.copyTo(matROI);
	matHalfLeftImage.copyTo(matROI_corss);
	imshow("ROI cross connect", matResult_cross);
	imshow("left image copy to mat ROI by clone", matResultClone);
	waitKey();

	vector<Point> nonBlackList;
	nonBlackList.reserve(matResult.rows * matResult.cols);

	for (int i = 0; i < matResultClone.rows; i++) {
		for (int j = 0; j < matResultClone.cols; j++) {
			if (matResultClone.at<Vec3b>(i, j) != Vec3b(0, 0, 0)) {
				nonBlackList.push_back(Point(j, i));
			}
		}
	}

	Rect			rtBound = boundingRect(nonBlackList);
	imshow("Result", matResultClone(rtBound));
	waitKey();

	return 0;
}