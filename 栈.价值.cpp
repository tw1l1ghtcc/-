#include <iostream>
#include <algorithm>
using namespace std;

long long calcMaxValue(const int a[], int N) {
    long long prefix_sum[100001];
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    int st[100000];
    int top = 0;

    long long max_value = 0;

    for (int i = 0; i < N; ++i) {
        while (top > 0 && a[st[top - 1]] >= a[i]) {
            int idx = st[--top];
            int right = i;
            int left = (top == 0 ? -1 : st[top - 1]);

            long long sum = prefix_sum[right] - prefix_sum[left + 1];
            max_value = std::max(max_value, sum * (long long)a[idx]);
        }
        st[top++] = i;
    }

    while (top > 0) {
        int idx = st[--top];
        int right = N;
        int left = (top == 0 ? -1 : st[top - 1]);

        long long sum = prefix_sum[right] - prefix_sum[left + 1];
        max_value = std::max(max_value, sum * (long long)a[idx]);
    }

    return max_value;
}

int main() {
    int N;
    cin >> N;

    int a[100000];
    for (int i = 0; i < N; ++i) cin >> a[i];

    cout << calcMaxValue(a, N) << "\n";
    return 0;
}
