#include <iostream>
using namespace std;

int Merge(int* A, int p, int q, int r)
{
	
	int a, b, j;
	int* mas = new int[100];
	a = p; //начало левой части
	b = q + 1; //начало правой части
	for (j = p; j <= r; j++)
		if ((a <= q) && ((b > r) || (A[a] < A[b])))
		{
			mas[j] = A[a];
			a++;
		}
		else
		{
			mas[j] = A[b];
			b++;
		}
	for (j = p; j <= r; j++) A[j] = mas[j];
	delete[]mas; return 0;
}

int Sort(int* A, int p, int r)
{
	if (p < r)
	{
		int q;
		q = (p + r) / 2;
		Sort(A, p, q);
		Sort(A, q + 1, r);
		Merge(A, p, q, r); return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int i, n;
	int* A = new int[100];
	cout << "Размер массива: "; cin>>n;
	for (i = 1; i <= n; i++)
	{
		cout << i << " элемент: "; cin>>A[i];
	}
	Sort(A, 1, n);
	cout<<"Упорядоченный массив: ";
	for (i = 1; i <= n; i++) cout<<A[i] << " ";
	delete[]A;
}
