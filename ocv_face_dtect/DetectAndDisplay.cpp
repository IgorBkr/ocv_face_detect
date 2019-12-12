/*
This code initially based on: https://docs.opencv.org/2.4/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html
Note: this is done with old Open CV - some functionality is no longer supported.
*/

#include "DetectAndDisplay.h"

// TODO: should not be hardcoded
const String face_cascade_name = "C:/OpenCV/opencv/sources/data/haarcascades/haarcascade_frontalface_alt.xml";
const String eye_cascade_name = "C:/OpenCV/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
const String def_win_name = "Capture: Face Detection";

// TODO: look here for some updated (?) methods: https://www.geeksforgeeks.org/opencv-c-program-face-detection/ 
// AND here: https://github.com/opencv/opencv/blob/master/samples/cpp/tutorial_code/objectDetection/objectDetection.cpp
// AND (the same excat way as original - updated): https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
// TODO: check Open CV face detection documentation tutorial: https://docs.opencv.org/2.4/modules/contrib/doc/facerec/facerec_tutorial.html (is this for 2.4??)

//
CDetectAndDisplay::CDetectAndDisplay()
{
	win_name = def_win_name;
	face_plot_color = Scalar(0, 255, 0);
	eyes_plot_colr = Scalar(0, 255, 0);
	plot_line_thikness = 1; 
	face_plot_shape = PLOT_RECT;
}

//
CDetectAndDisplay::~CDetectAndDisplay()
{
}

//
void CDetectAndDisplay::setPlotShapeFace(PlotShape shape)
{
	face_plot_shape = shape;
}

//
bool CDetectAndDisplay::detectAndDisplay(bool detect_eyes/* = true*/)
{
	// load cascades
	if (!LoadCascades(detect_eyes)) return false;

	VideoCapture capture;
	Mat frame;

	capture.open(0); // web cam
	if (!capture.isOpened()) return false;

	while (capture.read(frame))
	{
		if (frame.empty()) return false;

		// apply classifiers
		if (!detectAndDisplay(frame, detect_eyes)) return false;

		int c = waitKey(10);
		if (c == 'c') break; // 'c' is an exit key
	}

	return true;
}

//
bool CDetectAndDisplay::detectAndDisplay(Mat& frame, bool detect_eyes)
{
	// convert to gray
	Mat frame_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// detect faces
	vector<Rect> faces;
	// TODO: check docs
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	for (auto& face : faces)
	{
		if (face_plot_shape == PLOT_ELLIPSE)
		{
			// plot ellipse
			Point center(face.x + int(face.width*0.5), face.y + int(face.height*0.5));
			ellipse(frame, center, Size((int)face.width*0.5, (int)face.height*0.5), 0.0, 0.0, 360.0, face_plot_color, plot_line_thikness, 8, 0);
		}
		else if(face_plot_shape == PLOT_BLUR)
		{
			// blur the face rectangle
			blur(frame(face), frame(face), Size(30, 30));
		}
		else
		{
			// plot rectangle (default)
			rectangle(frame, face, face_plot_color, plot_line_thikness);
		}

		if (detect_eyes)
		{
			// detect eyes
			Mat faceROI = frame_gray(face);
			vector<Rect> eyes;

			eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

			for (auto& eye : eyes)
			{
				// plot
				Point center(face.x + eye.x + int(eye.width*0.5), face.y + eye.y + int(eye.height*0.5));
				int radius = cvRound((eye.width + eye.height)*0.25);
				circle(frame, center, radius, eyes_plot_colr, plot_line_thikness, 8, 0);
			}
		}
	}

	// show the frame
	imshow(win_name, frame);
	return true;
}

//
bool CDetectAndDisplay::LoadCascades(bool detect_eyes)
{
	if(face_cascade.empty())
		if (!this->face_cascade.load(face_cascade_name)) return false;
	if(detect_eyes && eyes_cascade.empty())
		if (!this->eyes_cascade.load(eye_cascade_name)) return false;
	return true;
}
