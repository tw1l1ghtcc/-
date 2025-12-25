#include <iostream>
#include <algorithm>
using namespace std;

long long calcMaxValue(int n) {
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    int top = 0;
    long long max_value = 0;

    for (int i = 0; i < n; ++i) {
        while (top > 0 && a[st[top - 1]] >= a[i]) {
            int idx = st[--top];
            int right = i;

            int left;
            if (top == 0) {
                left = -1;
            } else {
                left = st[top - 1];
            }

            long long sum = prefix_sum[right] - prefix_sum[left + 1];
            long long value = sum * (long long)a[idx];

            if (value > max_value) {
                max_value = value;
            }
        }
        st[top++] = i;
    }

    while (top > 0) {
        int idx = st[--top];
        int right = n;

        int left;
        if (top == 0) {
            left = -1;
        } else {
            left = st[top - 1];
        }

        long long sum = prefix_sum[right] - prefix_sum[left + 1];
        long long value = sum * (long long)a[idx];

        if (value > max_value) {
            max_value = value;
        }
    }

    return max_value;
}

int main() {
    int N;
    cin >> N;

    int a[100000];
    for (int i = 0; i < N; ++i) cin >> a[i];

    cout << calcMaxValue(a, N) << endl ;
    return 0;
}


