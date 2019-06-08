#include <stdio.h>
#include <stdlib.h>

int count = 0;
void hanoi(int n, int temp1, int from, int temp3, int temp4, int temp5, int to);
void hanoii(int n, int temp1, int from, int temp3, int temp4, int temp5, int to);
void hanoiii(int n, int temp1, int from, int temp3, int temp4, int temp5, int to);

int main() 
{
	int n = 10;
	hanoi(n, 1, 2, 3, 4, 5, 6);
	printf("%d\n", count);

	system("pause");
	return 0;
}

void hanoi(int n, int temp1, int from, int temp3, int temp4, int temp5, int to)
{
	printf("%d->%d\n", from, temp1);
	printf("%d->%d\n", from, temp3);
	printf("%d->%d\n", from, temp4);
	count += 3;
	if (n == 10) {
		printf("%d->%d\n", from, temp5);
		count++;
		hanoii(n - 2, temp1, from, temp3, temp4, temp5, to);
	}
	if (n == 6) {
		printf("%d->%d\n", temp3, temp4);
		printf("%d->%d\n", temp1, temp4);
		count += 2;
	}

}

void hanoii(int n, int temp1, int from, int temp3, int temp4, int temp5, int to)
{
	printf("%d->%d\n", temp4, temp5);
	printf("%d->%d\n", temp3, temp5);
	count += 2;
	if (n == 8 || n == 4 || n == 0) {
		printf("%d->%d\n", temp1, temp5);
		count++;
	}
	if (n == 0) {
		printf("%d->%d\n", to, temp5);
		count++;
	}
	if (n == 8) {
		hanoi(n, temp1, from, temp3, temp4, temp5, to);
		hanoii(n - 2, temp5, from, temp1, temp3, temp4, to);
	}
	else if (n == 6) {
		hanoi(n, temp3, from, temp4, to, temp1, temp5);
		hanoiii(n, temp3, from, temp4, temp5, temp1, to);
		hanoii(n - 2, temp3, from, temp4, temp5, to, temp1);
	}
	else if (n == 4)
		hanoiii(n - 2, temp1, from, temp3, to, temp4, temp5);
}

void hanoiii(int n, int temp1, int from, int temp3, int temp4, int temp5, int to)
{
	printf("%d->%d\n", temp4, temp1);
	printf("%d->%d\n", temp4, temp3);
	count += 2;
	if (n == 2) {
		printf("%d->%d\n", temp4, temp5);
		count++;
		hanoii(n - 2, temp3, from, temp5, temp4, to, temp1);
	}
		
}