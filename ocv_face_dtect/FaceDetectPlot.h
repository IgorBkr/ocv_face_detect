#pragma once
#include "FaceDetect.h"

class CFaceDetectPlot 
{
public:
	// TODO: a shared_pointer, perhaps?
	CFaceDetectPlot(CFaceDetect* detect);
	virtual ~CFaceDetectPlot();

	enum PlotShape { PLOT_RECT, PLOT_ELLIPSE, PLOT_BLUR };
	void setPlotShape(PlotShape shape);

	bool DetectPlot(Mat& frame);

protected:
	CFaceDetect* detect; 
	Scalar plot_color;
	int plot_line_thikness;
	PlotShape plot_shape;
};

