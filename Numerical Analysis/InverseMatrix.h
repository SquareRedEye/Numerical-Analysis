#pragma once
#include "extras.h"
#include "Matrix.h"
#include "MatrixOperations.h"
class InverseMatrix: 
	virtual public Matrix, public MatrixOperations
{
	double **invA;
public:
	InverseMatrix()
	{
		invA = new double *[n];
		for (int i = 0; i < n; i++)
			invA[i] = new double[n];
	}
	void makeSolution();
	~InverseMatrix()
	{
		soop::clearMemory(invA, n);
	}
};

