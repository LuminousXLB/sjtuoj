// 1005. 数独
// #555311 正确 / 分数：100 / 时间：10ms / 内存：10668kb 
#ifndef ONLINE_JUDGE
#define _freopen(fn) freopen(fn, "r", stdin);
#define _log(format, ...)                                               \
    fprintf(stderr, "[%s:%d] <%s> ", __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, format, ##__VA_ARGS__);                             \
    fprintf(stderr, "\n");
#else
#define _freopen(fn)
#define _log(format, ...)
#endif

#include <iostream>

using namespace std;

bool judge()
{
    int current;
    // int table[9][9] = { 0 };
    bool row[9][9] = { false };
    bool col[9][9] = { false };
    bool area[3][3][9] = { false };

    for (int ir = 0; ir < 9; ir++) {
        for (int ic = 0; ic < 9; ic++) {
            cin >> current;
            current--;
            // table[ir][ic] = current;
            row[ir][current] = true;
            col[ic][current] = true;
            area[ir / 3][ic / 3][current] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!row[i][j])
                return false;
            if (!col[i][j])
                return false;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 9; k++) {
                if (!area[i][j][k])
                    return false;
            }
        }
    }

    return true;
}

int main(int argc, char const* argv[])
{
    _freopen("sample.in");

    int CNT = 0;
    cin >> CNT;

    for (int cnt = 0; cnt < CNT; cnt++) {
        if (judge()) {
            cout << "Right" << endl;
        } else {
            cout << "Wrong" << endl;
        }
    }

    return 0;
}
