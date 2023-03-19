#include"FillRand.h"

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращения к элементам массива через арефметику указателей и оператор разыменования. 
		*(arr + i) = rand() % 10000;
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