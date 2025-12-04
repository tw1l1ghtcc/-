#include<iostream>
using namespace std;
const int Maxsize = 1001;
typedef struct Stack {
	int data[Maxsize];
	int top;
}Stack;
void InitStack(Stack& s) {
	s.top = 0;
	s.data[0] = 0;
}
void Push(Stack& s, int e) {
	if (s.top != Maxsize) {
		s.data[++s.top] = e;
	}
}
int Pop(Stack& s) {
	if (s.top != -1) {
		return s.data[s.top--];
	}
}
bool judge(int* arr,int m,int n) {
	Stack s;
	InitStack(s);
	int num = 1;
	for (int i = 0; i < n; i++) {
		while (s.data[s.top] < arr[i]) {
			if (s.top == m) {
				return false;
			}
			if (num > n) {
				return false;
			}
			Push(s, num++);
			
			
		}
		if (s.data[s.top] == arr[i]) {
			Pop(s);
		}
		if (s.data[s.top] > arr[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	int arr[Maxsize];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		if (judge(arr, m , n)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	return 0;
}