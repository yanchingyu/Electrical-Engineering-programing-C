#include <stdio.h>
#include <stdlib.h>

int XXX(int array[8], int count);
int main() {
	int array[8], count = 6;

	for (int i = 0; i < 8; i++) {
		printf("請輸入第%d個數字:", i + 1);
		scanf("%d", &array[i]);
	}
	for (int i = 0; i < 8; i++) {
		printf("%d ", XXX(array, count));
		count--;
	}

	system("pause");
	return 0;
}

int XXX(int array[], int count) {
	int min=array[0];

	for (int i = 0; i <= count; i++) {
		if (array[i] < array[i + 1]) {
			min = array[i];
			array[i] = array[i + 1];
			array[i + 1] = min;
		}
		else if (i == count && array[i] > array[i + 1]) {
			min = array[i + 1];
		}
	}
	return min;

}

