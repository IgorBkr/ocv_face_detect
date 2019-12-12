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

	bool detectAndDisplay();

protected:
	bool LoadCascades();
	bool detectAndDisplay(Mat& frame);

protected:
	// TODO: can I make a vector of classifiers and expose method: add_classifier?
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	String win_name;
};

