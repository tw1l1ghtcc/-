#include<iostream>
using namespace std;
const int maxsize = 10000 + 5;
const long Maxsize = 100000;
typedef struct Stack {
	int data[maxsize];
	int top;
}goods;
void Initstack(goods &g) {
	g.top = -1;
}
void Push(goods& g, int e) {
	if (g.top >= maxsize-1) {
		return;
	}
	g.data[++g.top] = e;
}
int Pop(goods& g) {
	if (g.top != -1) {
		return g.data[g.top--];
	}
	return 0;
}
void store(goods *g,int *arr,int *st,int n,int s){
	for (int i = 0; i < n / s; i++) {
		for (int j = i*s; j < i*s+s; j++) {
			int t = arr[j];
			st[t] = Pop(g[i]);
		}
	}
}
int main() {
	int n, s;
	cin >> n >> s;
	int *num = (int*)malloc(sizeof(int)*maxsize);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		num[i] = temp;
	}
	goods* g = (goods*)malloc(sizeof(goods) * 101);
	for (int i = 0; i < n/s; i++) {
		Initstack(g[i]);
		for (int j = 0; j < s; j++) {
			int temp;
			cin >> temp;
			Push(g[i], temp);
		}
	}
	int *st = (int*)malloc(sizeof(int)*Maxsize);
	store(g, num, st, n, s);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (num[j] == temp) {
				cout << st[num[j]]<<endl;
				flag++;
			}
		}
		if (!flag) {
			cout << " Wrong Number" << endl;
		}
	}
	free(num);
	free(st);
	free(g);
	return 0;
}