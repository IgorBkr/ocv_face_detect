#include <iostream>
#include <opencv2/opencv.hpp>
#include "DetectAndDisplay.h"
using namespace std;
using namespace cv;

// DEBUG - TEST FUNCTION
//bool display(const String& img_name, int flag = IMREAD_UNCHANGED) // IMREAD_GRAYSCALE is a ueful option
//{
//	Mat img = imread(img_name, flag);
//	if (img.empty())
//	{
//		cout << "Cannot open image " << img_name << endl;
//		system("pause");
//		return false;
//	}
//
//	String win_name = "Image window";
//	namedWindow(win_name);
//	imshow(win_name, img);
//
//	waitKey();
//	destroyWindow(win_name);
//
//	return true;
//}

//
int main()
{
	CDetectAndDisplay detect;
	cout << "Loaded CDetectAndDisplay object!\n";

	if (!detect.detectAndDisplay())
	{
		cout << "ERROR! detectAndDisplay() failed!\n";
		getchar();
		return -1;
	}

	getchar();
	return 0;
}