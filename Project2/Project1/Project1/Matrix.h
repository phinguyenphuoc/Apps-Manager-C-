#include <iostream>
using namespace std;
class Matrix{
	int row, col;
	int **p;
public:
	Matrix(int row, int col);
	void operator = (const Matrix & mt);
	Matrix operator + (Matrix & mt);
	Matrix operator - (Matrix & mt);
	Matrix  operator * (Matrix & mt);
	int operator ^(Matrix &mt);
	int operator ()(int row, int col);
	friend istream& operator >> (istream& is, Matrix& mt);
	friend ostream& operator << (ostream& os, Matrix& mt);
};

