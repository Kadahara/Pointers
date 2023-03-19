#pragma once
#include"stdafxh.h"
int* pop_front(int arr[], int& n);
int** pop_row_front(int** arr, int& rows, const int cols);
void pop_col_front(int** arr, const int rows, int& cols);