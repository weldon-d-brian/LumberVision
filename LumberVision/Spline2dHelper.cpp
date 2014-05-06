#include "stdafx.h"
#include "Spline2dHelper.h"
#include "interpolation.h"

using namespace alglib;


CSpline2dHelper::CSpline2dHelper()
{
}


CSpline2dHelper::~CSpline2dHelper()
{
}


// return absolute value of difference between min and max over range (the "height" of the bow)
double CSpline2dHelper::diffMinMax(spline2dinterpolant* s2dint, double xMin, double xMax, double yMin, double yMax)
{
	// I know it would be more efficient to take the derivative and solve for when it equals zero
	// but for now I'll use a brute force method
	
	int xLoopMin = int(ceil(xMin)); // make sure we are inside our data points
	int xLoopMax = int(floor(xMax));
	int yLoopMin = int(ceil(yMin));
	int yLoopMax = int(floor(yMax));

	double max = -999999;
	double min = 999999;

	for (int x = xLoopMin; x <= xLoopMax; x++)
	{
		for (int y = yLoopMin; y <= yLoopMax; y++)
		{
			real_1d_array f;
			spline2dcalcv(*s2dint, double(x), double(y), f);
			double value = f[0];
			if (value > max) max = value;
			if (value < min) min = value;
		}
	}

	return abs(max - min);
}
