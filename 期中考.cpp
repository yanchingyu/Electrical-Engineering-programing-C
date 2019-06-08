#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int array[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (array[j]>array[j+1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void post_mark_average(int array[], int n) {
	double total = 0;
	for (int i = 0; i < n/2; i++) {
		total += array[i];
	}
	printf("後標平均數:%0.2f\n", total / (n / 2));
}


double pass_average(int array[], int n) {
	double total = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] >= 60) {
			total += array[i];
			count++;
		}
	}
	return total / count;
}

void variance(int array[], int n) {
	double total = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] >= 60) {
			total += pow(array[i] - pass_average(array, n), 2);
			count++;
		}
	}
	printf("變異數:%0.2f\n", total/count);
}

int main() {
	FILE *fp1;
	int *array, n;

	fp1 = fopen("C:\\Users\\student\\Downloads\\data.txt", "r");
	if (fp1 == NULL)
		return 0;
	
	fscanf(fp1, "%d", &n);
	array = new int[n];

	for (int i = 0; i < n; i++) {
		fscanf(fp1, "%d", &array[i]);
	}
	bubbleSort(array, n);

	post_mark_average(array, n);

	printf("60以上平均數:%0.2f\n", pass_average(array, n));

	variance(array, n);

	fclose(fp1);
	system("pause");
	return 0;
}