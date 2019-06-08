#include <stdio.h>
#include <stdlib.h>

int main() {
	char x[1000];
	int xx[9] = {};
	scanf("%s", x);

	int xStart = 0, count = 0;
	while (x[xStart] != '\0') {
		while(x[xStart] >= '0' && x[xStart] <= '9') {
			count = x[xStart] - '0';

			xx[count - 1]++;
			xStart++;
		}
		xStart++;
	}

	for (int i = 0; i < 9; i++) {
		if (xx[i] != 0) {
			printf("%d->%d\n", i+1, xx[i]);
		}
	}

	system("pause");
	return 0;
}