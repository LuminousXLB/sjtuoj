// 4067. 整数加一
// #464144 正确 / 分数：100 / 时间：0ms / 内存：5248kb
#include <iostream>

using namespace std;

const char overflow = '9' + 1;

int main(int argc, char const *argv[]) {
    char num[52] = { '0' };
    char *p = num + 1;
    int len = 0;
    cin >> p;
    while(p[len]) ++len;

    ++num[len];

    for(int i = len; i > 0; --i) {
        if (num[i] == overflow) {
            num[i] = '0';
            ++num[i-1];
        }
    }

    if(num[0] == '0') {
        cout << p;
    } else {
        cout << num;
    }
    return 0;
}
