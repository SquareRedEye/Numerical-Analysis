#pragma once
#include "Matrix.h"
#include "extras.h"

class MatrixOperations :
	virtual public Matrix
{
	void cutedMatrix(double **, int &, int &); // вычёркивает строку и столбец из исходной матрицы / возвращает матрицу для вычисления минора
	double findMinor(double **, int &, int &); // поиск минора

public:
	MatrixOperations();
	double findDet(double **, unsigned short); // вычисляет определитель матрицы
	void findAlgebraicAddition(double **); // получаем матрицу алгебраических дополнений
	void mult(double **, double *, double *);// умножение матрицы на вектор
	void transp(double **); // транспонировать матрицу
	~MatrixOperations();
protected:
	unsigned short precision; // точность
};

