#ifndef _OPER_MAT_H_
#define _OPER_MAT_H_

//������� �-��
double** create_mat(int size);

//���������� �������� ����������� �-��
int input_size();

//������ �������� ��-��� �-��
double** input_mat(int size);

//������� �-��
void output_mat(double** mat, int size);

//������� � �������� �-��
void clean_mat(double** mat, int size);

//����������� ����� �-�� �� ������
void copy_mat(double** mat_from, double** mat_to, int size);

//�������� ���������� � �������
double** power_mat(double** mat_1, int size, int power);

//�������� ��������� �-�� �� �-��
double** mat_multpy_mat(double** mat_1, double** mat_2, int size);

//�������� ��������� �-��
double** create_identity_mat(int size);

//�������� ��������� �-�� �� �����
double** multiply_by_num_mat(double** mat_1, int size, double num);

//�������� ��������(���������, ���� ������� ��������� �-�� �� -1)
double** addition_mat(double** mat_1, double** mat_2, int size);

//��������� ������� ��� i-� ������ � j-�� �������
double** search_minor_mat(double** mat, int i, int j, int size);

//����������� ���������� ������������ �-�� ����������
double search_determinant(double** mat, int size);

//���������� �������� �-�� ���������� (���� ���������� ���������, �� ������������ �������� �������)
double** search_inverse_mat(double** mat, int size);

//���������� ����������������� �-�� ����������
double** search_transp_mat(double** mat, int size);

//������� �-� (����������)
bool comparison_of_mat(double** mat_1, double** mat_2, int size);

//���������� ��������� f(x)=x^3-10x^2+7x-12 � ������� ������������� �����������
double** calculator_mat(double** mat, int size);

//���������� ��������� 2A*X-2X=B � ������� ������������� �����������
double** calculator_search_x(double** mat_A, double** mat_B, int size);

#endif // _OPER_MAT_H_

