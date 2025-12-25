#include <iostream>
using namespace std;
const int MAX_QUEUE = 200000; // 队列足够大
int pigs[MAX_QUEUE];
int qsize = 0;
const int MAX_LUCKY = 3000;
int lucky[MAX_LUCKY];
int main() {
    int T;
    cin >> T;
    int queries[305];
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
    }
    for (int i = 2; i <= MAX_QUEUE; i++) {
        pigs[qsize++] = i;
    }
    int count = 0;
    int head = 0; // 队首索引
    while (count < MAX_LUCKY) {
        int val = pigs[head];       // 队首小猪
        lucky[count++] = val;

        // 原地删除队首之后每隔 val 个小猪
        int index = head + 1;       // 新队列写入位置
        for (int i = head + 1; i < qsize; i++) {
            if ((i - head) % val != 0) {
                pigs[index++] = pigs[i];
            }
        }
        qsize = index;              // 更新队列长度
        head++;                     // 队首出队
    }
    // 输出查询结果
    for (int i = 0; i < T; i++) {
        cout << lucky[queries[i] - 1] << endl;
    }
    return 0;
}
