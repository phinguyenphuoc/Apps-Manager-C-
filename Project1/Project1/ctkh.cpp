#include <iostream>
#include "ctkh.h"
using namespace std;
CongTrinhKhoaHoc::CongTrinhKhoaHoc() {
	this->id = "";
	this->year = 0;
	this->isForeign = 0;
}
void CongTrinhKhoaHoc::setId(string id) {
	this->id = id;
}
void CongTrinhKhoaHoc::setYear(int year) {
	this->year = year;
}
void CongTrinhKhoaHoc::setIsForeign(bool isForeign) {
	this->isForeign = isForeign;
}
string CongTrinhKhoaHoc::getId() {
	return id;
}
int CongTrinhKhoaHoc::getYear() {
	return year;
}
bool CongTrinhKhoaHoc::getIsForeign() {
	return isForeign;
}
istream& operator>>(istream& is, CongTrinhKhoaHoc& ctkh) {
	cout << "Id: ";
	is >> ctkh.id;
	cout << "Nam xuat ban: ";
	is >> ctkh.year;
	while (ctkh.getYear() < 1900 || ctkh.getYear() > 2018) {
		cout << "nam khong hop le, vui long nhap lai nam:" << endl;
		is >> ctkh.year;
	}
	cout << "Ma vung(0,1): ";
	is >> ctkh.isForeign;
	return is;
}
ostream& operator<<(ostream& os, CongTrinhKhoaHoc& ctkh) {
	cout << "Id: ";
	os << ctkh.getId() << endl;
	cout << "Nam xuat ban: ";
	os << ctkh.getYear() << endl;
	cout << "Ma vung: ";
	/*os << ctkh.getIsForeign() << endl;*/
	if (ctkh.getIsForeign() == 1) {
		os << "nuoc ngoai";
	}else os << "trong nuoc";
	return os;
}
