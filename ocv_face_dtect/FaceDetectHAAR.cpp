#include "FaceDetectHAAR.h"

//
CFaceDetectHAAR::CFaceDetectHAAR(const String&  face_cascade_file)
	:face_cascade_name(face_cascade_file)
{
	face_cascade.load(face_cascade_name);
}

//
CFaceDetectHAAR::~CFaceDetectHAAR()
{
}

//
bool CFaceDetectHAAR::Detect(Mat& frame, vector<Rect>& faces)
{
	if (face_cascade.empty() || frame.empty()) return false;

	// convert to gray
	Mat frame_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	return true;
}
