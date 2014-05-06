#pragma once
#include "ImageProcessingStrategy.h"
#include "ap.h"
using namespace alglib;

class CDetectBow :
	public CImageProcessingStrategy
{
public:
	CDetectBow();
	virtual ~CDetectBow();

	// returns max bow (if you laid the board flat on a table what is the max distance to the board)
	virtual double execute(CBoardParams* boardParams);
};

