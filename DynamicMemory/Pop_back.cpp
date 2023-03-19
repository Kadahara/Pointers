#include"Pop_back.h"
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
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