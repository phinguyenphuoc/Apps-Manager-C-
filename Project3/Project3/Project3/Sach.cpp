#include "Sach.h"
Sach::Sach(){
	this->category = "";
}
Sach::~Sach(){
}
void Sach::setCategory(string category) {
	this->category = category;
}
string Sach::getCategory() {
	return this->category;
}
istream& operator>>(istream& is, Sach& sach) {
	is >> (CongTrinhKhoaHoc&)sach;
	cout << "Nhap the loai: ";
	is >> sach.category;
	return is;
}
ostream& operator<<(ostream& os, Sach& sach) {
	os << (CongTrinhKhoaHoc&)sach;
	os << "The loai: ";
	os << sach.category << endl;
	return os;
}