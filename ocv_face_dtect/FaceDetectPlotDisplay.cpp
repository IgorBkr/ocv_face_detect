#ifdef _MSC_VER
#pragma warning(disable:4996) // instead of _CRT_SECURE_NO_WARNINGS, which doesn't work in current version
#endif

#include "FaceDetectPlotDisplay.h"
#include "FaceDetectHAAR.h"
#include "FaceDetectPlot.h"

const int esc_key = 27;

const string face_cascade_name = "C:/OpenCV/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
const string def_win_name = "Capture: Face Detection";

CFaceDetectPlotDisplay::CFaceDetectPlotDisplay()
{
	win_name = def_win_name;
}


CFaceDetectPlotDisplay::~CFaceDetectPlotDisplay()
{
}

//
bool CFaceDetectPlotDisplay::DetectAndDisplayFromCamera()
{
	CFaceDetectHAAR detect(face_cascade_name);
	CFaceDetectPlot plot(&detect);

	VideoCapture capture;
	Mat frame;

	capture.open(0); // web cam
	if (!capture.isOpened()) return false;

	while (capture.read(frame))
	{
		if (!plot.DetectPlot(frame)) return false;

		imshow(win_name, frame);

		if(waitKey(10) == esc_key) break;
	}

	return true;

}
