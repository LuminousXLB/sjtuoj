// 4040. 计算阿姆斯特朗数
// #421268 正确 / 分数：100 / 时间：2ms / 内存：4444kb
#include <cstdio>

int vol(int n) {
    return n * n * n;
}


int main() {
    bool found = false;
    size_t inf, sup;

    scanf("%d %d", &inf, &sup);
    if ((inf <= 0) || (sup < inf)) {
        printf("error\n");
        return 0;
    }
    for (size_t i = inf; i <= sup; i++) {
        size_t tmp = i, sum = 0;
        while (tmp > 0) {
            unsigned short digit = tmp % 10;
            tmp /= 10;
            sum += vol(digit);
        }
        if (i == sum) {
            printf("%d\n", i);
            found = true;
        }
    }
    if (!found) {
        printf("no\n");
    }
}
