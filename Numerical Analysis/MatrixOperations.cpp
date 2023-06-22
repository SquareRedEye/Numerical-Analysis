#include "MatrixOperations.h"
#include <iostream>
MatrixOperations::MatrixOperations()
{
	precision = 2;
	det = findDet(A, n);
	std::cout << "Вычислим определитель матрицы (D) = detA = " << det << std::endl;
	soop::roundBy(det, precision + 1);
}
double MatrixOperations::findDet(double** a, unsigned short size) { //Рекурсивная функция вычисления определителя матрицы
	unsigned short n = size;
	if (n == 1)
		return a[0][0];
	else if (n == 2)
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		double d = 0;
		for (int k = 0; k < n; k++) {
			double** b = new double*[n - 1];
			for (int i = 0; i < n - 1; i++) {
				b[i] = new double[n - 1];
			}
			for (int i = 1; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j == k)
						continue;
					else if (j < k)
						b[i - 1][j] = a[i][j];
					else
						b[i - 1][j - 1] = a[i][j];
				}
			}
			d += pow(-1, k + 2) * a[0][k] * findDet(b, n - 1);
			soop::clearMemory(b, n - 1);
		}
		return soop::roundBy(d, precision + 1);
	}
}

void MatrixOperations::findAlgebraicAddition(double **aa)
{
	double **for_minor = new double *[n - 1];
	for (int i = 0; i < n - 1; i++)
		for_minor[i] = new double[n - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aa[i][j] = pow(-1.0, i + j + 2) * findMinor(for_minor, i, j);
			soop::roundBy(aa[i][j], precision + 1);
		}
	}
	soop::clearMemory(for_minor, n - 1);
}

double MatrixOperations::findMinor(double **matrix, int &i, int &j)
{
	cutedMatrix(matrix, i, j);
	return findDet(matrix, n - 1);
}

void MatrixOperations::cutedMatrix(double **matrix, int &indRow, int &indCol)
{
	int ki = 0;
	for (int i = 0; i < n; i++) {
		if (i != indRow) {
			for (int j = 0, kj = 0; j < n; j++) {
				if (j != indCol) {
					matrix[ki][kj] = A[i][j];
					kj++;
				}
			}
			ki++;
		}
	}
}

void MatrixOperations::mult(double **matrix, double *vec, double *res)
{
	for (int i = 0; i < n; i++)
	{
		res[i] = 0;
		for (int j = 0; j < n; j++)
		{
			res[i] += matrix[i][j] * vec[j];
			soop::roundBy(res[i], precision + 1);
		}
	}
}

void MatrixOperations::transp(double **matrix)
{
	double **temp = new double*[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = temp[j][i];
	soop::clearMemory(temp, n);
}
MatrixOperations::~MatrixOperations()
{
	std::cout << "\n\nВыполним проверку полученного результата подстановкой в исходную СЛУ:\n\n";
	double*t_B = new double[n];
	for (int i = 0; i < n; i++)
		soop::roundBy(X[i], precision);
	mult(A, X, t_B);
	printSLE_x(A, t_B, X);
	std::cout << "\n\nАбсолютная погрешность составляет\n\n";
	for (int i = 0; i < n; i++)
		 std::cout << "для уравнения " << i + 1 << " -- "
			<< abs(B[i] - t_B[i]) << std::endl ;
	
		delete[] t_B;
}