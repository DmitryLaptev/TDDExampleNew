// TDDLinearC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "LinearEquation.h"
#include "SystemOfLinearEquation.h"
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(NULL));
    int n = 5;
    vector<double> Gauss; 
    SystemOfLinearEquation listofcoef(n);
    LinearEquation a(5);
    LinearEquation b(5);
    LinearEquation c(5);
    LinearEquation d(5);
    a.randomInput();
    b.randomInput();
    c.randomInput();
    d.randomInput();
    listofcoef.AddLE(a);
    listofcoef.AddLE(b);
    listofcoef.AddLE(c);
    listofcoef.AddLE(d);
    cout << (string)(listofcoef) << endl;
    listofcoef.stepConvert();
    Gauss = listofcoef.gaussMethod();
    for (int i = 0; i < Gauss.size(); i++) cout << Gauss[i] << ' ';
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
