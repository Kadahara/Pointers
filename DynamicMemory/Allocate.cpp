#include"Allocate.h"

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