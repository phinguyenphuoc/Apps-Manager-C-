#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "Polynomial.h"
using namespace std;
int main() {
	// Chao thay, em chua lam duoc phan dinh thuc cua ma tran :)
	int m;
	do {
		cout << "------------------" << endl;
		cout << "Demo chuong trinh: " << endl;
		cout << "1.Vector" << endl;
		cout << "2.Matrix" << endl;
		cout << "3.Polynomicial" << endl;
		cout << "Exit:Nhap phim bat ki khac 1,2,3" << endl;
		cout << "Nhap: " << endl;
		cin >> m;
		switch (m) {
		case 1: {
			int n1, n2;
			cout << "Nhap chieu vecto 1: " << endl;
			cin >> n1;
			Vector vt1(n1);
			cout << "Nhap vector 1: " << endl;
			cin >> vt1;
			cout << "nhap chieu vecto 2: " << endl;
			cin >> n2;
			Vector vt2(n2);
			cout << "Nhap vector 2: " << endl;
			cin >> vt2;
			Vector vt3(n1);
			vt3 = vt1 + vt2;
			if (n1 == n2)
				cout << "tong 2 vecto: " << vt3 << endl;
			vt3 = vt1 - vt2;
			if (n1 == n2)
				cout << "hieu 2 vecto: " << vt3 << endl;
			vt3 = vt1 * vt2;
			if (n1 == n2)
				cout << "tich 2 vecto(.*): " << vt3 << endl;
			cout << "do dai vecto 1: ";
			cout << (vt1^vt1);
			cout << "\ndo dai vecto 2: ";
			cout << (vt2^vt2) << endl;
			for (int i = 0; i < n1; i++) {
				cout << "phan tu thu[" << i << "] cua vecto1 la: ";
				cout << vt1[i] << endl;
			}
			break;
		}
		case 2: {
			int r1, r2, c1, c2;
			cout << "nhap so hang ma tran 1: " << endl;
			cin >> r1;
			cout << "nhap so cot cua ma tran 1: " << endl;
			cin >> c1;
			Matrix mt1(r1, c1);
			cout << "Nhap ma tran 1 (trai->phai,tren->duoi): " << endl;
			cin >> mt1;
			cout << "nhap so hang ma tran 2: " << endl;
			cin >> r2;
			cout << "nhap so cot cua ma tran 2: " << endl;
			cin >> c2;
			Matrix mt2(r2, c2);
			cout << "Nhap ma tran 2 (trai->phai,tren->duoi): " << endl;
			cin >> mt2;
			Matrix mt3(0, 0);
			mt3 = mt1 + mt2;
			if (c1 == c2 && r1 == r2)
				cout << "Tong 2 ma tran: \n" << mt3 << endl;
			mt3 = mt1 - mt2;
			if (c1 == c2 && r1 == r2)
				cout << "Hieu 2 ma tran: \n" << mt3 << endl;
			mt3 = mt1 * mt2;
			if (c1 == r2)
				cout << "Tich cua 2 ma tran: \n" << mt3 << endl;
			for (int i = 0; i < r1; i++) {
				for (int j = 0; j < c1; j++) {
					cout << "phan tu [" << i << "][" << j << "] cua ma tran 1 la: ";
					cout << mt1(i, j) << endl;
				}
			}
			break;
		}
		case 3: {
			int n1, n2, x;
			cout << "Nhap bac cua da thuc 1: " << endl;
			cin >> n1;
			Polynomial pl1(n1);
			cout << "Nhap cac he so da thuc 1: " << endl;
			cin >> pl1;
			cout << "Nhap bac cua da thuc 2: " << endl;
			cin >> n2;
			Polynomial pl2(n2);
			cout << "Nhap he so da thuc 2: " << endl;
			cin >> pl2;
			cout << "Da thuc 1: " << pl1 << endl;
			cout << "Da thuc 2: " << pl2 << endl;
			Polynomial pl3(0);
			pl3 = pl1 + pl2;
			cout << "Tong cua hai da thuc la: " << pl3 << endl;
			pl3 = pl1 - pl2;
			cout << "Hieu cua hai da thuc la: " << pl3 << endl;
			pl3 = pl1 * pl2;
			cout << "Tich cua hai da thuc la: " << pl3 << endl;
			for (int i = 0; i <= n1; i++) {
				cout << "He so bac [" << i << "] cua da thuc 1 la: " << pl1[i] << endl;
			}
			cout << "Tinh gia tri cua da thuc 1, nhap x: " << endl;
			cin >> x;
			cout << "Ket qua: " << pl1(x) << endl;
		}

		default:
			break;
		}
	} while (m >= 1 && m <= 3);
	system("pause");
	return 0;
}
