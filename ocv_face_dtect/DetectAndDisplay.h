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

	enum PlotShape { PLOT_RECT, PLOT_ELLIPSE };
	void setPlotShapeFace(PlotShape shape);

	bool detectAndDisplay(bool detct_eyes = true);

protected:
	bool LoadCascades(bool detect_eyes);
	bool detectAndDisplay(Mat& frame, bool detct_eyes);

protected:
	// TODO: can I make a vector of classifiers and expose method: add_classifier?
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	String win_name;
	Scalar face_plot_color;
	Scalar eyes_plot_colr;
	int plot_line_thikness;
	PlotShape face_plot_shape;
};

