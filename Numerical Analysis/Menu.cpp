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
	std::cout << "Меню\n\n";
	std::cout << "1. Заполнить матрицу с клавиатуры\n"
		<< "2. Скопировать матрицу из файла\n"
		<< "3. Вывести СЛАУ на экран\n"
		<< "4. Изменить Аij\n"
		<< "5. Изменить Bi\n\n"
		<< "6. Метод обратной матрицы\n"
		<< "7.Метод Крамера\n";
}

void Menu::control(Matrix &matrix)
{
	std::cout << "\nВведите команду: ";
	unsigned char order;
	std::cin >> order;
	system("cls");
	switch (order)
	{
	case '0':
		return;
	case '1':
		matrix.fillWithKeyboard();
		std::cout << "\nМатрица сохранена!";
		break;
	case '2':
		matrix.CopyFromFile();
		break;
	case '3':
		system("cls");
		std::cout << "Вот что получилось:\n";
		matrix.printSLE();
		break;
	case '4':
	{
		std::cout << "Введите i и j: ";
		unsigned short i, j;
		double val;
		std::cin >> i >> j;
		std::cout << "Введите новое значение (текущее значение: " << matrix.getAij(i, j) << "): ";
		std::cin >> val;
		matrix.setAij(i, j, val);
		break;
	}
	case '5':
	{
		std::cout << "Введите i: ";
		unsigned short i;
		std::cin >> i;
		std::cout << "Введите новое значение (текущее значение: " << matrix.getBi(i) << "): ";
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
		std::cout << "Неверная команда!";
		break;
	}
	system("pause");
	system("cls");
	menu();
	control(matrix);
}
