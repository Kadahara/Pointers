#include<iostream>
using namespace std;
//#define POINTER

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTER
	int a = 2;
	int* pa = &a; //pa - Pointer to 'a' (Указатель на переменную 'a')
	cout << a << endl;//  Вывод значения "а" на экран.
	cout << &a << endl;// Взятие адреса переменной "а" прямо при выводе.
	cout << pa << endl;// Вывод адреса переменной "а" хранящийся в указатели "ра".
	cout << *pa << endl;//Разыменование указателя "ра", для того чтобы получить значение по адресу.

	int* pb;
	int b = 3;
	pb = &b;
#endif

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl; 
	cout << *arr << endl; 
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}