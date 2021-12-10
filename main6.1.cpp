/* Лизунова Арина ПМИ-13БО labs6.1
Программа считает выражение f(A^2)=x^3-10x^2+7x-12, где А-квадратная м-ца размера size
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "oper_mat.h"

using namespace std;

int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size = 0;
	double** mat = input_mat(size); //создаем квадратную м-цу, вводим ее, сначала запрашивая ее размер

	//вычисление выражения с выводом промежуточных результатов
	calculator_mat(mat, size);

	clean_mat(mat, size);

	return 0;
	system("pause");
}
