#include <iostream>
using namespace std;
class Polynomial{
	int n;
	int *p;
public:
	Polynomial(int n);
	void operator = (const Polynomial & pl);
	Polynomial operator + (Polynomial & pl);
	Polynomial operator - (Polynomial & pl);
	Polynomial operator * (Polynomial & pl);
	int operator [](int k);
	int operator ()(int k);
	friend istream& operator >> (istream& is, Polynomial& pl);
	friend ostream& operator << (ostream& os, Polynomial& pl);
};

