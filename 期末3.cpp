#include <stdio.h>
#include <stdlib.h>

int count = 0;
void hanoi(int n, int temp1, int temp2, int temp3, int temp4, int temp5);
void hanoii(int n, int temp1, int temp2, int temp3, int temp4, int temp5);
void hanoiii(int n, int temp1, int temp2, int temp3, int temp4, int temp5);

int main() {
	int n = 10;

	hanoi(n, 1, 2, 3, 4, 5);
	printf("%d\n", count);

	system("pause");
	return 0;
}

void hanoi(int n, int temp1, int temp2, int temp3, int temp4, int temp5) {
	printf("%d->%d\n", temp2, temp5);
	printf("%d->%d\n", temp2, temp1);
	count += 2;
	if (n == 10) {
		printf("%d->%d\n", temp2, temp3);
		printf("%d->%d\n", temp2, temp4);
		count += 2;
		hanoii(n - 2, temp1, temp2, temp3, temp4, temp5);
	}
	if (n == 8) {
		printf("%d->%d\n", temp2, temp3);
		count++;
		hanoii(n - 2, temp5, temp2, temp1, temp3, temp4);
	}
	if (n == 6) {
		hanoii(n - 2, temp1, temp5, temp2, temp3, temp4);
	}
	if (n == 4) {
		printf("%d->%d\n", temp2, temp3);
		count++;
		hanoii(n - 2, temp3, temp1, temp2, temp4, temp5);
	}
}

void hanoii(int n, int temp1, int temp2, int temp3, int temp4, int temp5) {
	printf("%d->%d\n", temp3, temp4);
	printf("%d->%d\n", temp1, temp4);
	count += 2;
	if (n == 8) {
		printf("%d->%d\n", temp5, temp4);
		count++;
		hanoi(n, temp1, temp2, temp3, temp4, temp5);
	}
	if (n == 6) {
		hanoiii(n, temp3, temp2, temp4, temp5, temp1);
	}
	if (n == 4) {
		printf("%d->%d\n", temp2, temp4);
		count++;
		hanoi(n, temp1, temp5, temp3, temp4, temp2);
	}
	if (n == 2) {
		printf("%d->%d\n", temp2, temp4);
		printf("%d->%d\n", temp5, temp4);
		count += 2;
	}
} 

void hanoiii(int n, int temp1, int temp2, int temp3, int temp4, int temp5){
	printf("%d->%d\n", temp2, temp5);
	printf("%d->%d\n", temp2, temp1);
	printf("%d->%d\n", temp5, temp1);
	printf("%d->%d\n", temp2, temp5);
	printf("%d->%d\n", temp1, temp2);
	printf("%d->%d\n", temp1, temp5);
	printf("%d->%d\n", temp2, temp5);
	count += 7;
	hanoi(n, temp2, temp3, temp5, temp4, temp1);
}

