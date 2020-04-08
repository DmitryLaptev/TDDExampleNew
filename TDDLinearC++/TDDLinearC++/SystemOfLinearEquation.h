#pragma once
#include "LinearEquation.h"
#include <string>
class SystemOfLinearEquation
{
private:
	vector<LinearEquation> listofcoef;
	int n;
public:
	SystemOfLinearEquation(int n1) :n(n1) {}
	~SystemOfLinearEquation() {}
	LinearEquation& operator[](int ind);
	void stepConvert();
	void AddLE(LinearEquation&);
	int size();
	vector<double> gaussMethod();
	operator string();
};

