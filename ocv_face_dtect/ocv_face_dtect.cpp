#ifdef _MSC_VER
#pragma warning(disable:4996) // instead of _CRT_SECURE_NO_WARNINGS, which doesn't work in current version
#endif

#include <iostream>
#include <opencv2/opencv.hpp>
#include "DetectAndDisplay.h"
#include "FaceDetectPlotDisplay.h"
using namespace std;
using namespace cv;

//
int main()
{
	//CDetectAndDisplay detect;
	//cout << "Loaded CDetectAndDisplay object!\n";

	////detect.setPlotShapeFace(CDetectAndDisplay::PLOT_ELLIPSE);
	//detect.setPlotShapeFace(CDetectAndDisplay::PLOT_RECT);
	////detect.setPlotShapeFace(CDetectAndDisplay::PLOT_BLUR);

	//if (!detect.detectAndDisplay(false))
	//{
	//	cout << "ERROR! detectAndDisplay() failed!\n";
	//	getchar();
	//	return -1;
	//}

	CFaceDetectPlotDisplay detect;
	if (!detect.DetectAndDisplayFromCamera())
	{
		cout << "ERROR! DetectAndDisplayFromCamera() failed!\n";
		getchar();
		return -1;
	}

	//getchar();
	return 0;
}