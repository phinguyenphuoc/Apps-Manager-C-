#include "baiBao.h"
baiBao::baiBao(){
	this->name = "";
	this->auThors = 0;
}
baiBao::~baiBao(){
}
void baiBao::setName(string name) {
	this->name = name;
}
void baiBao::setauThors(int auThors) {
	this->auThors = auThors;
}
string baiBao::getName() {
	return this->name;
}
int baiBao::getauThors() {
	return this->auThors;
}
istream& operator>>(istream& is, baiBao& bb) {
	is >> (CongTrinhKhoaHoc&)bb;
	cout << "Ten: ";
	is >> bb.name;
	cout << "So luong tac gia :";
	is >> bb.auThors;
	return is;
}
ostream& operator<<(ostream& os, baiBao& bb) {
	os << (CongTrinhKhoaHoc&)bb;
	os << "Ten: ";
	os << bb.getName() << endl;
	os << "So luong tac gia: ";
	os << bb.getauThors() << endl;
	return os;
}
