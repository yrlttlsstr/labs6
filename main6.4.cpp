/* Ëčçóíîâŕ Ŕđčíŕ ĎĚČ-13ÁÎ labs6.1
Ďđîăđŕěěŕ ń÷čňŕĺň âűđŕćĺíčĺ f(A^2)=x^3-10x^2+7x-12, ăäĺ Ŕ-ęâŕäđŕňíŕ˙ ě-öŕ đŕçěĺđŕ size
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
	//вводим первую матрицу А
	int size_A = input_size();
	double** mat_A = input_mat(size_A); //создаем квадратную м-цу, вводим ее
	//вводим вторую матрицу B
	int size_B = input_size();
	double** mat_B = input_mat(size_B); //создаем м-цу x
	//процедура обертка
	wrapper(mat_A,size_A, mat_B,size_B);

	
	//чистим память
	clean_mat(mat_A, size_A);
	clean_mat(mat_B, size_B);
	
	system("pause");
	return 0;
}