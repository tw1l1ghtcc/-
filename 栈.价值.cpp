#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a[100000];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    long long prefix_sum[100001];
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    int stack[100000];
    int stack_size = 0;
    long long max_value = 0;
    for (int i = 0; i < N; ++i) {
        while (stack_size > 0 && a[stack[stack_size - 1]] >= a[i]) {
            int top_index = stack[--stack_size];
            int right = i;
            int left = stack_size == 0 ? -1 : stack[stack_size - 1];

            long long sum = prefix_sum[right] - prefix_sum[left + 1];

            max_value = max(max_value, sum * (long long)(a[top_index]));
        }
        stack[stack_size++] = i;
    }

    while (stack_size > 0) {
        int top_index = stack[--stack_size];
        int right = N; 
        int left = stack_size == 0 ? -1 : stack[stack_size - 1];
        long long sum = prefix_sum[right] - prefix_sum[left + 1];

        max_value = max(max_value, sum * (long long)(a[top_index]));
    }

    cout << max_value << endl;

    return 0;
}
