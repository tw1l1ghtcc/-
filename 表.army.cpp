#include<iostream>
using namespace std;

typedef struct Node {
	int army;
	struct Node* next;
}Node,*Linklist;
typedef struct region {
	Node* head;
	Node* tail;

}Region;
void InitRegion(Region &R) {
	Linklist L = new Node;
	L->next = NULL;
	R.head = L;
	R.tail = L;
}
void InsertTailNode(int e,Region &R) {
	Node* s = new Node;
	s->army = e;
	s->next = NULL;
	R.tail->next = s;
	R.tail = s;
}
void U(Region* r, int a, int b) {
	if (r[b].head->next == NULL) {
		return;
	}
	r[a].tail->next = r[b].head->next;
	r[a].tail = r[b].tail;
	r[b].head->next = NULL;
	r[b].tail = r[b].head;
}
void I(Region* r, int a, int x) {
	Node* p = new Node;
	p->army = x;
	p->next = r[a].head->next;
	r[a].head->next = p;
	if (r[a].head == r[a].tail) {
		r[a].tail = p;
	}
}
void D(Region* r, int a, int x) {
	if (r[a].head->next == NULL) {
		return;
	}
	Node* p = r[a].head;
	while (p->next != NULL) {
		if (p->next->army == x) {
			Node* q = p->next;
			p->next = q->next;
			if (q == r[a].tail) {
				r[a].tail = p;
			}
			delete q;
		}
		p = p->next;
	}
}
void Q(Region* r, int a) {
	if (r[a].head->next == NULL) {
		cout << "-1" << endl;
		return;
	}
	Node* p = r[a].head->next;
	while (p != NULL) {
		cout << p->army;
		if (p->next != NULL) {
			cout << " ";
		}
		p = p->next;
	}
	cout << endl;
}
int main() {
	int n, m;
	cin >> n >> m;
	int num = n;
	Region regions[1005];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		InitRegion(regions[i]);
		for (int j = 0; j < k; j++) {
			int army_num;
			cin >> army_num;
			InsertTailNode(army_num, regions[i]);
		}
	}
	for (int i = 0; i < m; i++) {
		char command;
		cin >> command;
		if (command == 'U') {
			int a, b;
			cin >> a >> b;
			U(regions, a, b);
		}else if (command == 'I') {
			int a, x;
			cin >> a >> x;
			I(regions, a, x);
		}
		else if (command == 'D') {
			int a, x;
			cin >> a >> x;
			D(regions, a, x);
		}
		else if (command == 'Q') {
			int a;
			cin >> a;
			Q(regions, a);

		}

	}
	return 0;
}