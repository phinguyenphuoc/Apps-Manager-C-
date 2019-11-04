#include <cmath>
#include <iostream>
#include "Vector.h"
using namespace std;
Vector::Vector(int n) {
	this->n = n;
	this->p = new int[n];
}
void Vector::operator=(const Vector& vt) {
	if (n != vt.n) {
		cout << "khong the gan 2 vector khac chieu" << endl;
	}
	else if(this != &vt){
		delete[]p;
		p = new int[n];
		for (int i = 0; i < n; i++) {
			p[i] = vt.p[i];
		}
	}
}
Vector Vector::operator+(Vector& vt) {
	Vector t(n);
	if (n != vt.n) {
		cout << "khong the cong 2 vector khac chieu" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			t.p[i] = p[i] + vt.p[i];
		}
	}
	return t;
}
Vector Vector::operator - (Vector& vt) {
	Vector t(n);
	if (n != vt.n) {
		cout << "khong the tru 2 vector khac chieu" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			t.p[i] = p[i] - vt.p[i];
		}
	}
	return t;
}
Vector Vector::operator * (Vector& vt) {
	Vector t(n);
	if (n != vt.n) {
		cout << "khong the nhan 2 vector khac chieu" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			t.p[i] = p[i] * vt.p[i];
		}
	}
	return t;
}
double Vector::operator ^(Vector& vt) {
	int k = 0;
	for (int i = 0; i < vt.n; i++) {
		k += vt.p[i] * vt.p[i];
	}
	return sqrt(k);
}
int Vector::operator [](int k) {
	return p[k];
}
istream& operator >> (istream& is, Vector& vt) {
	for (int i = 0; i < vt.n; i++) {
		is >> vt.p[i];
	}
	return is;
}
ostream& operator << (ostream& os, Vector& vt) {
	os << "(";
	for (int i = 0; i < vt.n; i++) {
		if (i == vt.n - 1) {
			os << vt.p[i];
		}
		else {
			os << vt.p[i] << " ";
		}
	}
	os << ")";
	return os;
}
