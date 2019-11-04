#include "ctkh.h"
#include <string>
#include <iostream>
class Sach:public CongTrinhKhoaHoc {
	string category;
public:
	Sach();
	~Sach();
	void setCategory(string category);
	string getCategory();
	friend ostream& operator<<(ostream& os, Sach& sach);
	friend istream& operator>>(istream& is, Sach& sach);
};

