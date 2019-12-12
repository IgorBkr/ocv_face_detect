#pragma once
#include <string>
using namespace std;

class CFaceDetectPlotDisplay
{
public:
	CFaceDetectPlotDisplay();
	virtual ~CFaceDetectPlotDisplay();

	bool DetectAndDisplayFromCamera();

protected:
	string win_name;
};

