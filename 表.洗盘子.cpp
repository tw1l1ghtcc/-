#include <iostream>
using namespace std;

const int MAX_QUEUE = 200000;
const int MAX_LUCKY = 3000;

int pigs[MAX_QUEUE];
int lucky[MAX_LUCKY];
int qsize = 0;

void generate_lucky() {
    for (int i = 2; i <= MAX_QUEUE; i++) {
        pigs[qsize++] = i;
    }

    int count = 0;
    int head = 0;

    while (count < MAX_LUCKY) {
        int val = pigs[head];
        lucky[count++] = val;

        int index = head + 1;
        for (int i = head + 1; i < qsize; i++) {
            if ((i - head) % val != 0) {
                pigs[index++] = pigs[i];
            }
        }
        qsize = index;
        head++;
    }
}

int main() {
    int T;
    cin >> T;

    int queries[305];
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
    }

    generate_lucky();

    for (int i = 0; i < T; i++) {
        cout << lucky[queries[i] - 1] << endl;
    }
    return 0;
}
