#include<iostream>
using namespace std;
#define tab "\t"
void Exchange(int* pa, int* pb);

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	int* pa = &a;
	int* pb = &b;
	cout << a << tab << b << endl;
	Exchange(pa, pb);
	cout << a << tab << b << endl;
}

void Exchange(int* pa, int* pb)
{
	int buffer = *pa;
	*pa = *pb;
	*pb = buffer;
}