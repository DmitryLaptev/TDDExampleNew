#include "LinearEquation.h"
#include <vector>
#include <stdexcept>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
LinearEquation::LinearEquation(vector<double> v) {
	listofcoef = v;
}
LinearEquation::LinearEquation(string s) {
	for (int i = 0; i < size(); i++) {
		if (s[i] != ' ') listofcoef.push_back(s[i]);
	}
}
LinearEquation::LinearEquation(double n) {
	listofcoef.resize(n + 1);
}
int LinearEquation::size() { return listofcoef.size(); }
void LinearEquation::input(double x) {
	for (int i = 0; i < size(); i++) {
		listofcoef[i] = x;
	}
}
void LinearEquation::randomInput() {
	srand(time(NULL));
	for (int i = 0; i < size(); i++) {
		listofcoef[i] = rand() % 100;
	}
}
bool LinearEquation::isEmpty() {
	for (int i = 0; i < size(); i++)
	{
		if (listofcoef[i] != 0) return false;
	}
	return true;
}
bool operator==(LinearEquation& a, LinearEquation& b) {
	for (int i = 0; i < a.size(); i++) {
		if (abs(b[i] - a[i]) > 0.000000001) return false;
	}
	return true;
}
bool operator!=(LinearEquation& a, LinearEquation& b) {
	return !(a == b);
}
double& LinearEquation::operator[](int ind) {
	if (ind < 0 || ind >= size()) throw out_of_range("Out Of Range");
	else return listofcoef.at(ind);
}
LinearEquation::operator bool() {
	for (int i = 0; i < size() - 1; i++) {
		if (listofcoef[i] != 0) return true;
	}
	if (listofcoef[size() - 1] == 0) return true;
	else return false;
}
LinearEquation LinearEquation::operator+(LinearEquation& a) {
	vector<double> result = listofcoef;
	for (int i = 0; i < size(); i++) result[i] += a[i];
	return LinearEquation(result);
}
LinearEquation LinearEquation::operator-(LinearEquation& a) {
	vector<double> result = listofcoef;
	for (int i = 0; i < size(); i++) result[i] -= a[i];
	return LinearEquation(result);
}
LinearEquation LinearEquation::operator*(const double& r) {
	vector<double> result = listofcoef;
	for (int i = 0; i < size(); i++) result[i] *= r;
	return LinearEquation(result);
}
LinearEquation LinearEquation::operator-() {
	vector<double> result = listofcoef;
	for (int i = 0; i < size(); i++) result[i] *= (-1);
	return LinearEquation(result);
}
LinearEquation::operator std::string() {
	string s = "";
	int i;
	for (i = 0; i < size() - 2; i++)
	{
		if (listofcoef[i + 1] >= 0)
		{
			s += to_string(listofcoef[i]) + 'x' + to_string(i + 1) + '+';
		}
		else s += to_string(listofcoef[i]) + 'x' + to_string(i + 1);
	}
	s += s += to_string(listofcoef[i]) + 'x' + to_string(i + 1);
	s += '=' + to_string(listofcoef[size() - 1]);
	return s;
}
