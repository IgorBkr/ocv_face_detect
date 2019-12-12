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

	if (!detect.detectAndDisplay(false))
	{
		cout << "ERROR! detectAndDisplay() failed!\n";
		getchar();
		return -1;
	}

	//getchar();
	return 0;
}