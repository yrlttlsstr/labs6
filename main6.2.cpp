/* �������� ����� ���-13�� labs6.2
��������� ���������, �������� �� �-�� A ����������� ������������� (������������ ����� 1, ����������������� ��������� � ��������), ��� �-���������� �-�� ������� size
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

	cout << "��������� ���������, �������� �� �-�� A ����������� ������������� (������������ ����� 1, ����������������� ��������� � ��������), ��� �-���������� �-��\n";

	int size = 0;

	cout << "������� ������ �-��: ";
	size = input_size();

	double** mat = input_mat(size); //������� ���������� �-��, ������ ��

	cout << "\nA: ";
	output_mat(mat, size);

	double** inverse_mat = create_mat(size); //������� �-�� ��� �������� �-��
	double** transp_mat = create_mat(size); //������� �-�� ��� ����������������� �-��
	double det; //������������

	det = search_determinant(mat, size);
	inverse_mat = search_inverse_mat(mat, size);
	transp_mat = search_transp_mat(mat, size);

	if ((det == 1) and (comparison_of_mat(inverse_mat, transp_mat, size)))
	{
		cout << "\n������� �������� ����������� �������������";
		clean_mat(inverse_mat, size);
	}
	else
		cout << "\n������� �� �������� ����������� �������������";

	clean_mat(mat, size);
	clean_mat(transp_mat, size);

	system("pause");
	return 0;
}
