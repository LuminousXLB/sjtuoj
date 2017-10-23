// 1101. SuperXOR
//

#include <cstdio>
// #include <iostream>
// using namespace std;

const char __base__ = 10;
const int max_size = 16;

char digit_XOR(char a, char b) {
    return (a + b) % __base__;
}
//
// int XOR(int a, int b) {
//
// }

int main(int argc, char const *argv[]) {
    int T;
    printf("<<< ");
    scanf("%d\n", &T);
    printf(">>> %d\n", T);
    for (int t = 0; t < T; t++) {
        char N[max_size] = {0};
        printf("<<< ");
        scanf("%s\n", N);
        printf(">>> %s\n", N);
        char num[max_size] = {0};
        for (int i = 0; N[i]; i++) {
            num[max_size - 1 - i] = N[i] - '0';
        }
        for (int i = 0; i<max_size; i++) {
            printf(">>> %d\n", (int) num[i]);
        }
    }
    return 0;
}
