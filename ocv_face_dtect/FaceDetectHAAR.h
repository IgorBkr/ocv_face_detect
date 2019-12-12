#pragma once
#include "FaceDetect.h"

class CFaceDetectHAAR : public CFaceDetect
{
public:
	CFaceDetectHAAR(const String&  face_cascade_file);
	virtual ~CFaceDetectHAAR();

	virtual bool Detect(Mat& frame, vector<Rect>& faces);

protected:
	String face_cascade_name;
	CascadeClassifier face_cascade;
};

