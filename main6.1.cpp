/* Лизунова Арина ПМИ-13БО labs6.1
Программа считает выражение f(A^2)=x^3-10x^2+7x-12, где А-квадратная м-ца размера size
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "oper_mat.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Программа считает выражение f(A^2)=x^3-10x^2+7x-12, где А-квадратная м-ца\n";

	int size = 0;

	cout << "Введите размер м-цы: ";
	size = input_size();

	double** mat = input_mat(size); //создаем квадратную м-цу, вводим ее
	double** x = create_mat(size); //создаем м-цу x

	cout << "\nA: ";
	output_mat(mat, size);

	cout << "\nA^2: ";
	x = power_mat(mat, size, 2);
	output_mat(x, size);

	double** res = create_mat(size); //создаем м-цу для вывода результата
	//вычисление выражения(от x) с выводом промежуточных результатов
	res = calculator_mat(x, size);
	output_mat(res, size);

	clean_mat(res, size);
	clean_mat(mat, size);
	clean_mat(x, size);

	system("pause");
	return 0;
}
