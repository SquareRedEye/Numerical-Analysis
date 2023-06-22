#pragma once
#include <iostream>

#include "extras.h"
class Matrix
{
protected:
	unsigned short n; // ����������� �������
	double **A; // ���������� ������� �������������
	double *B; // ������ ������ ������
	double *X; // ������ �����������
	double det; // ������������ �������

public:
	Matrix();
	void CopyFromFile(); // ����������� ������� �� ����� 
	void fillWithKeyboard(); // ��������� ������� � ����������

	void printSLE_x(double **A, double *B, double *X) const; // ������� ���� � ������������ �
	void printSLE() const; // ������� ����
	void printMatrix(double **); // ������� ������� �������������

	double getAij(unsigned short &i, unsigned short &j) const { return A[i][j]; }
	double getBi(unsigned short &i) const { return B[i]; }

	void setAij(unsigned short &i, unsigned short &j, double &val) { A[i][j] = val; }
	void setBi(unsigned short &i, double &val) { B[i] = val; }
	~Matrix()
	{
		soop::clearMemory(A, n);
		delete[] A;
		delete[] X;
		delete[] B;
	}
};

