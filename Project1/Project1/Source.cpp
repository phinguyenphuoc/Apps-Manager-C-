#include <iostream>
#include "list.h"
#include <string>
bool ascending(int left, int right) {
	return left > right;
}
bool descending(int left, int right) {
	return left < right;
}

int main() {
	CongTrinhKhoaHoc ctkh, ctkh2;
	int n, i = 1, k, y;
	cout << "Khoi tao danh sach cong trinh khoa hoc" << endl;
	cout << "Nhap so luong cong trinh khoa hoc: " << endl;
	cin >> n;
	list l(n), l2(0);
	l.creat();
	while (i != 0) {
		cout << "1.Hien thi danh sach cong trinh khoa hoc" << endl;
		cout << "2.Them cong trinh khoa hoc vao vi tri dau tien" << endl;
		cout << "3.Them cong trinh khoa hoc vao vi tri cuoi cung" << endl;
		cout << "4.Them cong trinh khoa hoc vao vi tri bat ki" << endl;
		cout << "5.Xoa cong trinh khoa hoc o vi tri dau tien" << endl;
		cout << "6.Xoa cong trinh khoa hoc o vi tri cuoi cung" << endl;
		cout << "7.Xoa cong trinh khoa hoc o vi tri bat ki" << endl;
		cout << "8.Cap nhat thong tin cong trinh khoa hoc" << endl;
		cout << "9.Tim kiem (theo nam xuat ban)" << endl;
		cout << "10.Sap xep danh sach cong trinh khoa hoc" << endl;
		cout << "Exit: Nhap phim bat ki khac danh sach tren" << endl;
		cout << "=================================" << endl;
		cout << "Nhap Lenh: " << endl;
		cin >> i;
		if (i < 1 || i>10) {
			break;
		}
		else {
			switch (i)
			{
				case 1:
					cout << l;
					cout << "*********" << endl;
					break;
				case 2:
					cin >> ctkh;
					l.addFirst(ctkh);
					cout << "*********" << endl;
					break;
				case 3:
					cin >> ctkh;
					l.addLast(ctkh);
					cout << "*********" << endl;
					break;
				case 4:
					cout << "Nhap vi tri muon them vao: " << endl;
					cin >> k;
					cout << "Nhap cong trinh khoa hoc muon them vao: " << endl;
					cin >> ctkh;
					l.add(ctkh, k);
					cout << "*********" << endl;
					break;
				case 5:
					l.delFirst();
					cout << "*********" << endl;
					break;
				case 6:
					l.delLast();
					cout << "*********" << endl;
					break;
				case 7:
					cout << "Nhap vi tri cong trinh khoa hoc can xoa: " << endl;
					cin >> k;
					l.del(k);
					cout << "*********" << endl;
					break;
				case 8:
					cout << "Nhap vao cong trinh khoa hoc can thay doi (chi thay doi id va ma vung):  " << endl;
					cin >> ctkh;
					l.update(ctkh);
					cout << "*********" << endl;
					break;
				case 9:
					l.shellShort(ascending);
					cout << "Nhap nam xuat ban cua cong trinh khoa hoc can tim: " << endl;
					cin >> y;
					l2 = l.find(y);
					cout << l2;
					cout << "*********" << endl;
					break;
				case 10:
					int j;
					cout << "1: tang dan" << endl;
					cout << "2: giam dan" << endl;
					cin >> j;
					if (j == 1) {
						l.shellShort(ascending);
					}
					else l.shellShort(descending);
					cout << "*********" << endl;
					break;
			}
		}
	}
	system("pause");
	return 0;
}