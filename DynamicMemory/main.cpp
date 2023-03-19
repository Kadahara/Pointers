#include"stdafxh.h"
#include"FillRand.h"
#include"Allocate.h"
#include"Clear.h"
#include"Print.h"
#include"Push_front.h"
#include"Push_back.h"
#include"Pop_front.h"
#include"Pop_back.h"
#include"Insert.h"
#include"Erase.h"

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������� �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	cout << "���������� �������� � �����" << endl;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "�������� ���������� ��������" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "���������� �������� � ������" << endl;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "�������� �������� �� ������" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	arr = insert(arr, n, value, index);
	cout << "���������� � ������� ������ " << endl;
	Print(arr, n);
	arr = erase(arr, n, value, index);
	cout << "�������� ����� �� �������� ������� " << endl;
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "������� ���-�� �����: "; cin >> rows;
	cout << "������� ���-�� ��������� ������: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������� ������ � ����� �������: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������� ������ � ������ �������: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ �� ����� �������: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ �� ������ �������" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ������ � ����� �������" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "��������� ������ � ������ �������" << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ � ������ �������" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "������� ������ � ����� �������" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	cout << "������� ������ ������: "; cin >> index;
	cout << "��������� ������ � �������� ������� " << endl;
	arr = insert(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "������� ������ �� �������� ������� " << endl;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "��������� ������� �� ������� " << endl;
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "������� ������� �� ������� " << endl;
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	//�������� �������
	Clear(arr, rows);
#endif
}
