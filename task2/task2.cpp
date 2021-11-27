#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int xc, yc, r;
    ifstream fin("file1.txt");
    fin >> xc;
    fin >> yc;
    fin >> r;
    fin.close();
    int x, y;
    int i = 0;
    ifstream finn("file2.txt");
    while (!finn.eof()) {
        finn >> x;
        finn >> y;

        if ((pow(x - xc, 2) + pow(y - yc, 2)) > pow(r, 2)) cout << i << " - точка снаружи" << endl;
        else if ((pow(x - xc, 2) + pow(y - yc, 2)) < pow(r, 2)) cout << i << " - точка внутри" << endl;
        else cout << i << " - точка лежит на окружности" << endl;
        i++;
    }
    finn.close();
    return 0;
}
