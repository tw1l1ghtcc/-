#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef struct Node {
	int data;
	string next;
	string addr;
}Node;//创建链表
int change(string add) {
	int sum = 0;
	if (add == "-1") {
		return -1;
	}
	for (int i = 0; i < 5; i++) {
		sum = sum * 10 + (add[i] - '0');
	}
	return sum;
}//地址转换函数
void traverse(Node* L, string Iniadd, int n) {
	int curraddr = change(Iniadd);
	static int order[100000];
	int len = 0;
	while (curraddr != -1) {
		order[len++] = curraddr;
		curraddr = change(L[curraddr].next);
	}
	int left = 0, right = len - 1;
	bool takeRight = true;
	int prevaddr = -1;
	while (left <= right) {//双指针重排链表
		int curr;
		if (takeRight) {
			curr = order[right--];//先取右边
		}
		else {
			curr = order[left++];
		}
		if (prevaddr != -1) {
			L[prevaddr].next = L[curr].addr;
		}
		prevaddr = curr;
		takeRight = !takeRight;
	}
	L[prevaddr].next = "-1";//设置最后一个节点指向-1
	int add = order[len - 1];
	for (int i = 0; i < len; i++) {
		cout << L[add].addr << " " << L[add].data << " " << L[add].next << endl;
		add = change(L[add].next);
	}
}
int main() {
	static Node L[100000];
	int  n;
	string Iniadd;
	cin >> Iniadd >> n;
	for (int i = 0; i < n; i++) {
		string add, nextadd;
		int data;
		cin >> add >> data >> nextadd;
		L[change(add)].data = data;
		L[change(add)].next = nextadd;
		L[change(add)].addr = add;
	}
	traverse(L, Iniadd, n);
	return 0;
}

