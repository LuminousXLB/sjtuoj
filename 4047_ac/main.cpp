// 4047. 埃拉托色尼筛法
// #519468 正确 / 分数：100 / 时间：130ms / 内存：14300kb
#include <cstdio>
#include <cmath>

const size_t maxsize = 2000000;

int main(int argc, char const *argv[]) {
    bool arr[maxsize] = { 0 };
    size_t max;

    scanf("%d", &max);
    double sup = sqrt(max) + 1;

    for (size_t i = 3; i <= sup; i += 2) {
        // printf("i = %d flag = %d\n", i, arr[i]);
        if (arr[i]) {
            continue;
        } else {
            for (size_t j = 3; i * j <= max; j += 2) {
                arr[i * j] = true;
            }
        }
    }

    printf("2");
    for (size_t i = 3; i <= max; i += 2) {
        if (!arr[i]) {
            printf(" %d", i);
        }
    }

    return 0;
}
