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
	cout << "Введите элемент массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	cout << "добавление элемента в конец" << endl;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "удаление последнего элемента" << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "добавление элемента в начало" << endl;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "удаление элемента из начало" << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	cout << "добавление в заданый индекс " << endl;
	Print(arr, n);
	arr = erase(arr, n, value, index);
	cout << "Удаление числа из заданого индекса " << endl;
	Print(arr, n);

	delete[] arr;
#endif DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите кол-во строк: "; cin >> rows;
	cout << "Введите кол-во элементов строки: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в конец массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в начало массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Убирает строку из конца массива: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Уберает строку из начало массива" << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляет стобец в конец массива" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавляет стобец в начало массива" << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Уберает стобец в начале массива" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Уберает стобец в конце массива" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	int index;
	cout << "Введите индекс строки: "; cin >> index;
	cout << "Добавляет строку в заданный индекса " << endl;
	arr = insert(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Уберает строку из заданого индекса " << endl;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Добавляет столбец по индексу " << endl;
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << "Уберает столбец по индексу " << endl;
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	//удаление массива
	Clear(arr, rows);
#endif
}
int** Allocate(int rows, int cols)
{
	//создание двумерного динамического массива (массив указателей)
	int** arr = new int* [rows];
	//создаем строки двумерного массива
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
		//Обращения к элементам массива через арефметику указателей и оператор разыменования. 
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
		//Обращения к элементам массива через оператор индексирования.
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
	//1)cоздаем новый массив нужного размера 
	int* buffer = new int[n + 1];
	//2) Копируем все содержимое исходного массива в новый:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив
	delete[] arr;
	//4)подменяем адрес старого массива адресом нового.
	arr = buffer;
	//5) только после всего этого в массиве 'arr' появляется элементо в который можно сохранить добовляемое значение.
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
	//1) Переопредляем массив указателей:
	int** buffer = new int* [rows + 1] {};
	//2) Копируем адреса строк из исходного массива указателей в новый:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) Удаляем старый массив указателей:
	delete[] arr;
	//4) Добавляем новую строку в новый массив указателей:
	buffer[rows] = new int[cols] {};
	//5) После добавления строки, количество строк увеличивается на 1:
	rows++;
	//6) Возвращаем новый массив на место вызова:
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
	//1) Удаляем из памяти последнюю строку:
	delete[] arr[rows - 1];
	//2) Переопределяем массив указателей:
	int** buffer = new int* [--rows];
	//3) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//4) Удаляем исходный массив указателей:
	delete[] arr;
	//5) Возвращаем новый массив на место вызова:
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
