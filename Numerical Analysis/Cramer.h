#pragma once
#include "extras.h"
#include "Matrix.h"
#include "MatrixOperations.h"
class Cramer:
	virtual public Matrix, public MatrixOperations
{
	double *D;
	void swapColumn(int &);
public:
	Cramer()
	{
		D = new double[n];
	}
	void makeSolution();
	~Cramer()
	{
		delete[] D;
	}
};

