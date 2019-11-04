#include <iostream>
using namespace std;
class Vector {
	int n;
	int* p;
public:
	Vector(int n);
	void operator = (const Vector& vt);
	Vector operator + (Vector& vt);
	Vector operator - (Vector& vt);
	Vector operator * (Vector& vt);
	double operator ^(Vector& vt);
	int operator [](int k);
	friend istream& operator >> (istream& is, Vector& vt);
	friend ostream& operator << (ostream& os, Vector& vt);
};
