#include <iostream>
#include <stack>

using namespace std;

bool arrange()
{
    int N, M;
    stack<int> park;

    cin >> N >> M;
    cin.get();

    int awayseq[1000];
    for (int i = 0; i < N; ++i) {
        cin >> awayseq[i];
    }

    // cout << "*** ";
    // for (int i = 0; i < N; ++i) {
    //     cout << awayseq[i] << " ";
    // }
    // cout << endl;

    int i = 0;
    for (int next = 0; next < N; next++) {
        int cur = awayseq[i];
        // cout << "next " << next << "\tcur " << cur;

        if (next == cur) {
            do {
                i++;
                // cout << "\ti++ " << awayseq[i] << " " << park.empty() << " " << park.top() << endl;
            } while ((!park.empty()) && (park.top() == awayseq[i]));
        } else if (park.empty() || (int)park.size() < M) {
            // cout << "\tpark" << endl;
            park.push(next);
        } else {
            // cout << "\tfalse" << endl;
            return false;
        }
    }

    return true;
}

int main()
{
    freopen("test.in", "r", stdin);

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
