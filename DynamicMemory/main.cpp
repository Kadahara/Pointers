#include<iostream>
using namespace std;
#define tab "\t"
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите элемент массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	//1)cоздаем новый массив нужного размера 
	int* buffer = new int[n + 1];
	//2) Копируем все содержимое исходного массива в новый:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив
	delete[] arr;
	//4)подменяем адрес старого массива адресом нового.
	arr = buffer;
	//5) только после всего этого в массиве 'arr' появляется элементо в который можно сохранить добовляемое значение.
	arr[n] = value;
	n++;
	Print(arr, n);
	delete[] arr;

}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращения к элементам массива через арефметику указателей и оператор разыменования. 
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращения к элементам массива через оператор индексирования.
		cout << arr[i] << tab;
	}
	cout << endl;
}