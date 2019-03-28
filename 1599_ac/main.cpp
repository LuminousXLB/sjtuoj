// 1599. Brackets Stack
// #643652 正确 / 分数：100 / 时间：170ms / 内存：9188kb
#include <cstdio>
#include <stack>
#include <vector>
#include <string>

using namespace std;

inline bool paired(char a, char b)
{
    int diff = b - a;
    return diff == 1 || diff == 2;
}

const char *isPaired(const vector<char> &context)
{
    const char *base = context.data();
    const char *ptr = base + context.size() - 1;
    stack<char> to;

    while (ptr >= base)
    {
        if (!to.empty() && paired(*ptr, to.top()))
        {
            ptr--;
            to.pop();
        }
        else
        {
            to.push(*ptr);
            ptr--;
        }
    }

    return to.empty() ? "YES" : "NO";
}

int main()
{
    // freopen("sample.input", "r", stdin);

    int num_of_rounds;
    scanf("%d\n", &num_of_rounds);

    vector<char> context;
    context.reserve(1000);
    int operation;
    char payload;

    for (int i = 0; i < num_of_rounds; i++)
    {
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            scanf(" %c\n", &payload);
            context.push_back(payload);
            break;
        case 2:
            if (!context.empty())
            {
                context.pop_back();
            }
            break;
        case 3:
            if (!context.empty())
            {
                printf("%c\n", context.back());
            }
            break;
        case 4:
            printf("%s\n", isPaired(context));
            break;
        }
    }
}