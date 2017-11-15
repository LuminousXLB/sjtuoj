// 4059. 求数组最大值及位置
// #464162 正确 / 分数：100 / 时间：0ms / 内存：4360kb
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int cnt;
    cin >> cnt;

    int max = 0, tmp, index;

    for (int i = 0; i < cnt; i++) {
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            index = i;
        }
    }

    cout << max << ' ' << index + 1;
    return 0;
}
