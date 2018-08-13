// 1101. SuperXOR
// #554591 正确 / 分数：100 / 时间：131ms / 内存：1076kb
#include <iostream>
using namespace std;

short XOR_table[] = { 0, 1, 3, 6, 0, 5, 1, 8, 6, 5 };

int main(int argc, char const* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int cnt[16][10] = { 0 };
        unsigned long long num;
        cin >> num;

        unsigned long long threshold = 0;

        unsigned long long tmp = num / 100;
        if (tmp > 0) {
            threshold = (tmp - 1) * 100 + 99;
        } else {
            threshold = 0;
        }

        for (unsigned long long k = num; k > threshold; k--) {
            unsigned long long tmp = k;
            for (short i = 0; tmp > 0; tmp /= 10, i++) {
                cnt[i][tmp % 10]++;
            }
        }

        short res[16] = { 0 };
        for (int j = 0; j < 16; j++) {
            for (int i = 0; i < 10; i++) {
                res[j] += i * (cnt[j][i] % 10);
            }
        }

        unsigned long long sum = 0;
        for (short i = 15; i >= 0; i--) {
            sum = sum * 10 + (res[i] % 10);
        }

        cout << sum << endl;
    }
    return 0;
}