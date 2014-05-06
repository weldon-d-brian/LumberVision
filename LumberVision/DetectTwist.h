#pragma once
#include "ImageProcessingStrategy.h"
class CDetectTwist :
	public CImageProcessingStrategy
{
public:
	CDetectTwist();
	virtual ~CDetectTwist();

	// not implemented yet
	virtual double execute(CBoardParams* boardParams) { return 0; }
};

