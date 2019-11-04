#include "ListCTKH.h"
#include <iostream>
#include <string>
using namespace std;
bool ascending(int left, int right) {
	return left > right;
}
bool descending(int left, int right) {
	return left < right;
}
int main() {
	ListCTKH l;
	int i = 1;
	Node nodeFirst, nodeLast, nodeAtPosition;
	cout << "Khoi tao danh sach cong trinh khoa hoc" << endl;
	cin >> l;
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
				nodeFirst = l.creatNode();
				l.insertFirst(&nodeFirst);
				cout << "*********" << endl;
				break;
			case 3:
				nodeLast = l.creatNode();
				l.insertLast(&nodeLast);
				cout << "*********" << endl;
				break;
			case 4:
				int postion;
				cout << "Nhap vi tri muon them vao: ";
				cin >> postion;
				nodeAtPosition = l.creatNode();
				l.insertAtPosition(&nodeAtPosition,postion);
				cout << "*********" << endl;
				break;
			case 5:
				l.delFirst();
				break;
			case 6:
				l.delLast();
				break;
			case 7:
				int postionDel;
				cout << "Nhap vi tri muon xoa: ";
				cin >> postionDel;
				l.delAtPosition(postionDel);
				break;
			case 8:
				int yearUpdate;
				cout << "Nhap nam CTKH ban muon update lai thong tin: ";
				cin >> yearUpdate;
				l.update(yearUpdate);
				break;
			case 9:
				int yearFind;
				cout << "Nhap nam CTKH ban muon tim kiem: ";
				cin >> yearFind;
				cout << "Vi tri: ";
				cout << l.find(yearFind) << endl;
				break;
			case 10:
				int isDesc;
				cout << "1: tang dan / 0: giam dan :";
				cin >> isDesc;
				if (isDesc==1) {
					l.bubleShort(ascending);
				}
				else {
					l.bubleShort(descending);
				}
				break;
			}
		}
	}
	system("pause");
	return 0;
}