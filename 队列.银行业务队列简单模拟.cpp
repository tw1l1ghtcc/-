#include<iostream>
using namespace std;
typedef struct QNode {
	int data;
	QNode* next;
}QNode;
typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;
void InitQueue(Queue& q) {
	q.front = q.rear = NULL;
}
void EnQueue(Queue& q, int e) {
	QNode* s = (QNode*)malloc(sizeof(QNode));
	s->data = e;
	s->next = NULL;
	if (q.front == NULL) {
		q.front = q.rear = s;
	}
	else {
		q.rear->next = s;
		q.rear = s;
	}
}
int DeQueue(Queue& q) {
	QNode* p = q.front;
	int x = p->data;
	q.front = p->next;
	if (q.front == NULL) {
		q.rear = NULL;
	}
	free(p);
	return x;
}
bool IsEmpty(Queue& q) {
	return q.front == NULL;
}
int main() {
	int n;
	cin >> n;
	Queue qa;
	Queue qb;
	InitQueue(qa);
	InitQueue(qb);
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		if (x % 2 == 0) {
			EnQueue(qb, x);
		}
		else {
			EnQueue(qa, x);
		}
	}
	bool first = true;
	while (!IsEmpty(qa) || !IsEmpty(qb)) {
		for (int i = 0; i < 2; i++) {
			if (!IsEmpty(qa)) {
				if (!first) {
					cout << " ";
				}
				cout << DeQueue(qa);
				first = false;
			}
		}
		if (!IsEmpty(qb)) {
			if (!first) {
				cout << " ";
			}
			cout << DeQueue(qb);
			first = false;
		}
	}
	return 0;
}