// 4068. Z字形输出
// #464350 正确 / 分数：100 / 时间：7ms / 内存：10684kb
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int step = 2*(n - 1);

    cin.get();

    char str[32];
    int len = 0;
    cin >> str;
    while(str[len]) len++;

    if (n == 1) {
        cout << str;
    } else {
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                for (int k = i; k < len; k += step) {
                    cout << str[k];
                }
            } else {
                int substep = 2*(n - i - 1);
                for (int k = i; k < len; k+=step) {
                    cout << str[k];
                    if (k + substep < len) {
                        cout << str[k + substep];
                    }
                }
            }
        }
    }
    return 0;
}
