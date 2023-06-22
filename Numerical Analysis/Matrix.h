#pragma once
#include <iostream>

#include "extras.h"
class Matrix
{
protected:
	unsigned short n; // размерность матрицы
	double **A; // квадратная матрица коэффициентов
	double *B; // вектор парвых частей
	double *X; // вектор неизвестных
	double det; // определитель матрицы

public:
	Matrix();
	void CopyFromFile(); // скопировать матрицу из файла 
	void fillWithKeyboard(); // заполнить матрицу с клавиатуры

	void printSLE_x(double **A, double *B, double *X) const; // вывести СЛАУ с подстановкой Х
	void printSLE() const; // вывести СЛАУ
	void printMatrix(double **); // Вывести матрицу коэффициентов

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

