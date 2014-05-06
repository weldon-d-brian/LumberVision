#pragma once
#include "interpolation.h"
using namespace alglib;

class CSpline2dHelper
{
public:
	CSpline2dHelper();
	~CSpline2dHelper();
	double diffMinMax(spline2dinterpolant* s2dint, double xMin, double xMax, double yMin, double yMax);
};

