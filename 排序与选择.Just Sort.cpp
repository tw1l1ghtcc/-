#include<iostream>
using namespace std;
const int MAX = 100005;
int partition(int* a, int l, int r) {
	int p = a[l + (r - l) / 2];
	int i = l - 1;
	int j = r + 1;
	while (true) {
		do { i++; } while (a[i] < p);
		do { j--; } while (a[j] > p);
		if (i >= j) {
			return j;
		}
		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
}
void quick_sort(int* a, int l, int r) {
	if (l >= r)return;
	int p = partition(a, l, r);
	quick_sort(a, l, p);
	quick_sort(a, p + 1, r);
}
bool Judge(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] <= a[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	int a[MAX];
	int b[MAX];
	int count = 0;
	int ans[MAX];
	bool IsZero[MAX];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			IsZero[i] = true;
		}
		else {
			IsZero[i] = false;
			a[count++] = x;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	quick_sort(a, 0, count - 1);
	quick_sort(b, 0, m - 1);
	int counta = 0;
	int countb = 0;
	for (int i = 0; i < n; i++) {
		if (IsZero[i]) {
			ans[i] = b[countb++];
		}
		else {
			ans[i] = a[counta++];
		}
	}
	if (Judge(ans, n)) {
		cout << ans[0];
		for (int i = 1; i < n; i++) {
			cout << " " << ans[i];
		}
	}
	else {
		cout << "-1";
	}


	return 0;
}