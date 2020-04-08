#pragma once
#include <vector>
#include <string>
using namespace std;
class LinearEquation
{
private:
	vector<double> listofcoef;
public:
	LinearEquation(vector<double>);
	LinearEquation(string s);
	LinearEquation(double x);
	int size();
	~LinearEquation() {};
	bool isEmpty();
	void input(double);
	void randomInput();
	double& operator[](int ind);
	LinearEquation operator+(LinearEquation&);
	LinearEquation operator-(LinearEquation&);
	LinearEquation operator*(const double&);
	LinearEquation operator-();
	operator std::string();
	operator bool();
};

