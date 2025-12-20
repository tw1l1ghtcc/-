#include<iostream>
#include<string>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef struct Stack {
	struct Node* top;
}Stack;
void InitStack(Stack& s) {
	Node* p = new Node;
	p->next = NULL;
	s.top = p;
}
void Push(Stack& s, int e) {
	Node* p = new Node;
	p->data = e;
	p->next = s.top->next;
	s.top->next = p;
}
int Pop(Stack& s) {
	if (s.top->next == NULL) {
		return -1;
	}
	Node* p = s.top->next;
	s.top->next = p->next;
	int e = p->data;
	delete p;
	return e;
}
bool judge(Stack& s, int* in, int* out, string* str,int n) {
	int i = 0,o = 0,st = 0;
	while (o<n) {
		if (s.top->next != NULL && s.top->next->data == out[o]) {
			Pop(s);
			str[st++] = "out";
			o++;
		}
		else if (i < n) {
			Push(s, in[i++]);
			str[st++] = "in";
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	Stack s;
	InitStack(s);
	string in1;
	string out1;
	int in[20];
	int out[20];
	cin >> in1;
	cin >> out1;
	for (int i = 0; i < n; i++) {
		in[i] = in1[i] - '0';
		out[i] = out1[i] - '0';
	}
	string str[40];
	if (judge(s, in, out, str, n)) {
		cout << "Yes" << endl;
		for (int i = 0; i < 2 * n; i++) {
			cout << str[i] << endl;
		}
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}
