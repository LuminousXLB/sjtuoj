// 4040. 计算阿姆斯特朗数
// 421268	2ms	4444kb	2017-10-21 12:23:52

#include <cstdio>
// #include <iostream>
// using namespace std;

int vol(int n) {
	return n*n*n;
}

int main () {
	bool found = false;
	size_t inf, sup;
	scanf("%d %d", &inf, &sup);
	if (inf <= 0 || sup < inf) {
		printf("error\n");
		return 0;
	}
	for (size_t i = inf; i <= sup; i++) {
		// cout << "========== " << i << endl;
		size_t tmp = i, sum = 0;
		while (tmp > 0) {
			unsigned short digit = tmp % 10;
			tmp /= 10;
			sum += vol(digit);
			// cout << digit << endl;
		}
		if (i == sum) {
			printf("%d\n", i);
			found = true;
		}
		// cout << "====== " << sum << endl;
	}
	if (!found) {
		printf("no\n");
	}
}
