// 4060. 最优潜水策略设计
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;

    cin >> n;
    if (n > 0) {
        int pool[100] = { 0 };
        int min, tmp;
        cin >> min;
        int sum = min;
        for (int i = 1; i < n; i++) {
            cin >> tmp;
            sum += tmp;
            if (tmp < min) {
                min = tmp;
            }
        }
        sum += min * (n - 3);
        cout << sum << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
