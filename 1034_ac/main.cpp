// 1034. 二哥的金链
// #464985 正确 / 分数：100 / 时间：212ms / 内存：13916kb

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class mycomparison {
    bool reverse;
public:
    mycomparison(const bool& revparam = false) {
        reverse = revparam;
    }
    bool operator()(int *& lhs, int *& rhs) const {
        if (reverse) {
            return(*lhs > *rhs);
        } else {
            return(*lhs < *rhs);
        }
    }
};

typedef std::priority_queue<int *, std::vector<int *>, mycomparison> mypq;

int *findmax(int *head, int len) {
    mypq pq;

    for (size_t i = 0; i < len; i++) {
        pq.push(head + i);
    }

    return pq.top();
}


int main(int argc, char const *argv[]) {
    // freopen("sample.in", "r", stdin);

    size_t count, len;
    int *rp = new int[count + len];

    scanf("%d %d", &count, &len);
    for (size_t i = 0; i < count; i++) {
        scanf("%d", &rp[i]);
    }

    for (size_t i = 0; i < len; i++) {
        rp[i + count] = rp[i];
    }

    mypq pq(mycomparison(true));
    int *bottom = rp + count;
    for (int *p = rp; p < bottom; p++) {
        p = findmax(p, len);
        pq.push(p);
    }

    printf("%d\n", *pq.top());

    return 0;
}
