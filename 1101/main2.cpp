// 1101. SuperXOR
//

#include <iostream>
using namespace std;

const char __base__ = 10;

char digit_XOR(char a, char b) {
    return (a + b) % __base__;
}

unsigned long long XOR(unsigned long long a, unsigned long long b) {
    char res[16] = {0};
    unsigned long long ret = 0;
    for (short i = 0; a > 0 || b > 0; a/=10, b/=10, i++) {
        res[i] = digit_XOR(a%10, b%10);
    }
    for (short i = 15; i >=0; i--) {
        ret = ret*10 + res[i];
        // cout << (unsigned)res[i] << endl;
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        unsigned long long sum = 0;
        unsigned long long num;
        cin >> num;
        for (unsigned long long i = 1; i <= num; i++) {
            sum = XOR(sum, i);
        }
        cout << sum << endl;
    }
    return 0;
}
