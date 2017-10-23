#include <iostream>
#include <stack>

using namespace std;

bool arrange() {
    int N, M;
    int next = 0;
    stack<int> park;
    
    cin >> N >> M;
    cin.get();
    int awayseq[3000] = {-1};
    for (int i = 0; i < N; ++i) {
        cin >> awayseq[i];
    }

    for (int i = 0; i < N; ++i) {
        cout << "*** " << awayseq[i] << endl;
    }

    for (int i = 0; i < N; ++i) {
        cout << "****" << i << endl;
        int cur = awayseq[i];
        if(next == cur) {
            next++;
        } else if (park.top() == cur) {
            park.pop();
        } else if (park.empty() || park.size() < M) {
            park.push(cur);
        } else {
            return false;
        }
        cout << i << '\t' << park.size() << endl;
    }
    return true;
}

int main() {
    int T;
    bool rec[300] = {0};
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