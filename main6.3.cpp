/* Лизунова Арина ПМИ-13БО labs6.2
Программа решает матричное уравнение 2A*X-2X=B, где А и X - квадратные м-цы размера size
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

	cout << "Матрица A:\n";
	double** mat_A = input_mat(size); //создаем квадратную м-цу, вводим ее, сначала запрашивая ее размер

	cout << "Матрица B:\n";
	double** mat_B = input_mat(size); //создаем квадратную м-цу, вводим ее, сначала запрашивая ее размер

	cout << "A:\n";
	output_mat(mat_A, size);

	cout << "B:\n";
	output_mat(mat_B, size);

	double** identity_mat = create_identity_mat(size); //создаем единичную м-цу

	//E*(-1)
	cout << "E*(-1):\n";
	double** mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(identity_mat, size, -1.0);
	output_mat(mat_2, size);

	//A-1E
	cout << "A-1E:\n";
	double** mat_1 = create_identity_mat(size);
	mat_1 = addition_mat(mat_A, mat_2, size);
	output_mat(mat_1, size);

	//2(A-1E)
	cout << "2(A-1E):\n";
	double** denominator = create_mat(size);
	denominator = multiply_by_num_mat(mat_1, size, 2.0);
	output_mat(denominator, size);

	//(2(A-1E))^-1
	cout << "(2(A-1E))^-1:\n";
	double** inverse_mat_denominator = create_mat(size); //создаем обратную м-цу знаменателя
	inverse_mat_denominator = search_inverse_mat(denominator, size);
	output_mat(inverse_mat_denominator, size);

	//X = B*((2(A-1E))^-1)
	cout << "X:\n";
	double** mat_x = create_mat(size);
	mat_x = mat_multpy_mat(mat_B, inverse_mat_denominator, size);
	output_mat(mat_x, size);

	clean_mat(mat_x, size);
	clean_mat(mat_A, size);
	clean_mat(mat_B, size);
	clean_mat(mat_1, size);
	clean_mat(mat_2, size);
	clean_mat(denominator, size);
	clean_mat(identity_mat, size);
	clean_mat(inverse_mat_denominator, size);

	system("pause");
	return 0;
}
