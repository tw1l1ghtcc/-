#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
}Node,*Linklist;
bool Insertnextnode(Node* p, int e);
bool Inilist(Linklist& L) {
	L = (Node*)malloc(sizeof(Node));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}
bool Empty(Linklist L) {
	return (L == NULL);
}
bool Listinsert(Linklist& L, int i, int e) {
	if (i < 1) {
		return false;
	 }
	Node* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	return Insertnextnode(p, e);
}
bool Insertnextnode(Node* p, int e) {
	if (p == NULL) {
		return false;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p -> next = s;
	return true;
}      
bool Insertpriornode(Node* p, int e) {
	if (p == NULL) {
		return false;
	}
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = p->data;
	p->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool Deletenextnode(Node* p, int& e);
bool  Deletenode(Linklist& L, int i, int& e) {
	if (i < 1) {
		return false;
	}
	Node* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	return Deletenextnode(p, e);
	
}
bool Deletenextnode(Node* p,int &e) {
	if (p == NULL || p->next == NULL) {
		return false;
	}
	Node* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
	
}
bool DeleteNode(Node* p) {
	if (p == NULL) {
		return false;
	}
	Node* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}
Node* Getelem(Linklist L, int i) {
	if (i < 0) {
		return NULL;
	}
	int j = 0;
	Node* p = L;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
Node* Locateelem(Linklist L, int e) {
	Node* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;
}
int Length(Linklist L) {
	int len = 0;
	Node* p = L;
    while(p->next != NULL){
		p = p->next;
		len++;
	}
	return len;
}
Linklist List_Tailinsert(Linklist& L) {
	int x = 0;
	cin >> x;
	Node* s, * r = L;
	while (x != 9099) {
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	return L;
}
Linklist List_Headinsert(Linklist &L){
	int x = 0;
	Node* s;
	cin >> x;
	while (x != 999) {
		s = (Node*)malloc(sizeof(Node));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}
void showlist(Linklist L) {
	Node* p = L;
	while (p->next != NULL) {
		p = p->next;
		cout << p->data << endl;
	}
}
int main() {
	Linklist L;
	Inilist(L);
	List_Headinsert(L);
	showlist(L);
	
	
	return 0;
}