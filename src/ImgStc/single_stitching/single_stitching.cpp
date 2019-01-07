#include "H_single_stc.hpp"

int stitching_main(void) {
	Mat				matLeftImage;
	Mat				matRightImage;
	Mat				matHalfLeftImage;
	Mat				matHalfRightImage;
	Mat				matGrayLImage;
	Mat				matGrayRImage;

	FILE			*fp1, *fp2;

	//이미지 불러옴
	matLeftImage = imread("..\\images\\bryce_left_02.png", IMREAD_COLOR);
	matRightImage = imread("..\\images\\bryce_right_02.png", IMREAD_COLOR);

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

	//크기 변경
	Size			size(matLeftImage.cols / 2, matLeftImage.rows / 2);
	resize(matLeftImage, matHalfLeftImage, size);
	resize(matRightImage, matHalfRightImage, size);
	imshow("Half Image_L", matHalfLeftImage);
	imshow("Half Image_R", matHalfRightImage);
	waitKey();

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

	//필터링을 하지 않고 매칭결과 표시
	Mat				matNotFilter12, matNotFilter21;

	drawMatches(matGrayLImage, LeftKeyPoint, matGrayRImage, RightKeyPoint, matches12, matNotFilter12, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	drawMatches(matGrayRImage, RightKeyPoint, matGrayLImage, LeftKeyPoint, matches21, matNotFilter21, Scalar::all(-1), Scalar::all(0), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("matches not filter_12", matNotFilter12);
	waitKey();
	imshow("matches not filter_21", matNotFilter21);
	waitKey();

	//cross-checking을 이용한 방법
	vector<DMatch> good_matches;

	for (size_t i = 0; i < matches12.size(); i++) {
		DMatch forward = matches12[i];
		DMatch backward = matches21[forward.trainIdx];

		if (backward.trainIdx == forward.queryIdx) {
			good_matches.push_back(forward);
		}
	}

	fp1 = fopen("good matches - keypoint.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches[i].distance, good_matches[i].queryIdx, good_matches[i].trainIdx);
	}
	fclose(fp1);

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

	fp1 = fopen("good matches - keypoint use distance.txt", "w");

	fprintf(fp1, "%10s%10s%10s | \n", "distance", "queryIdx", "trainIdx");
	for (size_t i = 0; i < good_matches_dist.size(); i++) {
		fprintf(fp1, "%10.2f%10d%10d\n", good_matches_dist[i].distance, good_matches_dist[i].queryIdx, good_matches_dist[i].trainIdx);
	}
	fclose(fp1);

	//good match 결과 표시
	Mat				matGoodMatchDist;

	drawMatches(matGrayLImage, LeftKeyPoint, matGrayRImage, RightKeyPoint, good_matches_dist, matGoodMatchDist, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Good Match Distance", matGoodMatchDist);
	waitKey();

	//이미지 결합을 위한 기하학적 변형 <호모그래피 사용>
	vector<Point2f> ptLeft, ptRight;

	for (int i = 0; i < good_matches_dist.size(); i++) {
		ptLeft.push_back(LeftKeyPoint[good_matches_dist[i].queryIdx].pt);
		ptRight.push_back(RightKeyPoint[good_matches_dist[i].trainIdx].pt);
	}

	Mat				HomoMatrix;
	HomoMatrix = findHomography(ptRight, ptLeft, CV_RANSAC);

	cout << HomoMatrix << endl;

	//homography 행렬을 하용해 warp
	Mat				matResult;
	warpPerspective(matHalfRightImage, matResult, HomoMatrix, Size(matHalfRightImage.cols * 2, matHalfRightImage.rows), INTER_CUBIC);

	Mat				matResultClone;
	matResultClone = matResult.clone();

	imshow("Homography right image", matResultClone);
	waitKey();

	Mat				matROI(matResultClone, Rect(0, 0, matHalfLeftImage.cols, matHalfLeftImage.rows));
	imshow("mat ROI", matROI);
	waitKey();

	matHalfLeftImage.copyTo(matROI);
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