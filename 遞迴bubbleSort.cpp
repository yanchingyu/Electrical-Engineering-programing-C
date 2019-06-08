#include <stdio.h>
#include <stdlib.h>

int array[8] = { 2, 9, 11, 12, 6, 7, 6, 4 };

void scan(int lastID) {
	
	for (int i = 0; i < lastID; i++) {
		if (array[i] > array[i + 1]) {
			int temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}
	}
}

void bubbleSort(int lastID) {
	if (lastID < 1) return;
	scan(lastID);
	bubbleSort(lastID - 1);
}

int main() {
	bubbleSort(7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", array[i]);
	}

	system("pause");
	return 0;
}