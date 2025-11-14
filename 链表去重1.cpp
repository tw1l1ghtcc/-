#include<iostream>
#include<string>
#include<cmath>
using namespace std;
typedef struct Node {
	int data;
	string addr, next;
}Node;
int change(string a) {
	if (a == "-1") {
		return -1;
	}
	int i = 0;
	int sum = 0;
	while (a[i] != NULL) {
		sum = sum * 10 + (a[i++] - '0');
	}
	return sum;
}
void unique(Node* L, string Iniadd, int n, int* store, int& sum) {
	int add = change(Iniadd);
	if (add == -1 || add >= 100010 || add < 0) { // 初始地址无效直接返回
		sum = 0;
		return;
	}
	sum = 0;
	bool seen[10001] = { false }; // 键值绝对值≤1e4，标记已出现的绝对值

	while (add != -1 && add < 100010) { // 遍历所有有效节点（包括尾节点）
		int dat_abs = abs(L[add].data);
		if (!seen[dat_abs]) {
			seen[dat_abs] = true; // 标记第一个出现的绝对值
			// 移动到下一个节点（作为新基准）
			int next_add = change(L[add].next);
			if (next_add == -1) break;
			add = next_add;
		}
		else {
			// 重复节点：记录并删除
			store[sum++] = add;
			// 找到前驱节点，修改其next（关键：删除当前重复节点）
			int prev = change(Iniadd);
			while (prev != -1 && prev < 100010) {
				int prev_next = change(L[prev].next);
				if (prev_next == add) { // 找到前驱节点
					L[prev].next = L[add].next; // 跳过当前重复节点
					break;
				}
				prev = prev_next;
			}
			// 移动到下一个节点（继续检查重复）
			add = change(L[add].next);
		}
	}
}

void traverseDeleted(Node* L, int* store, int sum) {
	// 重构链接：逐个设置上一个节点的next为下一个节点的addr
	for (int i = 0; i < sum; i++) {
		int curr_idx = store[i];
		// 不是最后一个节点：next = 下一个被删除节点的addr
		if (i < sum - 1) {
			int next_idx = store[i + 1];
			L[curr_idx].next = L[next_idx].addr;
		}
		else {
			// 最后一个节点：next = "-1"
			L[curr_idx].next = "-1";
		}
		// 输出当前节点（已重构链接）
		cout << L[curr_idx].addr << " " << L[curr_idx].data << " " << L[curr_idx].next << endl;
	}
}
void traverse(Node *L, string Iniadd, int n) {
	int add = change(Iniadd);
	for (int i = 0; i < n; i++) {
		
		cout << L[add].addr << " " << L[add].data << " " << L[add].next << endl;
		add = change(L[add].next);
	}
}
int main() {
	static Node L[100010];
	string Iniadd;
	int n;
	cin >> Iniadd >> n;
	for (int i = 0; i < n; i++) {
		string add,nextadd;
		int dat;
		cin >> add >> dat >> nextadd;
		L[change(add)].addr = add;
		L[change(add)].data = dat;
		L[change(add)].next = nextadd;
	}
	static int store[100010];
	int sum;
	unique(L, Iniadd, n, store, sum);
	traverse(L, Iniadd, n-sum);
	traverseDeleted(L, store, sum);
	
	

	return 0;
}