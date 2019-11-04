#include "ListCTKH.h"
using namespace std;
ListCTKH::ListCTKH(){
	this->personalName = "";
	this->quantity = 0;
	head = NULL;
	tail = NULL;
}
ListCTKH::~ListCTKH(){
}
bool ListCTKH::isEmpty() {
	if (head == NULL){
		return true;
	}
	else {
		return false;
	}
}
int ListCTKH::length() {
	int length = 0;
	Node *current = head;
	do {
		length++;
		current = current->next;
	} while (current != head);
	return length;
}
void ListCTKH::insertFirst(Node *newNode) {
	newNode->next = NULL;
	newNode->previous = NULL;
	if (isEmpty()) {
		tail = newNode;
		head = newNode;
		tail->previous = head;
		tail->next = head;
		head->next = tail;
		head->previous = tail;
	}
	else {
		head->previous = newNode;
		tail->next = newNode;
		newNode->next = head;
		newNode->previous = tail;
		head = newNode;
	}
}
void ListCTKH::insertLast(Node *newNode) {
	newNode->next = NULL;
	newNode->previous = NULL;
	if (isEmpty()) {
		tail = newNode;
		head = newNode;
		tail->previous = head;
		tail->next = head;
		head->next = tail;
		head->previous = tail;
	}
	else {
		head->previous = newNode;
		tail->next = newNode;
		newNode->next = head;
		newNode->previous = tail;
		tail = newNode;
	}
}
void ListCTKH::insertAtPosition(Node *newNode, int position) {
	int l = length();
	if (position == 1) {
		insertFirst(newNode);
	}
	else if(position == (l+1)){
		insertLast(newNode);
	}
	else if(position > 1 && position <= l) {
		int halflength = l / 2;
		// chon cach duyet nhanh nhat
		if (position < halflength) {
			Node *current = head;
			int i = 1;
			while (i != position - 1) {
				current = current->next;
				i++;
			}
			newNode->next = current->next;
			newNode->previous = current;
			current->next = newNode;
			current = newNode->next;
			current->previous = newNode;
		}else {
			Node *current = tail;
			int i = l;
			while (i != position){
				current = current->previous;
				i--;
			}
			newNode->next = current;
			newNode->previous = current->previous;
			current->previous = newNode;
			current = newNode->previous;
			current->next = newNode;
		}
	}
	else {
		cout << "Vi tri nhap khong hop le" << endl;
	}
}
void ListCTKH::delFirst() {
	Node *temp;
	if(isEmpty()==false){
		if (length() == 1) {
			head = NULL;
		}else{
		temp = head->next;
		//delete head;
		head = temp;
		head->previous = tail;
		tail->next = head;
		}
	}
}
void ListCTKH::delLast() {
	Node *temp;
	if (isEmpty() == false) {
		if (length() == 1) {
			head = NULL;
		}
		else {
			temp = tail->previous;
			//delete tail;
			tail = temp;
			tail->next = head;
			head->previous = tail;
		}
	}
}
void ListCTKH::delAtPosition(int position) {
	int l = length();
	if (position == 1) {
		delFirst();
	}
	else if (position == l){
		delLast();
	}
	else if (position > 1 && position < l ) {
		Node *tempBefore;
		Node *tempAfter;
		int halflength = l / 2;
		// chon cach duyet nhanh nhat
		if (position < halflength) {
			Node *current = head;
			int i = 1;
			for (i; i < position; i++) {
				current = current->next;
			}
			tempBefore = current->previous;
			tempBefore->next = current->next;
			tempAfter = current->next;
			tempAfter->previous = current->previous;
			//delete current;
		}
		else {
			Node *current = tail;
			int i = l;
			for (i; i > position; i--) {
				current = current->previous;
			}
			tempBefore = current->previous;
			tempBefore->next = current->next;
			tempAfter = current->next;
			tempAfter->previous = current->previous;
			//delete current;
		}
	}
	else
	{
		cout << "Vi tri khong hop le: " << endl;
	}
}
void ListCTKH::swapData(int left, int right) {
	int l = length();
	if ((left >= 1 && left <= l) && (right >= 1 && right <= l)) {
		Node *leftNode = head;	
		Node *rightNode = tail;
		for (int i = 1; i < left; i++) {
			leftNode = leftNode->next;
		}
		for (int i = l; i > right; i--) {
			rightNode = rightNode->previous;
		}
		Node *temp = new Node();
		temp->inf1 = leftNode->inf1;
		temp->inf2 = leftNode->inf2;
		temp->flag = leftNode->flag;
		leftNode->inf1 = rightNode->inf1;
		leftNode->inf2 = rightNode->inf2;
		leftNode->flag = rightNode->flag;
		rightNode->inf1 = temp->inf1;
		rightNode->inf2 = temp->inf2;
		rightNode->flag = temp->flag;
	}
}
int ListCTKH::getNodeYear(int position) {
	Node *current = head;
	int year;
	for (int i = 1; i < position; i++) {
		current = current->next;
	}
	if (current->inf1.getYear() != NULL) {
		return year = current->inf1.getYear();
	}
	else {
		return year = current->inf2.getYear();
	}
}
void ListCTKH::bubleShort(bool(*comparisonFunc)(int, int)) {
	int l = length();
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j < l; j++) {
			if (comparisonFunc(getNodeYear(j),getNodeYear(j+1))) {
				swapData(j, j + 1);
			}
		}
	}
	
}
int ListCTKH::find(int year) {
	for (int i = 1; i <= length(); i++) {
		if (getNodeYear(i) == year)
			return i;
	}
	return 0;
}
istream& operator>>(istream& is, Node* node) {
	cout << "Bai bao (1) - Sach(0): ";
	is >> node->flag;
	if (node->flag == true) {
		baiBao bb;
		is >> bb;
		node->inf1 = bb;
	}
	else {
		Sach s;
		is >> s;
		node->inf2 = s;
	}
	return is;
}
istream& operator>>(istream& is, ListCTKH& ctkh) {
	baiBao bb;
	Sach s;
	cout << "Nhap ten list: ";
	is >> ctkh.personalName;
	cout << "Nhap so luong: ";
	is >> ctkh.quantity;
	for (int i = 0; i < ctkh.quantity; i++) {
		Node *newNode;
		newNode = new Node;
		is >> newNode;
		ctkh.insertLast(newNode);
	}
	return is;
}
ostream& operator<<(ostream& os, ListCTKH& ctkh) {
	Node *ptr = ctkh.head;
	int i = 1;
	if (ctkh.isEmpty() == false) {
		do {
			if (ptr->flag) {
				os << ptr->inf1 << endl;
			}
			else {
				os << ptr->inf2 << endl;
			}
			ptr = ptr->next;
		} while (ptr != ctkh.head);
	}
	else {
		os << "rong" << endl;
	}
	return os;
}
CongTrinhKhoaHoc& ListCTKH::operator[](int position) {
	int l = length();
	int halflength = l / 2;
	// chon cach duyet nhanh nhat
	if (position < halflength) {
		Node *current = head;
		for (int i = 1; i < position; i++) {
			current = current->next;
		}
		if (current->flag) {
			return current->inf1;
		}
		else {
			return current->inf2;
		}	
	}
	else {
		Node *current = tail;
		for (int i = l; i > position; i--) {
			current = current->previous;
		}
		if (current->flag) {
			return (baiBao&)current->inf1;
		}
		else {
			return (Sach&)current->inf2;
		}
	}
}
Node ListCTKH::creatNode() {
	Node *node;
	node = new Node();
	cin >> node;
	return *node;
}
void ListCTKH::update(int year) {
	int position = find(year);
	if (position == 0) {
		cout << "Khong tim thay nam" << endl;
	}
	else {
		Node *current = head;
		Node *temp;
		temp = new Node();
		for (int i = 1; i < position; i++) {
			current = current->next;
		}
		cin >> temp;
		current->inf1 = temp->inf1;
		current->inf2 = temp->inf2;
		current->flag = temp->flag;
	}
	
}
