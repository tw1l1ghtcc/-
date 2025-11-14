#include<iostream>
using namespace std;
typedef struct sNode {
	int data;
	struct sNode* next;
}sNOde, * sLinklist; 
typedef struct dNode {
	int data;
	struct dNode* prev, * next;
}dNode,*dLinklist;
bool Initslist(sLinklist& L) {
	L = (sNode*)malloc(sizeof(sNode));
	if (L == NULL) {
		return false;
	}
	L->next = L;
	return true;
}
bool Initdlist(dLinklist& L) {
	L = (dNode*)malloc(sizeof(dNode));
	if (L == NULL) {
		return false;
	}
	L->next = L;
	L->prev = L;
	return true;
}
bool InsertNextdNode(dNode* p, dNode* s) {
	if (p == NULL || s == NULL) {
		return false;
	}
	s->next = p->next;
	s->prev = p;
	p->next->prev = s;
	p->next = s;
}
int main() {
	return 0;
}