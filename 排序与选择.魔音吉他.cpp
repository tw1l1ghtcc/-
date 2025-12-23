#include<iostream>
using namespace std;
const int MAX = 100005;
void merge(long long* a, long long* temp, int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) / 2;
	merge(a, temp, l, mid);
	merge(a, temp, mid+1, r);
	int i = l;
	int j = mid + 1;
	int k = l;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (int t = l; t <= r; t++) {
		a[t] = temp[t];
	}
}
int lowerbound(long long* a, int n, long long key) {
	int l = 0;
	int r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < key) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return l;
}
int main() {
	int n;
	cin >> n;
	long long x[MAX];
	long long tmpx[MAX];
	long long diff[MAX];
	long long tmpd[MAX];
	long long prefix[MAX];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	merge(x, tmpx, 0, n - 1);
	int m = n - 1;
	for (int i = 0; i < m; i++) {
		diff[i] = x[i + 1] - x[i];
	}
	if (m > 0) {
		merge(diff, tmpd, 0, m - 1);
	}
	prefix[0] = 0;
	for (int i = 0; i < m; i++) {
		prefix[i + 1] = prefix[i] + diff[i];
	}
	int q;
	cin >> q;
	while (q--) {
		long long l, r;
		cin >> l >> r;
		if (l > r) {
			long long t = l;
			l = r;
			r = t;
		}
		long long len = r - l + 1;
		int k = lowerbound(diff, m, len);
		long long ans = prefix[k] + (long long)(n - 1) * len;
		cout << ans;
		if (q > 0) {
			cout << " ";
		}
	}

	return 0;
}