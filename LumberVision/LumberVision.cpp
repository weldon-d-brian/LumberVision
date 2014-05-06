// LumberVision.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DetectBow.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "BoardParams.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Welcome to Lumber Vision..." << endl <<  "-------------------------" << endl << endl;

	cout << "Sample 1: parabolic bow (z = -x^2) over x=-5..5 and y=-5..5" << endl << "-----------------" << endl;
	//initialize data...parabolic bow (z = -x^2)
	real_1d_array xValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	const int rows = 11; 
	real_1d_array yValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	const int cols = 11;
	double temp[rows*cols];
	int i = 0;
	for (int x = -5; x < 6; x++)
	{
		for (int y = -5; y < 6; y++)
		{
			temp[i++] = double(-x*x);
		}
	}
	real_1d_array zValues;
	zValues.setcontent(rows*cols, temp);
	
	CBoardParams boardParams(&xValues, rows, &yValues, cols, &zValues, double(-5), double(5), double(-5), double(5));
	CDetectBow db;
	double height = db.execute(&boardParams); // the height of the bow

	cout << fixed << setprecision(2) << "Bow found across board: " << height << endl << "----------------------" << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "Sample 2: parabolic bow (z = (x^2)/2) over x=-5..5 and y=-5..5" << endl << "-----------------" << endl;
	xValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	yValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	i = 0;
	for (int x = -5; x < 6; x++)
	{
		for (int y = -5; y < 6; y++)
		{
			temp[i++] = double((x*x)/2);
		}
	}
	zValues.setcontent(rows*cols, temp);

	CBoardParams boardParams2(&xValues, rows, &yValues, cols, &zValues, double(-5), double(5), double(-5), double(5));
	CDetectBow db2;
	double height2 = db2.execute(&boardParams2); // the height of the bow

	cout << fixed << setprecision(2) << "Bow found across board: " << height2 << endl << "----------------------" << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Sample 3: non-parabolic bow (z = (1/10) *(x)^3 + y) over x=-5..5 and y=-5..5" << endl << "-----------------" << endl;
	xValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	yValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	i = 0;
	for (int x = -5; x < 6; x++)
	{
		for (int y = -5; y < 6; y++)
		{
			temp[i++] = double((1 / 10) *(x) ^ 3 + y);
		}
	}
	zValues.setcontent(rows*cols, temp);

	CBoardParams boardParams3(&xValues, rows, &yValues, cols, &zValues, double(-5), double(5), double(-5), double(5));
	CDetectBow db3;
	double height3 = db3.execute(&boardParams3); // the height of the bow

	cout << fixed << setprecision(2) << "Bow found across board: " << height3 << endl << "----------------------" << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "Sample 4: no bow (z = 2) over x=-5..5 and y=-5..5" << endl << "-----------------" << endl;
	xValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	yValues = "[-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5]";
	i = 0;
	for (int x = -5; x < 6; x++)
	{
		for (int y = -5; y < 6; y++)
		{
			temp[i++] = double(2);
		}
	}
	zValues.setcontent(rows*cols, temp);

	CBoardParams boardParams4(&xValues, rows, &yValues, cols, &zValues, double(-5), double(5), double(-5), double(5));
	CDetectBow db4;
	double height4 = db4.execute(&boardParams4); // the height of the bow

	cout << fixed << setprecision(2) << "Bow found across board: " << height4 << endl << "----------------------" << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////


	cout << endl << "Thank you for using Lumber Vision." << endl << "Press <enter> to exit..." << endl << endl;
	cin.get();
	return 0;
}

