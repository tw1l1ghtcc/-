#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next, * prev;
}Node,*Linklist;
bool Initlist(Linklist& L) {
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL) {
		return false;
	}
	L->prev = NULL;
	L->next = NULL;
	return true;
}
void testLinklist() {
	Linklist L;
	Initlist(L);
}
bool isEmpty(Linklist L) {
	if (L->next == NULL) {
		return true;
	}
	else return false;
}
bool InsertNextNode(Node* p, Node* s) {
	if (p == NULL || s == NULL) {
		return false;
	}
	s->next = p->next;
	if (p->next != NULL) {
		p->next->prev = s;
	}
	s->prev = p;
	p->next = s;
}

bool DeleteNextNode(Node* p) {
	if (p == NULL) {
		return false;
	}
	Node* s = p->next;
	if (s == NULL) {
		return false;
	}
	p->next = s->next;
	if (s->next != NULL) {
		s->next->prev = p;
	}
	free(s);
	return true;
}
void DestroyList(Linklist& L) {
	while (L->next != NULL) {
		DeleteNextNode(L);
	}
	free(L);
	L = NULL;
}
int main() {
	Linklist L;
	Node *T = (Node*)malloc(sizeof(Node));
	Initlist(L);
	InsertNextNode(L, T);
	cout << L->next->data;
	//±éÀú next: while(p != NULL) p = p->next;
	//±éÀú prev: while(p != NULL) p = p->prev;
	return 0;
}