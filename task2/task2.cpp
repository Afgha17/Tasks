#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    float xc, yc, r;
    string file1, file2;
    cout << "Имя файла, где указаны координаты центра окр-сти и радиус: "; cin >> file1;
    cout <<endl<< "Имя файла, где указаны координаты точек: "; cin >> file2;
    ifstream fin(file1);
    fin >> xc;
    fin >> yc;
    fin >> r;
    fin.close();
    float x, y;
    int i = 0;

    ifstream finn(file2);
    while (!finn.eof()) {
        finn >> x;
        finn >> y;

        if ((pow(x - xc, 2) + pow(y - yc, 2)) > pow(r, 2)) cout << i << " - точка снаружи" << endl;
        else if ((pow(x - xc, 2) + pow(y - yc, 2)) < pow(r, 2)) cout << i << " - точка внутри" << endl;
        else cout << i << " - точка лежит на окружности" << endl;
        i++;
    }
    finn.close();
    system("pause");
}
