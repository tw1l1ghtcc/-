#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
}Node, * Linklist;
bool InitList(Linklist& L) {
	L = (Node*)malloc(sizeof(Node));
	if (!L) {
		return false;
	}
	L->next = NULL;
	return true;
}
void List_Tailinsert(Linklist& L, int e) {
	Node* s = (Node*)malloc(sizeof(Node));  
	s->data = e;
	s->next = NULL;  

	Node* r = L;     
	while (r->next) {
		r = r->next;
	}
	r->next = s;     
}
bool empty(Linklist L);
void traverse(Linklist L) {
	Linklist p = L->next;
	if (empty(L)) {
		cout << "NULL";
		return;
	}
	while (p != NULL) {
		cout << p->data;
		if (p->next != NULL) {
			cout << " ";
		}
		p = p->next;
	}
	
}
Linklist merge(Linklist L, Linklist T) {
	Node* p = L->next;
	Node* q = T->next;
	Linklist S;
	InitList(S);
	int x = 0;
	while (p != NULL || q != NULL) {
		if (p != NULL && q != NULL) {
			if (p->data <= q->data) {
				x = p->data;
				p = p->next;
			}
			else {
				x = q->data;
				q = q->next;
			}
			List_Tailinsert(S, x);
		}
		else if (p != NULL && q == NULL) {
			x = p->data;
			p = p->next;
			List_Tailinsert(S, x);
		}
		else if (p == NULL && q != NULL) {
			x = q->data;
			q = q->next;
			List_Tailinsert(S, x);
		}

	}
	return S;
}
bool empty(Linklist L) {
	if (L->next == NULL) {
		return true;
	}
	return false;
}
int main() {
	Linklist L;
	InitList(L);
	Linklist T;
	InitList(T);
	int x = 0;
	while (true) {
		cin >> x;
		if (x == -1) {
			break;
		}
		List_Tailinsert(L, x);
	}
	while (true) {
		cin >> x;
		if (x == -1) {
			break;
		}
		List_Tailinsert(T, x);
	}
	Linklist S = merge(L, T);
	traverse(S);
	return 0;

}
