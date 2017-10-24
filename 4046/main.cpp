#include <cstdio>

const int maxsize = 10;

int main(int argc, char const *argv[]) {
	int m = 3, n = 4, data[maxsize*maxsize];
	scanf("%d %d", &m, &n);
	int count = m*n;

	for (int i = 0; i < count; i++) {
		scanf("%d", data+i);
	}

for (int j = 0; j < n; j++) {
	for (int i = m-1; i >= 0; i--) {
		printf("%d", i*n+j );
		if (i) {
			printf(" ");
		}
	}
	if (j != n-1) {
		printf("\n");
	}
}
	return 0;
}


/*
m = 3; n = 4

0	1	2 	3
4	5 	6	7
8	9	10	11

8	4	0




*/
