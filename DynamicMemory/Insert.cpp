#include"Insert.h"
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
int** insert(int** arr, int& rows, int cols, int index)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}
int** insert_col(int** arr, int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		buffer[index] = *new int[rows] {};
		arr[i] = buffer;
	}
	cols++;
	return arr;
}