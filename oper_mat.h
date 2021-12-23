#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//создает м-цу
double** create_mat(int size);

//записываем значение размерности м-цы
int input_size();

//вводим значения эл-тов м-цы
double** input_mat(int size);

//выводим м-цу
void output_mat(double** mat, int size);

//очистка и удаление м-цы
void clean_mat(double** mat, int size);

//копирование одной м-цы во вторую
void copy_mat(double** mat_from, double** mat_to, int size);

//операция возведения в степень
double** power_mat(double** mat_1, int size, int power);

//операция умножения м-цы на м-цу
double** mat_multpy_mat(double** mat_1, double** mat_2, int size);

//создание единичной м-цы
double** create_identity_mat(int size);

//операция умножения м-цы на число
double** multiply_by_num_mat(double** mat_1, int size, double num);

//операция сложения(вычитания, если сначала домножить м-цу на -1)
double** addition_mat(double** mat_1, double** mat_2, int size);

//получение матрицы без i-й строки и j-го столбца
double** search_minor_mat(double** mat, int i, int j, int size);

//рекурсивное вычисление детерминанта м-цы квадратной
double search_determinant(double** mat, int size);

//вычисление обратной м-цы квадратной (если невозможно вычислить, то возвращается исходная матрица)
double** search_inverse_mat(double** mat, int size);

//вычисление транспонированной м-цы квадратной
double** search_transp_mat(double** mat, int size);

//сравние м-ц (поэлемнтно)
bool comparison_of_mat(double** mat_1, double** mat_2, int size);

//вычисление выражения f(x)=x^3-10x^2+7x-12 с выводом промежуточных результатов
double** calculator_mat(double** mat, int size);

//вычисление выражения 2A*X-2X=B с выводом промежуточных результатов
double** calculator_search_x(double** mat_A, double** mat_B, int size);

#endif // _OPER_MAT_H_

