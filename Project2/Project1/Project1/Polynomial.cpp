#include "Polynomial.h"
#include <iostream>
#include <cmath>
using namespace std;
Polynomial::Polynomial(int n){
	this->n = n;
	this->p = new int[n+1];
}
void Polynomial::operator = (const Polynomial & pl) {
	if (this != &pl) {
		delete[] p;
		this->n = pl.n;
		p = new int[n+1];
		for (int i = 0; i <= n; i++) {
			p[i] = pl.p[i];
		}
	}
}
Polynomial Polynomial::operator + (Polynomial & pl) {
	int max, min;
	bool flag;
	if (this->n > pl.n) {
		max = this->n;
		min = pl.n;
		flag = true;
	}
	else {
		max = pl.n;
		min = this->n;
		flag = false;
	}
	Polynomial t(max);
	int i = 0;
	while (i <= min) {
		t.p[i] = p[i]+pl.p[i];
		i++;
	}
	if (flag == true) {
		for (i = min + 1; i <= max; i++) {
			t.p[i] = p[i];
		}
	}
	else {
		for (i = min + 1; i <= max; i++) {
			t.p[i] = pl.p[i];
		}
	}
	return t;
}
Polynomial Polynomial::operator - (Polynomial & pl) {
	int max, min;
	bool flag;
	if (this->n > pl.n) {
		max = this->n;
		min = pl.n;
		flag = true;
	}
	else {
		max = pl.n;
		min = this->n;
		flag = false;
	}
	Polynomial t(max);
	int i = 0;
	while (i <= min) {
		t.p[i] = p[i] - pl.p[i];
		i++;
	}
	if (flag == true) {
		for (i = min + 1; i <= max; i++) {
			t.p[i] = p[i];
		}
	}
	else {
		for (i = min + 1; i <= max; i++) {
			t.p[i] = -pl.p[i];
		}
	}
	return t;
}
Polynomial Polynomial::operator * (Polynomial & pl) {
	int a = this->n + pl.n;
	Polynomial t(a);
	for (int i = 0; i <= a; i++) {
		t.p[i] = 0;
	}	
	for (int i = this->n; i >= 0; i--) {
		for (int j = pl.n; j >= 0; j--) {
			t.p[i + j] = t.p[i+j] + p[i] * pl.p[j];
		}
	}
	return t;
}
int Polynomial::operator [](int k) {
	return p[k];
}
int Polynomial::operator ()(int k) {
	int s = 0;
	for (int i = 0; i <= n; i++) {
		s = s + p[i] * (int)pow(k, i);
	}
	return s;
}
istream& operator >> (istream& is, Polynomial& pl) {
	for (int i = pl.n; i >= 0; i--) {
		is >> pl.p[i];
	}
	return is;
}
ostream& operator << (ostream& os, Polynomial& pl) {
	bool flag = false;
	int check = 0;
	int i = pl.n;
	if (pl.p[i] != 0) {
		flag = true;
		os << pl.p[i] << "x^" << i;
	}
	for (i = pl.n-1; i >= 0; i--) {
		if (pl.p[i] == 0) {
			check++;
			continue;
		}
		else if (i == 0) {
				if (pl.p[i] > 0) {
					os << "+" << pl.p[i];
				}
				else {
					os << pl.p[i];
				}
			}
			else {
				if (pl.p[i] < 0) {
					os << pl.p[i] << "x^" << i;
				}
				else {
					os << "+" << pl.p[i] << "x^" << i;
				}
			}
	}
	if (flag == false && check == (pl.n)) {
		os << "0";
	}
	return os;
}
