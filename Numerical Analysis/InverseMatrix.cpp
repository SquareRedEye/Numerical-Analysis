#include "InverseMatrix.h"

void InverseMatrix::makeSolution()
{
	std::cout << "\n\n�������� ������� �������������� ����������:\n\n";
	findAlgebraicAddition(invA); // �������� ������� ������������� ����������
	printMatrix(invA);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			invA[j][i] /= det;
			soop::roundBy(invA[j][i], precision + 1);
		}
	}
	std::cout << "\n\n������������� ������� �������������� ����������:\n\n";
	transp(invA); // ������������� ������� ������������� ����������
	printMatrix(invA);
	std::cout << "\n\n�������� �������� ������� ������������ (�) � ��������� (d) = " << pow(10, -1 * precision) << ":\n\n ";
	mult(invA, B, X); // �������� ������� ������������� ���������� �� ������ ������ ������ 
	printSLE_x(invA, X, B);
}