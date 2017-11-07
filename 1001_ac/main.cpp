// 1001. 二哥摘苹果
// #383031 正确 / 分数：100 / 时间：28ms / 内存：10780kb
#include <iostream>

using namespace std;

int main() {
    int shengao, dengzi, total;

    cin >> shengao >> dengzi >> total;
    int height = shengao + dengzi;
    int apple, cnt = 0;
    for (int i = 0; i < total; i++) {
        cin >> apple;
        if (apple <= height) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
