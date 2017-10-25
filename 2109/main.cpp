#include <cstdio>

bool delta(int a, int b2, int c) {
    int delta = b2 - 4 * a * c;

    return delta >= 0;
}


int main(int argc, char const *argv[]) {
    int N;

    scanf("%d", &N);
    int *num = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", num + i);
    }

    int K, b, c;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &b, &c);
        b = b * b;
        for (int j = 0; j < N; j++) {
            if (!delta(num[j], b, c)) {
                printf("%d\n", j);
                break;
            } else if (j == N - 1) {
                printf("%d\n", N);
            }
        }
    }

    delete[] num;
    return 0;
}
