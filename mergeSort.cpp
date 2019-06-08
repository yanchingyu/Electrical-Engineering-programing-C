#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define size 8

int sort[size] = { 6,5,1,8,4,3,2,9 };

void bublleSort(int _sort[]) {
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j < size/2 - i - 1; j++) {
			if (_sort[j] > _sort[j + 1]) {
				int temp = _sort[j];
				_sort[j] = _sort[j + 1];
				_sort[j + 1] = temp;
			}
		}
	}
}


void mergeSort(int sort1[], int sort2[]) {
	int count = 0, count1 = 0;
	for (int i = 0; i < size; i++) {
		if (i == 7 && count == 3) {
			printf("%d ", sort1[count]);
			return;
		}
		else if(i == 7 && count1 == 3){
			printf("%d ", sort2[count1]);
			return;
		}
		if (sort1[count] >= sort2[count1]) {
			printf("%d ", sort2[count1]);
			count1++;
		}
		else if (sort1[count] < sort2[count1]) {
			printf("%d ", sort1[count]);
			count++;
		}
	}
}

int main() {
	int sort1[size / 2], sort2[size / 2];
	
	for (int i = 0; i < size / 2; i++) 
		sort1[i] = sort[i];

	int count = 0;
	for (int i = size / 2; i < size; i++) {
		sort2[count] = sort[i];
		count++;
	}


	bublleSort(sort1);
	bublleSort(sort2);

	mergeSort(sort1, sort2);

	system("pause");
	return 0;
}