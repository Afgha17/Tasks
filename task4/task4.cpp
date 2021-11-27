#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    int n = 0, k = 0; int sum = 0; int avg;
    int* nums = new int[100]; int i = 0;
    string file1;
    cout << "Имя файла: "; cin >> file1;
    ifstream fin(file1);
    cout << "Массив до: " << endl;
    while (!fin.eof()) {
        fin >> nums[i];
        sum = sum + nums[i];
        cout << nums[i] << ' ';
        n++; i++;
    }
    avg = sum / n;
    for (int i = 0; i < n; i++)
    {
        while (nums[i] != avg)
        {
            if (nums[i] < avg) { nums[i]++; k++; }
            else { nums[i]--; k++; }
        }
    }
    cout << endl << "Массив после: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl << "Ходов: " << k;
    fin.close();
    delete[]nums;
}

