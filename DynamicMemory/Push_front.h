#pragma once
#include"stdafxh.h"
int* push_front(int arr[], int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);