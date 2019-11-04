#ifndef CTKH_H
#define CTKH_H
#include <string>
using namespace std;
class CongTrinhKhoaHoc {
	string id;
	int year;
	bool isForeign;
public:
	CongTrinhKhoaHoc();
	void setId(string id);
	void setYear(int year);
	void setIsForeign(bool isForeign);
	string getId();
	int getYear();
	bool getIsForeign();
	friend ostream& operator<<(ostream& os, CongTrinhKhoaHoc& ctkh);
	friend istream& operator>>(istream& is, CongTrinhKhoaHoc& ctkh);
};
#endif