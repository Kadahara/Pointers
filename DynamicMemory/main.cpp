#include<iostream>
using namespace std;
#define tab "\t"
int** Allocate(int rows, int cols);
void Clear(int** arr, int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);

int* push_front(int arr[], int& n, int value);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, int value, int index);
int** insert(int** arr, int& rows,  int cols, int index);
int** insert_col(int** arr, int rows, int& cols, int index);
int* erase(int arr[], int& n, int value, int index);
int** erase_row(int** arr, int& rows, int cols, int index);
int** erase_col(int** arr, int rows, int& cols, int index);

int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);

int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);

void pop_col_front(int** arr, const int rows, int& cols);
void pop_col_back(int** arr, const int rows, int& cols);



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
int** Allocate(int rows, int cols)
{
	//�������� ���������� ������������� ������� (������ ����������)
	int** arr = new int* [rows];
	//������� ������ ���������� �������
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void Clear(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� ������� ����� ���������� ���������� � �������� �������������. 
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� ������� ����� �������� ��������������.
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << tab;
			//cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[],int &n, int value)
{
	//1)c������ ����� ������ ������� ������� 
	int* buffer = new int[n + 1];
	//2) �������� ��� ���������� ��������� ������� � �����:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������
	delete[] arr;
	//4)��������� ����� ������� ������� ������� ������.
	arr = buffer;
	//5) ������ ����� ����� ����� � ������� 'arr' ���������� �������� � ������� ����� ��������� ����������� ��������.
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) ������������� ������ ����������:
	int** buffer = new int* [rows + 1] {};
	//2) �������� ������ ����� �� ��������� ������� ���������� � �����:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) ������� ������ ������ ����������:
	delete[] arr;
	//4) ��������� ����� ������ � ����� ������ ����������:
	buffer[rows] = new int[cols] {};
	//5) ����� ���������� ������, ���������� ����� ������������� �� 1:
	rows++;
	//6) ���������� ����� ������ �� ����� ������:
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
int*  pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	//1) ������� �� ������ ��������� ������:
	delete[] arr[rows - 1];
	//2) �������������� ������ ����������:
	int** buffer = new int* [--rows];
	//3) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4) ������� �������� ������ ����������:
	delete[] arr;
	//5) ���������� ����� ������ �� ����� ������:
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	delete[] arr[0];
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	arr[cols--];
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}
int* insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
int** insert(int** arr, int& rows,int cols, int index)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_col(int** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		buffer[index] = *new int[rows] {};
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
int* erase(int arr[], int& n, int value, int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	delete[]arr;
	return buffer;
}
int** erase_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}
int** erase_col(int** arr, int rows, int& cols, int index)
{ 
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
	return arr;
}
