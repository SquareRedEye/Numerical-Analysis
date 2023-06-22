#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <string>
Matrix::Matrix()
{
	n = 4;
	std::cout << "Создаём матрицу" << std::endl;
	B = new double[n];
	X = new double[n];
	A = new double *[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
		X[i] = 0;
	}
	CopyFromFile();
}
void Matrix::CopyFromFile()
{
	std::ifstream file("input.txt");
	if (file.bad() == true) {
		std::cout << "Файла не существует!";
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			file >> A[i][j];
	std::cout << "Матрицы была скопирована из файла!" << std::endl;
	bool trash;
	file >> trash; // Пропускаем одну строку
	for (int i = 0; i < n; i++)
		file >> B[i];
	file.close();
}
void Matrix::fillWithKeyboard()
{
	std::cout << "Введите матрицу А:" << std::endl;
	std::cout << "Введите матрицу B:" << std::endl;

}

void Matrix::printSLE_x(double **A, double *B, double *X) const
{
	using std::cout;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] < 0 && j > 0)
				cout << " - " << -1 * A[i][j] << "*";
			else if (A[i][j] >= 0 && j > 0) 
				cout << " + " << A[i][j] << "*";
			else 
				cout << A[i][j] << "*";

			if (X[j] < 0)
				cout << "(" << X[j] << ")";
			else cout << X[j];

			if (j == n - 1)
				cout << " = " << B[i] << std::endl;
		}
}

void Matrix::printSLE() const
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (j == 0)
				std::cout << A[i][j] << "*x" << j + 1;
			else
			{
				if (A[i][j] < 0) std::cout << " - " << -1 * A[i][j] << "*x" << j + 1;
				else std::cout << " + " << A[i][j] << "*x" << j + 1;
				if (j == n - 1)
					std::cout << " = " << B[i] << std::endl;
			}
}

void Matrix::printMatrix(double **arr)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j] << "\t";
			if (j == n - 1) std::cout << arr[i][j] << std::endl;
		}
	}
}
