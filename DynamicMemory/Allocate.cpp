#include"Allocate.h"

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