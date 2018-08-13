// 1049. 火车调度
// #554576 正确 / 分数：100 / 时间：49ms / 内存：10536kb
#include <iostream>
#include <stack>

using namespace std;

bool arrange()
{
    int N, M;
    stack<int> park;

    cin >> N >> M;
    cin.get();

    int awayseq[1024];
    for (int i = 0; i < N; ++i) {
        cin >> awayseq[i];
    }

    if (M > N) {
        return true;
    }

    int i = 0;
    for (int next = 0; next < N; next++) {

        if (next == awayseq[i]) {
            i++;
            while ((!park.empty()) && (i < N) && (park.top() == awayseq[i])) {
                i++;
                park.pop();
            }
        } else {
            park.push(next);
            if ((int)park.size() > M) {
                return false;
            }
        }
    }

    return park.empty();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif

    int T;
    cin >> T;
    cin.get();

    for (int i = 0; i < T; ++i) {
        if (arrange()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
