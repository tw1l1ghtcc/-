#include<iostream>
using namespace std;
const int Max = 1000;
typedef struct Frame {
	int n;
	char from;
	char aux;
	char to;
	int state;
}Hanoi;
typedef struct Stack {
	Frame data[Max];
	int top;
};
void InitStack(Stack& s) {
	s.top = -1;
}
void Push(Stack& s, Frame f) {
	s.data[++s.top] = f;
}
Frame Pop(Stack& s) {
	return s.data[s.top--];
}
Frame& top(Stack& s) {
	return s.data[s.top];
}
int main() {
	int n;
	cin >> n;
	Stack st;
	InitStack(st);
	Frame start = { n,'a','b','c',0 };
	Push(st, start);
	while (st.top != -1) {
		Frame& cur = top(st);
		if (cur.n == 1) {
			cout << cur.from << "->" << cur.to << endl;
			Pop(st);
			continue;
		}
		if (cur.state == 0) {
			Frame f = { cur.n - 1,cur.from,cur.to,cur.aux,0 };
			cur.state = 1;
			Push(st, f);
		}
		else if (cur.state == 1) {
			cout << cur.from << "->" << cur.to << endl;
			cur.state = 2;
		}
		else if (cur.state == 2) {
			Frame f = { cur.n - 1,cur.aux,cur.from,cur.to,0 };
			cur.state = 3;
			Push(st, f);
		}
		else {
			Pop(st);
		}
	}
	return 0;
}
