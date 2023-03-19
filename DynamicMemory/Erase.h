#pragma once
#include"stdafxh.h"
int* erase(int arr[], int& n, int value, int index);
int** erase_row(int** arr, int& rows, int cols, int index);
int** erase_col(int** arr, int rows, int& cols, int index);