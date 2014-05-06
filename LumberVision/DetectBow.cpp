#include "stdafx.h"
#include "DetectBow.h"

#include "interpolation.h"
using namespace alglib;

#include "Spline2dHelper.h"
#include "BoardParams.h"

CDetectBow::CDetectBow()
{
}


CDetectBow::~CDetectBow()
{
}

// returns max bow (if you laid the board flat on a table what is the max distance to the board)
double CDetectBow::execute(CBoardParams* boardParams)
{
	double maxBow = 0;
	// Use spline interpolation to create approximation of function to match points
	spline2dinterpolant s2dint;

	try
	{
		spline2dbuildbicubicv(*(boardParams->xValues), 
								boardParams->rows, 
								*(boardParams->yValues), 
								boardParams->cols, 
								*(boardParams->zValues), 
								1, 
								s2dint);
	}
	catch (ap_error err)
	{
		maxBow = -1;
	}

	// This should work for parabolic and boards that bow in multiple directions
	CSpline2dHelper helper;
	maxBow = helper.diffMinMax(&s2dint,
								boardParams->xMin,
								boardParams->xMax,
								boardParams->yMin,
								boardParams->yMax);

	return maxBow;
}