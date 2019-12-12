#include <iostream>
#include <opencv2/opencv.hpp>
#include "DetectAndDisplay.h"
using namespace std;
using namespace cv;

//
int main()
{
	CDetectAndDisplay detect;
	cout << "Loaded CDetectAndDisplay object!\n";

	//detect.setPlotShapeFace(CDetectAndDisplay::PLOT_ELLIPSE);
	detect.setPlotShapeFace(CDetectAndDisplay::PLOT_RECT);

	if (!detect.detectAndDisplay(false))
	{
		cout << "ERROR! detectAndDisplay() failed!\n";
		getchar();
		return -1;
	}

	//getchar();
	return 0;
}