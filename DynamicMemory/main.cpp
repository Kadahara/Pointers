#include"stdafxh.h"
#include"FillRand.h"
#include"Allocate.h"
#include"Clear.h"
#include"Print.h"
#include"Push_front.h"
#include"Push_back.h"
#include"Pop_front.h"
#include"Pop_back.h"
#include"Insert.h"
#include"Erase.h"

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
