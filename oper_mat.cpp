﻿#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//создает м-цу
double** create_mat(int size)
{
	double** mat = new double* [size];

	for (int i = 0; i < size; i++)
		mat[i] = new double[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;

	return mat;
}

//записываем значение размерности м-цы
int input_size()
{
	double size;
	cin >> size;
	int isize = check_input_int(size);

	return isize;
}

//записываем значения эл-тов м-цы
double** input_mat(int size)
{
	double** mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cin >> mat[i][j];
			check_input_double(mat[i][j]);
		}

	return mat;
}

//выводим м-цу
void output_mat(double** mat, int size)
{
	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << setw(10) << fixed << setprecision(3) << mat[i][j] << " ";
		cout << "\n";
	}
}

//очистка и удаление м-цы
void clean_mat(double** mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			mat[i][j] = 0;
		delete[] mat[i];
	}

	delete[] mat;
}

//копирование одной м-цы во вторую
void copy_mat(double** mat_from, double** mat_to, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat_to[i][j] = mat_from[i][j];
}

//операция возведения в степень
double** power_mat(double** mat_1, int size, int power)
{
	double** mat_2 = create_mat(size);
	copy_mat(mat_1, mat_2, size);

	for (int i = 0; i < (power - 1); i++)
	{
		double** res_mat = create_mat(size);
		//фактически просто умножаем матрицу саму на себя power раз
		for (int j = 0; j < size; j++)
			for (int h = 0; h < size; h++)
				for (int k = 0; k < size; k++)
					res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

		copy_mat(res_mat, mat_2, size);
		clean_mat(res_mat, size);
	}

	return mat_2;
}

//операция умножения м-цы на м-цу
double** mat_multpy_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int j = 0; j < size; j++)
		for (int h = 0; h < size; h++)
			for (int k = 0; k < size; k++)
				res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

	return res_mat;
}

//создание единичной м-цы
double** create_identity_mat(int size)
{
	double** identity_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j)
				identity_mat[i][j] = 1.0;
			else
				identity_mat[i][j] = 0;

	return identity_mat;
}

//операция умножения м-цы на число
double** multiply_by_num_mat(double** mat_1, int size, double num)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			res_mat[i][j] = mat_1[i][j] * num;

			if (abs(res_mat[i][j]) < 0.00001) //против -0
				res_mat[i][j] = 0;
		}

	return res_mat;
}

//операция сложения(вычитания, если сначала домножить м-цу на -1)
double** addition_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] + mat_2[i][j];

	return res_mat;
}

//получение матрицы без i-й строки и j-го столбца(минорной)
double** search_minor_mat(double** mat, int i, int j, int size)
{
	double** minor_mat = create_mat(size - 1);
	int ki, kj, di, dj;
	di = 0;

	for (ki = 0; ki < size - 1; ki++) // проверка индекса строки
	{
		if (ki == i) //если совпало, сдвигаем на 1 строку
			di = 1;

		dj = 0;

		for (kj = 0; kj < size - 1; kj++) // проверка индекса столбца
		{
			if (kj == j) //если совпало, сдвигаем на 1 столбец
				dj = 1;

			minor_mat[ki][kj] = mat[ki + di][kj + dj]; //считаем минор, учитывая сдвиги
		}
	}

	return minor_mat;
}

//рекурсивное вычисление детерминанта (определителя) м-цы квадратной
double search_determinant(double** mat, int size)
{
	double det = 0;
	int parameter = -1;

	if (size == 1)
		det = mat[0][0];
	else if (size == 2)
		det = mat[0][0] * mat[1][1] - (mat[1][0] * mat[0][1]);
	else
	{
		double** minor_mat = create_mat(size - 1);

		for (int i = 0; i < size; i++)
		{
			minor_mat = search_minor_mat(mat, 0, i, size);
			parameter *= -1;
			det += mat[0][i] * parameter * search_determinant(minor_mat, size - 1);
		}
	}

	return det;
}

//вычисление обратной м-цы квадратной (если невозможно вычислить, то возвращается исходная матрица)
double** search_inverse_mat(double** mat, int size)
{   //провекрка определителя на 0
	double det = search_determinant(mat, size);
	if (det == 0)
	{
		cout << "\nОпределитель равен 0. Решений для обратной м-цы нет или бесконечно много";
		return mat;
	}

	double** inverse_mat = create_mat(size);
	//нельзя взять минор у матрицы 1х1
	if (size == 1)
	{
		inverse_mat[0][0] = 1 / mat[0][0];
		return inverse_mat;
	}

	double** minor_mat = create_mat(size - 1);
	int parameter;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if ((i + j) % 2 == 0)
				parameter = 1;
			else
				parameter = -1;

			minor_mat = search_minor_mat(mat, j, i, size);

			inverse_mat[i][j] = (1 / det) * parameter * search_determinant(minor_mat, size - 1);
			if (abs(inverse_mat[i][j]) < 0.00001)
				inverse_mat[i][j] = 0;
		}

	return inverse_mat;
}

//вычисление транспонированной м-цы квадратной
double** search_transp_mat(double** mat, int size)
{
	double** transp_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			transp_mat[i][j] = mat[j][i];

	return transp_mat;
}

//сравние на равенство м-ц (поэлемнтно)
bool comparison_of_mat(double** mat_1, double** mat_2, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (mat_1[i][j] != mat_2[i][j])
				return false;

	return true;
}

