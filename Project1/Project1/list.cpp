#include "list.h"
#include <iostream>
list::list(int n) {
	this->n = n;
	this->p = new CongTrinhKhoaHoc[n];
}
void list::creat() {
	CongTrinhKhoaHoc ctkh;
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin ctkh " << (i + 1) << endl;
		cin >> ctkh;
		p[i] = ctkh;
	}
}
void list::addFirst(CongTrinhKhoaHoc& ctkh) {
	CongTrinhKhoaHoc *p1 = this->p;
	this->n++;
	this->p = new CongTrinhKhoaHoc[this->n];
	p[0] = ctkh;
	for (int i = 1; i < n; i++) {
		p[i] = p1[i - 1];
	}
}
void list::addLast(CongTrinhKhoaHoc& ctkh) {
	CongTrinhKhoaHoc *p1 = this->p;
	this->n++;
	this->p = new CongTrinhKhoaHoc[this->n];
	for (int i = 0; i < n - 1; i++) {
		p[i] = p1[i];
	}
	p[n - 1] = ctkh;
}
void list::add(CongTrinhKhoaHoc& ctkh, int k) {
	if (k > n || k <= 0) {
		cout << "vi tri khong hop le" << endl;
	}
	else {
		CongTrinhKhoaHoc *p1 = this->p;
		int i;
		this->n++;
		this->p = new CongTrinhKhoaHoc[this->n];
		p[0] = p1[0];
		--k;
		for (i = 1; i < k; i++) {
			p[i] = p1[i];
		}
		p[k] = ctkh;
		for (i = k + 1; i < n - 1; i++) {
			p[i] = p1[i - 1];
		}
		p[n - 1] = p1[n - 2];
	}
}

void list::delFirst() {
	for (int i = 0; i < n - 1; i++) {
		p[i] = p[i + 1];
	}
	n--;
}
void list::delLast() {
	n--;
}
void list::del(int k) {
	if (k > n || k <= 0) {
		cout << "vi tri khong hop le" << endl;
	}
	else {
		int i = 0;
		for (i = k - 1; i < n - 1; i++) {
			p[i] = p[i + 1];
		}
		n--;
	}
}
void list::update(CongTrinhKhoaHoc& ctkh) {
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (p[i].getYear() == ctkh.getYear()) {
			flag = true;
			p[i].setId(ctkh.getId());
			p[i].setIsForeign(ctkh.getIsForeign());
			break;
		}
	}
	if (flag == false) {
		cout << "khong tim thay doi tuong" << endl;
	}
}
void list::shellShort(bool(*comparisonFunc)(int, int)) {
	CongTrinhKhoaHoc temp;
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		for (int i = gap; i < n; i += 1) {
			temp = p[i];
			int j;
			//   for (j = i; j >= gap && p[j - gap].getYear() > temp.getYear(); j -= gap){
			for (j = i; j >= gap && comparisonFunc(p[j - gap].getYear(), temp.getYear()); j -= gap) {
				p[j] = p[j - gap];
			}
			p[j] = temp;
		}
	}
}
int list::interpolationSearch(int x) {
	int lo = 0, hi = (n - 1);
	while (lo <= hi && x >= p[lo].getYear() && x <= p[hi].getYear()) {
		int pos = lo + (((double)(hi - lo) / (p[hi].getYear() - p[lo].getYear()))*(x - p[lo].getYear()));
		if (p[pos].getYear() == x)
			return pos;
		if (p[pos].getYear() < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}
list list::find(int x) {
	list al(0);
	int pos = interpolationSearch(x);
	int pos1 = pos-1;
	do {
		al.addFirst(p[pos]);
		pos++;
	} while (p[pos].getYear() == x);
	while (p[pos1].getYear() == x) {
		al.addFirst(p[pos1]);
		pos1--;
	}
	return al;
}
void list::display() {
	cout << "n =" << this->n << endl;
	for (int i = 0; i < this->n; i++) {
		cout << p[i] << endl;
	}
}
ostream& operator<<(ostream& os, list& l) {
	for (int i = 0; i < l.n; i++) {
		os << l.p[i] << endl;
	}
	return os;
}
CongTrinhKhoaHoc& list::operator[](int i) {
	CongTrinhKhoaHoc temp;
	if (i >= 0 && i < n) {
		return p[i];
	}
}