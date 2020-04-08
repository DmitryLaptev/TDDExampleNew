#pragma once
class Indexer
{
private:
	double* array1;
	int beg;
	int len;
	bool IndexCheck(int ind);
public:
	int n = 4;
	int getLength() {
		return len;
	}
	Indexer(double* array, int beg, int end, int len);
	~Indexer() {}
	double& operator[](int ind);
};

