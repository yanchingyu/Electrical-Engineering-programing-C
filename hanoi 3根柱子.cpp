#include <stdio.h>
#include <stdlib.h>

int count = 0;
void hanoi(int n, int from, int to, int temp) {
	if (n == 1) {
		printf("%d-->%d\n", from, to);
		count++;
		return;
	}

	hanoi(n - 1, from, temp, to);
	hanoi(1, from, to, temp);
	hanoi(n - 1, to, from, temp);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("%d\n", count);

	system("pause");
	return 0;
}