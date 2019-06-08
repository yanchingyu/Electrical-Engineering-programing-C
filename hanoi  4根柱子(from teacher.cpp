#include <stdio.h>
#include <stdlib.h>

int count = 0;		
void hanoi(int n, int from, int to, int temp1, int temp2) {
	if (n == 1) {
		printf("%d-->%d\n", from, to);
		count++;
		return;
	}
	if (n == 2 ) {
		printf("%d-->%d\n", from, temp1);
		printf("%d-->%d\n", from, to);
		printf("%d-->%d\n", temp1, to);
		count += 3;
		return;
	}
	if (n == 3) {
		printf("%d-->%d\n", from, temp2);
		printf("%d-->%d\n", from, temp1);
		printf("%d-->%d\n", from, to);
		printf("%d-->%d\n", temp1, to);
		printf("%d-->%d\n", temp2, to);
		count += 5;
		return;
	}
	/*int temp1 = 3, temp2 = 4;
	hanoi(n - 2, from, temp2);
	hanoi(1, from, temp1);
	hanoi(1, temp2, temp1);
	hanoi(1, from, temp2);
	hanoi(n - 2, from, to );*/

	hanoi(n - 2, from, temp2, to, temp1);
	hanoi(1, from, temp1, to, temp2);
	hanoi(1, from, to, temp2, temp1);
	hanoi(1, temp1, to, temp2, from);
	hanoi(n - 2, temp2, to, from, temp1);
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3, 4);
	printf("%d\n", count);

	system("pause");
	return 0;
}


