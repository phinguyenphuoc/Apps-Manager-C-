#ifndef LIST_H
#define LIST_H
#include "ctkh.h"
using namespace std;
class list {
	CongTrinhKhoaHoc *p;
	int n;
public:
	list(int n);
	void creat();
	void addFirst(CongTrinhKhoaHoc& ctkh);
	void addLast(CongTrinhKhoaHoc& ctkh);
	void add(CongTrinhKhoaHoc& ctkh, int k);
	void delFirst();
	void delLast();
	void del(int k);
	void update(CongTrinhKhoaHoc& ctkh);
	void shellShort(bool(*comparisonFunc)(int, int));
	int interpolationSearch(int x);
	list find(int x);
	void display();
	friend ostream& operator<<(ostream& os, list& l);
	CongTrinhKhoaHoc& operator[](int i);
};
#endif
