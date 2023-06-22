#include "Cramer.h"
void Cramer::makeSolution()
{
	printMatrix(A);
	for (int i = 0; i < n; i++)
	{
		std::cout << "\n\nВычислим D" << i + 1<< ":\n\n";
		swapColumn(i); // меняем столбец под номером i на вектор правых частей
		D[i] = findDet(A, n); 
		printMatrix(A);
		std::cout << "\nD" << i + 1 << " = " << D[i] << std::endl;
		swapColumn(i); // меняем обратно
	}
	std::cout << "\n\nВычислим значения вектора неизвестных (Х) с " << pow(10, -1*precision) << "\n\n";
	for (int i = 0; i < n; i++)
	{
		X[i] = D[i] / det;
		soop::roundBy(X[i], precision + 1);
		std::cout << "x" << i << " = " << D[i] << "/" << det << " = " << X[i] << std::endl;
	}
}

void Cramer::swapColumn(int &j)
{
	for(int i = 0; i < n; i++)
	std::swap(A[i][j], B[i]);
}