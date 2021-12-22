#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//������� �-��
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

//���������� �������� ����������� �-��
int input_size()
{
	int size;
	cin >> size;
	check_input_int(size);

	return size;
}

//���������� �������� ��-��� �-��
double** input_mat(int size)
{
	double** mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			cout << "������� ��-� �-�� c ������� [" << i << "][" << j << "]: ";
			cin >> mat[i][j];
			check_input_double(mat[i][j]);
		}

	return mat;
}

//������� �-��
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

//������� � �������� �-��
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

//����������� ����� �-�� �� ������
void copy_mat(double** mat_from, double** mat_to, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			mat_to[i][j] = mat_from[i][j];
}

//�������� ���������� � �������
double** power_mat(double** mat_1, int size, int power)
{
	double** mat_2 = create_mat(size);
	copy_mat(mat_1, mat_2, size);

	for (int i = 0; i < (power - 1); i++)
	{
		double** res_mat = create_mat(size);

		for (int j = 0; j < size; j++)
			for (int h = 0; h < size; h++)
				for (int k = 0; k < size; k++)
					res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

		copy_mat(res_mat, mat_2, size);
		clean_mat(res_mat, size);
	}

	return mat_2;
}

//�������� ��������� �-�� �� �-��
double** mat_multpy_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int j = 0; j < size; j++)
		for (int h = 0; h < size; h++)
			for (int k = 0; k < size; k++)
				res_mat[j][h] += mat_1[j][k] * mat_2[k][h];

	return res_mat;
}

//�������� ��������� �-��
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

//�������� ��������� �-�� �� �����
double** multiply_by_num_mat(double** mat_1, int size, double num)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) 
		{
			res_mat[i][j] = mat_1[i][j] * num;

			if (abs(res_mat[i][j]) < 0.00001) //������ -0
				res_mat[i][j] = 0;
		}

	return res_mat;
}

//�������� ��������(���������, ���� ������� ��������� �-�� �� -1)
double** addition_mat(double** mat_1, double** mat_2, int size)
{
	double** res_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res_mat[i][j] = mat_1[i][j] + mat_2[i][j];

	return res_mat;
}

//��������� ������� ��� i-� ������ � j-�� �������
double** search_minor_mat(double** mat, int i, int j, int size)
{
	int ki, kj, di, dj;
	di = 0;

	for (ki = 0; ki < size - 1; ki++) // �������� ������� ������
	{
		if (ki == i) //���� �������, �������� �� 1 ������
			di = 1;

		dj = 0;

		for (kj = 0; kj < size - 1; kj++) // �������� ������� �������
		{
			if (kj == j) //���� �������, �������� �� 1 �������
				dj = 1;

			minor_mat[ki][kj] = mat[ki + di][kj + dj]; //������� �����, �������� ������
		}
	}

	return minor_mat;
}

//����������� ���������� ������������ (������������) �-�� ����������
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

//���������� �������� �-�� ����������
double** search_inverse_mat(double** mat, int size)
{
	double det = search_determinant(mat, size);
	if (det == 0)
	{
		cout << "\n������������ ����� 0. ������� ��� �������� �-�� ��� ��� ���������� �����";
		return 0;
	}

	double** inverse_mat = create_mat(size);

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
			if (abs(inverse_mat[i][j]) < 0.00001) //������ -0
				inverse_mat[i][j] = 0;
		}

	return inverse_mat;
}

//���������� ����������������� �-�� ����������
double** search_transp_mat(double** mat, int size)
{
	double** transp_mat = create_mat(size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			transp_mat[i][j] = mat[j][i];

	return transp_mat;
}

//������� �-� (����������)
bool comparison_of_mat(double** mat_1, double** mat_2, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (mat_1[i][j] != mat_2[i][j])
				return false;

	return true;
}

//���������� ��������� f(x)=x^3-10x^2+7x-12 � ������� ������������� �����������
double** calculator_mat(double** x, int size)
{
	double** mat_1 = create_mat(size); //������� ���������� ��� ��������� ���������
	double** mat_2 = create_mat(size);
	double** additional_mat = create_mat(size); //������� �������������� �-�� ��� ��������������
	double** res = create_mat(size); //������� �-�� ��� ����������
	double** identity_mat = create_identity_mat(size); //�������� ��������� �-��

	cout << "\nx^3: ";
	mat_1 = power_mat(x, size, 3);
	output_mat(mat_1, size);

	cout << "\nx^2: ";
	mat_2 = power_mat(x, size, 2);
	output_mat(mat_2, size);

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

//���������� ��������� 2A*X-2X=B � ������� ������������� �����������
double** calculator_search_x(double** mat_A, double** mat_B, int size)
{
	double** identity_mat = create_identity_mat(size); //������� ��������� �-��

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
	if (det == 0)
	{
		cout << "������������ ����� 0. ������� ��� �������� �-�� ��� ��� ���������� �����\n";
		clean_mat(mat_1, size);
		clean_mat(mat_2, size);
		clean_mat(denominator, size);
		clean_mat(identity_mat, size);

		return 0;
	}
	double** inverse_mat_denominator = create_mat(size); //������� �������� �-�� �����������
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