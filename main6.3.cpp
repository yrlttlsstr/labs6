/* �������� ����� ���-13�� labs6.2
��������� ������ ��������� ��������� 2A*X-2X=B, ��� �, B � X - ���������� �-�� ������� size
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

	cout << "��������� ������ ��������� ��������� 2A*X-2X=B, ��� � � X - ���������� �-�� ������� size\n";
	//����������� ��������� 2A*X-2X = B -> 2X(A-1*E) = B -> 2X = B/(A-1*E) -> X = B/(2(A-1E))

	int size = 0;

	cout << "������� ������ �-�: ";
	size = input_size();

	cout << "������� A:\n";
	double** mat_A = input_mat(size); //������� ���������� �-��, ������ ��, ������� ���������� �� ������

	cout << "������� B:\n";
	double** mat_B = input_mat(size); //������� ���������� �-��, ������ ��, ������� ���������� �� ������

	cout << "A:\n";
	output_mat(mat_A, size);

	cout << "B:\n";
	output_mat(mat_B, size);

	double** mat_x = create_mat(size);

	//���������� ��������� 2A*X-2X=B � ������� ������������� �����������
	mat_x = calculator_search_x(mat_A, mat_B, size);
	output_mat(mat_x, size);
	clean_mat(mat_x, size);

	clean_mat(mat_A, size);
	clean_mat(mat_B, size);

	system("pause");
	return 0;
}
