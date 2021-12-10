#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//�������� ������������ ������ ���� double
double check_input_double(double& num)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������� ���������� ������" << endl;
		cin >> num;
	}
	return num;
}

//�������� ������������ ������ ���� int
int check_input_int(int& num)
{
	while (cin.fail() or (num <= 0))
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������� ���������� ������" << endl;
		cin >> num;
	}
	return num;
}