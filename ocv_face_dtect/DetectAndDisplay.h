#pragma once
#include <opencv2/opencv.hpp>
#include <string>
using namespace std;
using namespace cv;

class CDetectAndDisplay
{
public:
	CDetectAndDisplay();
	virtual ~CDetectAndDisplay();

	bool detectAndDisplay(bool detct_eyes = true);

protected:
	bool LoadCascades(bool detect_eyes);
	bool detectAndDisplay(Mat& frame, bool detct_eyes);

protected:
	// TODO: can I make a vector of classifiers and expose method: add_classifier?
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	String win_name;
};

