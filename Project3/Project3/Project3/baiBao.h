#include "ctkh.h"
#include <iostream>
#include <string>
class baiBao:public CongTrinhKhoaHoc{
	string name;
	int auThors;
public:
	baiBao();
	~baiBao();
	void setName(string name);
	void setauThors(int auThors);
	string getName();
	int getauThors();
	friend ostream& operator<<(ostream& os, baiBao& bb);
	friend istream& operator>>(istream& is, baiBao& bb);
};

