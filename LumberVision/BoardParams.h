#pragma once
#include "ap.h"
using namespace alglib;

class CBoardParams
{
// todo: add get/set functions
public:
	real_1d_array *xValues;
	int rows;
	real_1d_array *yValues;
	int cols;
	real_1d_array *zValues;
	double xMin;
	double xMax;
	double yMin;
	double yMax;

public:
	CBoardParams();
	CBoardParams(real_1d_array *xV,
		int r,
		real_1d_array *yV,
		int c,
		real_1d_array *zV,
		double xMin,
		double xMax,
		double yMin,
		double yMax) : xValues(xV),
						rows(r),
						yValues(yV),
						cols(c),
						zValues(zV),
						xMin(xMin),
						xMax(xMax),
						yMin(yMin),
						yMax(yMax) {}

	virtual ~CBoardParams();
};

