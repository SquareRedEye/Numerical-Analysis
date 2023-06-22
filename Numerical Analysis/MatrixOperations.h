#pragma once
#include "Matrix.h"
#include "extras.h"

class MatrixOperations :
	virtual public Matrix
{
	void cutedMatrix(double **, int &, int &); // ����������� ������ � ������� �� �������� ������� / ���������� ������� ��� ���������� ������
	double findMinor(double **, int &, int &); // ����� ������

public:
	MatrixOperations();
	double findDet(double **, unsigned short); // ��������� ������������ �������
	void findAlgebraicAddition(double **); // �������� ������� �������������� ����������
	void mult(double **, double *, double *);// ��������� ������� �� ������
	void transp(double **); // ��������������� �������
	~MatrixOperations();
protected:
	unsigned short precision; // ��������
};

