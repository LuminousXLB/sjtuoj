#include <cstdio>
#include <cmath>

const int maxsize = 2000000;


int main(int argc, char const *argv[]) {
	freopen("output.txt", "w", stdout);
	bool arr[maxsize] = {0};
	int max;
	scanf("%d", &max);
	double sup = sqrt(max) + 1;

	for (int i = 3; i <= sup; i += 2) {
		if(arr[i]) {
			continue;
		} else {
			for (int j = 2; i*j <= max; j++) {
				arr[i*j] = true;
			}
		}
	}

	printf("2");
	for (int i = 3; i <= max; i += 2) {
		if (!arr[i]) {
			printf(" %d", i);
		}
	}

	return 0;
}
