#include <iostream>
#include <iomanip>
#include "oper_mat.h"
#include "check_input.h"

using namespace std;

//проверка корректности данных типа double
double check_input_double(double& num)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "¬ведите корректные данные" << endl;
		cin >> num;
	}
	return num;
}

//проверка корректности данных типа int
int check_input_int(double& num)
{
	while (cin.fail() or (num <= 0)or(num!=(int)num))
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "¬ведите корректные данные" << endl;
		cin >> num;
	}
	return (int)num;
}