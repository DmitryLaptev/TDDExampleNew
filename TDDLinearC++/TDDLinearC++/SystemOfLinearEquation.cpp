#include "SystemOfLinearEquation.h"
#include <stdexcept>
#include <iostream>
using namespace std;
int SystemOfLinearEquation::size() { return listofcoef.size(); }
LinearEquation& SystemOfLinearEquation::operator[](int ind) {
    if (ind < 0 || ind >= size()) throw out_of_range("Out Of Range");
    else return listofcoef[ind];
}
void SystemOfLinearEquation::stepConvert() {
    int step;
    int j, c;
    double step1, step2;
    for (int i = 0; i < size(); i++)
    {
        j = i;
        if (listofcoef[i][j] == 0)
        {
            while (listofcoef[i][j] == 0 && j < n) j++;
            step = 1;
            while (i + step < size() && listofcoef[i + step][j] == 0) step++;
            if (i + step == size()) return;
            c = listofcoef[i];
            listofcoef[i] = listofcoef[i + step];
            listofcoef[i + step] = c;
        }
        for (int k = i + 1; k < size(); k++)
        {
            LinearEquation a = listofcoef[j] * listofcoef[i][j];
            LinearEquation b = listofcoef[i] * listofcoef[k][j];
            listofcoef[k] = a - b;
        }
    }
}
vector<double> SystemOfLinearEquation::gaussMethod() {
    while (listofcoef[size() - 1].isEmpty()) listofcoef.pop_back();
    if (listofcoef[size() - 1])
    {
        if (size() == n)
        {
            vector<double> Gauss;
            for (int i = size() - 1; i >= 0; i--)
            {
                Gauss[i] = listofcoef[i][n];
                for (int j = i + 1; j < n; j++) Gauss[i] -= listofcoef[i][j] * Gauss[j];
                Gauss[i] /= listofcoef[i][i];
            }
            return Gauss;
        }
        else throw invalid_argument("Все коэффициенты равны нулю");
    }
    else throw new invalid_argument("Система не имеет решений");
}
SystemOfLinearEquation::operator string() {
    string s = "";
    for (int i = 0; i <size(); i++)
    {
        s += to_string(listofcoef[i]);
        s += "\n";
    }
    return s;
}
void SystemOfLinearEquation::AddLE(LinearEquation& a) {
    if (a.size() == n + 1) listofcoef.push_back(a);
    else throw invalid_argument("Invalid");
}