// 4011. k树

#include <iostream>

using namespace std;

int* produce(int k, int* current)
{
    int* next = new int[k]();
    for (int i = 0; i < k; i++) {
        for (int j = k - i - 1; j >= 0; j--) {
            next[j] += current[i];
        }
    }

    return next;
}

int main(int argc, char const* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("sample.in", "r", stdin);
#endif

    int k, h;
    cin >> k >> h;

    int* cnt = new int[k]();

    cnt[0] = 1;

    for (int i = 0; i < k; i++) {
        cerr << cnt[i] << ' ';
    }
    cerr << endl;

    for (int i = 1; i < h; i++) {
        int* next = produce(k, cnt);
        delete[] cnt;
        cnt = next;

        for (int i = 0; i < k; i++) {
            cerr << cnt[i] << ' ';
        }
        cerr << endl;
    }
 
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += cnt[i];
    }

    cout << sum << endl;

    delete[] cnt;

    return 0;
}
