// 1002. 二哥种花生
// #552773 正确 / 分数：100 / 时间：2778ms / 内存：16624kb 

#include <iostream>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    int l, w;
    cin >> l >> w;

    char area[1001][1001];
    short tmp = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            area[i][j] = tmp;
        }
    }

    int a, b;
    int cnt, res = 0;
    cin >> a >> b;

    if (a == 1 && b == 1) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                if (area[i][j] > res) {
                    res = area[i][j];
                }
            }
            if (res == 9) {
                break;
            }
        }
    } else if (a == l && b == w) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < w; j++) {
                res += area[i][j];
            }
        }
    } else {
        for (int si = 0; si <= l - a; si++) {
            cnt = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    cnt += area[i + si][j];
                }
            }

            if (cnt > res) {
                res = cnt;
            }

            for (int sj = 1; sj <= w - b; sj++) {
                for (int i = 0; i < a; i++) {
                    cnt -= area[si + i][sj - 1];
                    cnt += area[si + i][sj - 1 + b];
                }

                if (cnt > res) {
                    res = cnt;
                }
            }
        }
    }
    cout << res;

    return 0;
}