// 1205. ackerman
// #408061 正确 / 分数：100 / 时间：8ms / 内存：11424kb
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

const char DEBUG[] = "DEBUG\t";

int Ackerman(int m, int n);
int Ackerman_opt(int m, int n);

struct arg {
    int m, n;
};

const int SIZE = 10000;
int data[SIZE][SIZE] = { 0 };
stack<arg> cache;

int getData(int m, int n);
int Ackerman_stack(int m, int n);


void printAck(int m, int n) {
    cout << m << '\t' << n << '\t' << Ackerman_opt(m, n) << '\t' << Ackerman_stack(m, n) << endl;
}


int main() {
    int m, n;

    cin >> m >> n;
    cout << Ackerman_stack(m, n);
    return 0;
}


int Ackerman(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return Ackerman(m - 1, 1);
    } else {
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
}


int Ackerman_opt(int m, int n) {
    if ((m == 1) && (n >= 1)) {
        return n + 2;
    } else if ((m == 2) && (n >= 1)) {
        return 2 * n + 3;
    } else if ((m == 3) && (n >= 1)) {
        return pow(2, n + 3) - 3;
    }

    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        if (m == 1) {
            return Ackerman_opt(m - 1, 1);
        } else {
            return Ackerman_opt(m - 2, Ackerman_opt(m - 1, 0));
        }
    } else {
        return Ackerman_opt(m - 1, Ackerman_opt(m, n - 1));
    }
}


int getData(int m, int n) {
    int ret = data[m][n];

    if (!ret) {
        arg uncalculated = { m, n };
        cache.push(uncalculated);
    }
    return ret;
}


int Ackerman_stack(int m, int n) {
    arg enter = { m, n };

    cache.push(enter);

    while (!cache.empty()) {
        arg cur = cache.top();
        int m = cur.m, n = cur.n;

        if (data[m][n]) {
            cache.pop();
        } else {
            if (m == 0) {
                data[m][n] = n + 1;
            } else if (n == 0) {
                data[m][n] = getData(m - 1, 1);
            } else {
                int nn = getData(m, n - 1);
                if (nn) {
                    data[m][n] = getData(m - 1, nn);
                }
            }
            if (data[m][n]) {
                cache.pop();
            }
        }
    }
    return data[m][n];
}
