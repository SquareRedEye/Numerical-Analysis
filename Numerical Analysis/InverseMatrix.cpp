#include "InverseMatrix.h"

void InverseMatrix::makeSolution()
{
	std::cout << "\n\nВычислим матрицу алгебраических дополнений:\n\n";
	findAlgebraicAddition(invA); // Получаем матрицу алебраических дополнений
	printMatrix(invA);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			invA[j][i] /= det;
			soop::roundBy(invA[j][i], precision + 1);
		}
	}
	std::cout << "\n\nТранспонируем матрицу алгебраических дополнений:\n\n";
	transp(invA); // транспонируем матрицу алебраических дополнений
	printMatrix(invA);
	std::cout << "\n\nВычислим значения вектора неизвестнынх (Х) с точностью (d) = " << pow(10, -1 * precision) << ":\n\n ";
	mult(invA, B, X); // умножаем матрицу алебраических дополнений на вектор парвых частей 
	printSLE_x(invA, X, B);
}