#include"Print.h"

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