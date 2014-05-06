#pragma once

#include "ap.h"
using namespace alglib;
#include "BoardParams.h"

class CImageProcessingStrategy
{
public:
	CImageProcessingStrategy();
	virtual ~CImageProcessingStrategy();

	// use Strategy Pattern and Dependency Injection
	virtual double execute(CBoardParams* boardParams) = 0;
};

