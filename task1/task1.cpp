
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int i, j, n, m, k, ch, b;
    cout << "Круговой массив до числа n: "; cin >> n;
    cout << "Шаг: "; cin >> m;
    int* A = new int[100];
    int* B = new int[100];
    i = 0; j = 0; k = 0; ch = 1;
    while (k != 1)
    {
        A[i] = ch;
        if (i % (m - 1) == 0) { B[j] = ch; b = j; j++; }
        i++; ch++;
        if (ch == (n + 1)) ch = 1;
        if ((i % (m - 1) == 0) && (ch == 1)) k = 1;
    }
    cout << "Полученный путь: ";
   
    for (j = 0; j <= b; j++) cout << B[j];
}
