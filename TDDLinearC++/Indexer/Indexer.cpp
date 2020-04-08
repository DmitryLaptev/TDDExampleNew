// Indexer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Indexer.h"
#include <stdexcept>
using namespace std;
Indexer::Indexer(double* array1, int beg, int end, int len) {
    if (beg + len > n || beg < 0 || len <= 0) throw invalid_argument("ArgumentException");
    else
    {
        this->array1 = array1;
        this->beg = beg;
        this->len = len;
    }
}
double& Indexer::operator[](int ind) {
    if (!IndexCheck(ind)) throw out_of_range("IndexOutOfRangeException");
    else return array1[ind + beg];
}
bool Indexer::IndexCheck(int ind)
{
    if (ind < 0 || ind + beg > len) return false;
    return true;
}
int main()
{
    double* array1 = new double[5]{ 1,2,3,4,5 };
    Indexer indexer1(array1, 1, 2, 5);
    Indexer indexer2(array1, 0, 2, 5);
    indexer1[0] = 100500;
    for (int i = 0; i < 5; i++) cout << indexer2[i] << " ";
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
