#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix(int row, int col){
	this->row = row;
	this->col = col;
	p = new int*[row];
		for (int i = 0; i < row; i++) {
			p[i] = new int[col];
		}
}
void Matrix::operator = (const Matrix & mt) {
	if (this != &mt) {
		for (int i = 0; i < row; i++) {
			delete[] p[i];
		}
		delete[] p;
		this->row = mt.row;
		this->col = mt.col;
		p = new int*[row];
		for (int i = 0; i < row; i++) {
			p[i] = new int[col];
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				p[i][j] = mt.p[i][j];
			}
		}
	}
}
Matrix Matrix::operator + (Matrix & mt) {
	Matrix t(mt.row, mt.col);
	if (row != mt.row || col != mt.col) {
		cout << "khong the cong 2 ma tran khac so hang, so cot" << endl;
	}
	else {
		for (int i = 0; i < mt.row; i++) {
			for (int j = 0; j < mt.col; j++) {
				t.p[i][j] = p[i][j]+mt.p[i][j];
			}
		}
	}
	return t;
}
Matrix Matrix::operator - (Matrix & mt) {
	Matrix t(mt.row, mt.col);
	if (row != mt.row || col != mt.col) {
		cout << "khong the tru 2 ma tran khac so hang, so cot" << endl;
	}
	else {
		for (int i = 0; i < mt.row; i++) {
			for (int j = 0; j < mt.col; j++) {
				t.p[i][j] = p[i][j] - mt.p[i][j];
			}
		}
	}
	return t;
}
Matrix  Matrix::operator * (Matrix & mt) {
	Matrix t(row, mt.col);
	int s;
	if (col != mt.row) {
		cout << "Khong the nhan 2 ma tran nay" << endl;
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < mt.col; j++) {
				s = 0;
				for (int k = 0; k < col; k++) {
					s = s + p[i][k] * mt.p[k][j];
				}
				t.p[i][j] = s;
			}
		 }
	}
	return t;

}
int Matrix::operator ()(int row, int col){
	return p[row][col];
}
istream& operator >> (istream& is, Matrix& mt) {
	for (int i = 0; i < mt.row; i++) {
		for (int j = 0; j < mt.col; j++) {
			is >> mt.p[i][j];
		}
	}
	return is;
}
ostream& operator << (ostream& os, Matrix& mt) {
	for (int i = 0; i < mt.row; i++) {
		for (int j = 0; j <mt.col; j++) {
			os << mt.p[i][j] << " ";
		}
		cout << endl;
	}
	return os;
}