//вычисление выражения f(x)=x^3-10x^2+7x-12 с выводом промежуточных результатов
double** calculator_mat(double** x, int size)
{
	double** mat_1 = create_mat(size);//создаем переменные для слагаемых выражения
	double** mat_2 = create_mat(size);
	double** additional_mat = create_mat(size); //создаем дополнительную м-цу для преобразований
	double** res = create_mat(size); //создаем м-цу для результата
	double** identity_mat = create_identity_mat(size); //создание единичной м-цы

	//выписываем, что хотим найти, находим, и выписываем это(так каждый блок)
	cout << "\nx^3: ";
	mat_1 = power_mat(x, size, 3);
	output_mat(mat_1, size);

	cout << "\nx^2: ";
	mat_2 = power_mat(x, size, 2);
	output_mat(mat_2, size);

	//комент себе|| можно ли сделать операцию ниже без копирования? ведь функция берет additional_mat не по ссылке
	cout << "\n(x^2)*(-10): ";
	copy_mat(mat_2, additional_mat, size);
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(additional_mat, size, -10.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2): ";
	res = addition_mat(mat_1, mat_2, size);
	output_mat(res, size);

	cout << "\n7*x: ";
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(x, size, 7.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x: ";
	clean_mat(mat_1, size);
	mat_1 = create_mat(size);
	mat_1 = addition_mat(res, mat_2, size);
	output_mat(mat_1, size);

	cout << "\n-12*E: ";
	clean_mat(mat_2, size);
	mat_2 = create_mat(size);
	mat_2 = multiply_by_num_mat(identity_mat, size, -12.0);
	output_mat(mat_2, size);

	cout << "\n(x^3)-10*(x^2)+7x-12E: ";
	clean_mat(res, size);
	res = create_mat(size);
	res = addition_mat(mat_1, mat_2, size);

	clean_mat(mat_1, size);
	clean_mat(mat_2, size);
	clean_mat(identity_mat, size);
	clean_mat(additional_mat, size);

	return res;
}

//вычисление X из уравнения 2A*X-2X=B с выводом промежуточных результатов
double** calculator_search_x(double** mat_A, double** mat_B, int size, double &flag_det)
{
	double** identity_mat = create_identity_mat(size); //ñîçäàåì åäèíè÷íóþ ì-öó

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
	double det = search_determinant(denominator, size);
	flag_det = det;
	//если определитель матрицы 0
	if (det == 0)
	{
		clean_mat(mat_1, size);
		clean_mat(mat_2, size);
		clean_mat(identity_mat, size);

		return denominator;
	}
	double** inverse_mat_denominator = create_mat(size); //ñîçäàåì îáðàòíóþ ì-öó çíàìåíàòåëÿ
	inverse_mat_denominator = search_inverse_mat(denominator, size);
	output_mat(inverse_mat_denominator, size);

	//X = ((2(A-1E))^-1)*B
	cout << "X:\n";
	double** mat_x = create_mat(size);
	mat_x = mat_multpy_mat(inverse_mat_denominator, mat_B, size);

	clean_mat(mat_1, size);
	clean_mat(mat_2, size);
	clean_mat(denominator, size);
	clean_mat(identity_mat, size);
	clean_mat(inverse_mat_denominator, size);

	return mat_x;
}


//проверка на, то что матрица спец.ортогональная
int check_special_orthogonal_mat(double** mat, int size) {

	double** inverse_mat = create_mat(size);
	double** transp_mat = create_mat(size);
	double det;

	det = search_determinant(mat, size);
	inverse_mat = search_inverse_mat(mat, size);
	transp_mat = search_transp_mat(mat, size);

	if ((det == 1) && (comparison_of_mat(inverse_mat, transp_mat, size)))
		return 1;
	else
		return 0;

	clean_mat(inverse_mat, size);
	clean_mat(transp_mat, size);
	return 0;
}

//обертка для новой лабораторной 6.4
void wrapper(double** mat_A, int size_A, double** mat_B, int size_B) {
	if (size_A != size_B)
		cout << "Необходимы матрицы одинаковой размерности" << endl;
	else {
		double** new_mat_A = create_mat(size_A);
		double** new_mat_B = create_mat(size_A);
		double** x = create_mat(size_A);
		double** E = create_mat(size_A);
		double** E3 = create_mat(size_A);
		
		E = create_identity_mat(size_A);//создаем единичную матрицу
		E3 = multiply_by_num_mat(E, size_A, 3);// E*3
		x = addition_mat(mat_A, E3, size_A);//E*3+A
		new_mat_A = calculator_mat(x, size_A);//находим А'
		output_mat(new_mat_A, size_A);
		cout << endl;

		x = mat_multpy_mat(mat_B, mat_A, size_A);//B*A
		new_mat_B = calculator_mat(mat_A, size_A);//находим матрицу B'
		output_mat(new_mat_B, size_A);

		//проверяем, что матрица A' специальная ортогональная
		int flag2 = check_special_orthogonal_mat(new_mat_A, size_A);

		if (flag2 == 1)
			cout << "\nДа,это спициальная ортогональная матрица";
		else
			cout << "\nНЕТ,это НЕ спициальная ортогональная матрица";
		cout << endl;
		
		//ищем корень матричного уравнения
		double flag_det = 1;
		x = calculator_search_x(new_mat_A, new_mat_B, size_A, flag_det);

		if(flag_det == 0)
			cout << "Определитель равен 0. Решений для обратной м-цы нет или бесконечно много\n";
		else
	     	output_mat(x, size_A);

		clean_mat(new_mat_A, size_A);
		clean_mat(new_mat_B, size_B);
		clean_mat(E, size_A);
		clean_mat(E3, size_A);
		clean_mat(x, size_A);

	}
}