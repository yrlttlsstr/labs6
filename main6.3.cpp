/* Лизунова Арина ПМИ-13БО labs6.2
Программа решает матричное уравнение 2A*X-2X=B, где А, B и X - квадратные м-цы размера size
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

	cout << "Программа решает матричное уравнение 2A*X-2X=B, где А и X - квадратные м-цы размера size\n";
	//Преобразуем уравнение 2A*X-2X = B -> 2X(A-1*E) = B -> 2X = B/(A-1*E) -> X = B/(2(A-1E))

	int size = 0;

	cout << "Введите размер м-ц: ";
	size = input_size();

	cout << "Матрица A:\n";
	double** mat_A = input_mat(size); //создаем квадратную м-цу, вводим ее, сначала запрашивая ее размер

	cout << "Матрица B:\n";
	double** mat_B = input_mat(size); //создаем квадратную м-цу, вводим ее, сначала запрашивая ее размер

	cout << "A:\n";
	output_mat(mat_A, size);

	cout << "B:\n";
	output_mat(mat_B, size);

	double** mat_x = create_mat(size);

	//вычисление выражения 2A*X-2X=B с выводом промежуточных результатов
	mat_x = calculator_search_x(mat_A, mat_B, size);
	output_mat(mat_x, size);
	clean_mat(mat_x, size);

	clean_mat(mat_A, size);
	clean_mat(mat_B, size);

	system("pause");
	return 0;
}
