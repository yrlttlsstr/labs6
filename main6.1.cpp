/* �������� ����� ���-13�� labs6.1
��������� ������� ��������� f(A^2)=x^3-10x^2+7x-12, ��� �-���������� �-�� ������� size
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

	cout << "��������� ������� ��������� f(A^2)=x^3-10x^2+7x-12, ��� �-���������� �-��\n";

	int size = 0;

	cout << "������� ������ �-��: ";
	size = input_size();

	double** mat = input_mat(size); //������� ���������� �-��, ������ ��
	double** x = create_mat(size); //������� �-�� x

	cout << "\nA: ";
	output_mat(mat, size);

	cout << "\nA^2: ";
	x = power_mat(mat, size, 2);
	output_mat(x, size);

	double** res = create_mat(size); //������� �-�� ��� ������ ����������
	//���������� ���������(�� x) � ������� ������������� �����������
	res = calculator_mat(x, size);
	output_mat(res, size);

	clean_mat(res, size);
	clean_mat(mat, size);
	clean_mat(x, size);

	system("pause");
	return 0;
}
