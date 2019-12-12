#include "FaceDetectPlot.h"

//
CFaceDetectPlot::CFaceDetectPlot(CFaceDetect* detect)
	:detect(detect)
{
	plot_color = Scalar(0, 255, 0);
	plot_line_thikness = 1;
	plot_shape = PLOT_RECT;
}

//
CFaceDetectPlot::~CFaceDetectPlot()
{
}

//
bool CFaceDetectPlot::DetectPlot(Mat& frame)
{
	if (!detect) return false;

	vector<Rect> faces;
	if (!detect->Detect(frame, faces)) return false;

	for (auto& face : faces)
	{
		if (plot_shape == PLOT_ELLIPSE)
		{
			// plot ellipse
			Point center(face.x + int(face.width*0.5), face.y + int(face.height*0.5));
			ellipse(frame, center, Size(int(face.width*0.5), int(face.height*0.5)), 0, 0, 360, plot_color, plot_line_thikness, 8, 0);
		}
		else if (plot_shape == PLOT_BLUR)
		{
			// blur the face rectangle
			blur(frame(face), frame(face), Size(30, 30));
		}
		else
		{
			// plot rectangle (default)
			rectangle(frame, face, plot_color, plot_line_thikness);
		}
	}

	return true;
}

//
void CFaceDetectPlot::setPlotShape(PlotShape shape)
{
	plot_shape = shape;
}
