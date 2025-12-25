#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100001;

// 全局数组，避免栈溢出
int a[MAXN];
long long prefix_sum[MAXN];
int st[MAXN];

long long calcMaxValue(int n) {

    // 1. 计算前缀和
    prefix_sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    // 2. 单调栈
    int top = 0;
    long long max_value = 0;

    // 3. 主循环
    for (int i = 0; i < n; i++) {

        // 当当前元素更小，弹栈
        while (top > 0 && a[st[top - 1]] >= a[i]) {

            int idx = st[top - 1];
            top--;

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

        // 当前下标入栈
        st[top] = i;
        top++;
    }

    // 4. 清空栈中剩余元素
    while (top > 0) {

        int idx = st[top - 1];
        top--;

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
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << calcMaxValue(n) << endl;
    return 0;
}
