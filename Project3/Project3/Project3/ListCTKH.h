#include "ctkh.h"
#include "baiBao.h"
#include "Sach.h"
#include <iostream>
#include <string>
using namespace std;
struct Node{
	CongTrinhKhoaHoc ctkh;
	baiBao inf1;
	Sach inf2;
	bool flag ; // Check if node is baiBao or Sach
	Node *next;
	Node *previous;
};

class ListCTKH{
	Node* head;
	Node* tail;
	string personalName;
	int quantity;
public:
	ListCTKH();
	~ListCTKH();
	bool isEmpty();
	int length();
	void insertFirst(Node *newNode);
	void insertLast(Node *newNode);
	void insertAtPosition(Node *newNode, int position);
	void delFirst();
	void delLast();
	void delAtPosition(int position);
	int getNodeYear(int position);
	void swapData(int left, int right);
	void bubleShort(bool(*comparisonFunc)(int, int));
	int find(int year);
	friend istream& operator>>(istream& is, Node& node);
	friend ostream& operator<<(ostream& os, ListCTKH& ctkh);
	friend istream& operator>>(istream& is, ListCTKH& ctkh);
	CongTrinhKhoaHoc& operator[](int position);
	Node creatNode();
	void update(int year);
};

