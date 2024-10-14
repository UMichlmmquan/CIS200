#include <iostream>

using namespace std;

struct NodeType {
	int data;
	NodeType* link;
};

int main() {
	NodeType* p;
	NodeType* q;

	p = new NodeType;
	q = new NodeType;

	p->data = 12;
	q->data = 5;

	p->link = NULL;
	q->link = p;

	cout << p->data << endl;
	cout << q->data << endl;

	return 0;
}