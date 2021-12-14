/* Лизунова Арина ПМИ-13БО labs6.2
Программа проверяет, является ли м-ца A специальной ортогональной (определитель равен 1, транспонированная совпадает с обратной), где А-квадратная м-ца размера size
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

	cout << "Программа проверяет, является ли м-ца A специальной ортогональной (определитель равен 1, транспонированная совпадает с обратной), где А-квадратная м-ца\n";

	int size = 0;

	cout << "Введите размер м-цы: ";
	size = input_size();

	double** mat = input_mat(size); //создаем квадратную м-цу, вводим ее

	cout << "\nA: ";
	output_mat(mat, size);

	double** inverse_mat = create_mat(size); //создаем м-цу для обратной м-цы
	double** transp_mat = create_mat(size); //создаем м-цу для транспонированной м-цы
	double det; //определитель

	det = search_determinant(mat, size);
	inverse_mat = search_inverse_mat(mat, size);
	transp_mat = search_transp_mat(mat, size);

	if ((det == 1) and (comparison_of_mat(inverse_mat, transp_mat, size)))
	{
		cout << "\nМатрица является специальной ортогональной";
		clean_mat(inverse_mat, size);
	}
	else
		cout << "\nМатрица НЕ является специальной ортогональной";

	clean_mat(mat, size);
	clean_mat(transp_mat, size);

	system("pause");
	return 0;
}
