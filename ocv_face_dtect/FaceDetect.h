#pragma once
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class CFaceDetect
{
public:
	CFaceDetect();
	virtual ~CFaceDetect();

	virtual bool Detect(Mat& frame, vector<Rect>& faces) = 0;
};

