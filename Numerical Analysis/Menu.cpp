#include "Menu.h"
#include <iostream>
#include "InverseMatrix.h"
#include "Cramer.h"
Menu::Menu()
{
	Matrix matrix;
	menu();
	control(matrix);
}

void Menu::menu() const
{
	std::cout << "����\n\n";
	std::cout << "1. ��������� ������� � ����������\n"
		<< "2. ����������� ������� �� �����\n"
		<< "3. ������� ���� �� �����\n"
		<< "4. �������� �ij\n"
		<< "5. �������� Bi\n\n"
		<< "6. ����� �������� �������\n"
		<< "7.����� �������\n";
}

void Menu::control(Matrix &matrix)
{
	std::cout << "\n������� �������: ";
	unsigned char order;
	std::cin >> order;
	system("cls");
	switch (order)
	{
	case '0':
		return;
	case '1':
		matrix.fillWithKeyboard();
		std::cout << "\n������� ���������!";
		break;
	case '2':
		matrix.CopyFromFile();
		break;
	case '3':
		system("cls");
		std::cout << "��� ��� ����������:\n";
		matrix.printSLE();
		break;
	case '4':
	{
		std::cout << "������� i � j: ";
		unsigned short i, j;
		double val;
		std::cin >> i >> j;
		std::cout << "������� ����� �������� (������� ��������: " << matrix.getAij(i, j) << "): ";
		std::cin >> val;
		matrix.setAij(i, j, val);
		break;
	}
	case '5':
	{
		std::cout << "������� i: ";
		unsigned short i;
		std::cin >> i;
		std::cout << "������� ����� �������� (������� ��������: " << matrix.getBi(i) << "): ";
		double val;
		std::cin >> val;
		matrix.setBi(i, val);
		break;
	}
	case '6':
	{
		InverseMatrix().makeSolution();
		break;
	}
	case '7':
	{
		Cramer().makeSolution();
		break;
	}
	default:
		std::cout << "�������� �������!";
		break;
	}
	system("pause");
	system("cls");
	menu();
	control(matrix);
}
