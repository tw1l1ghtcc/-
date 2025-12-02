#include<iostream>
using namespace std;
const int maxsize = 1000;
typedef struct {
	int num[maxsize];
	int  top;
}num;
typedef struct {
	char op[maxsize];
	int top;
}op;
void InitStack(num& n) {
	n.top = -1;
}
void Push(num& n,int e) {
	n.top++;
	n.num[n.top] = e;

}
void Initstack(op& n) {
	n.top = -1;
}
void Push(op& n, char e) {
	n.top++;
	n.op[n.top] = e;

}
int Pop(num& n) {
	int e = n.num[n.top];
	n.top--;
	return e;
}
char Pop(op& n) {
	char e = n.op[n.top];
	n.top--;
	return e;
}
int calc(int a, int b, char x,int &boo) {
	if (x == '+') {
		return b + a;
	}
	if (x == '-') {
		return b - a;
	}
	if (x == '*') {
		return b * a;
	}
	if (x == '/') {
		if (a == 0) {
			boo = 0;
			return b;
		}
		return b / a;
	}
}
int ans(op &o,num &n,int &boo){
	while (n.top != 0) {
		boo = 1;
		int e = calc(Pop(n), Pop(n), Pop(o),boo);
		if (!boo) {
			cout << "ERROR: " << e << "/0"<<endl;
			return 0;
		}

		Push(n, e);
	}
	return Pop(n);

}
int main() {
	int n;
	cin >> n;
	num nu;
	op o;
	int boo = 1;
	InitStack(nu);
	Initstack(o);
	for (int i = 0; i < n; i++) {
		int e = 0;
		cin >> e;
		Push(nu, e);
	}
	for (int i = 0; i < n - 1; i++) {
		char e;
		cin >> e;
		Push(o, e);
	}
	int an =ans(o, nu,boo);
	if (boo) {
		cout << an << endl;
	}
	return 0;
}