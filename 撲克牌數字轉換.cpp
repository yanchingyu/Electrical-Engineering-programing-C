#include <stdio.h>
#include <stdlib.h>

#define number 8

int XXX(char array[], char shape[], int NumberSort[], int shape2[]);
int NumberChange(char array[]);
int color(char shape[]);
char GGC(int NumberSort[], int shape2[]);

int main() {
	char array[number], shape[number];
	int NumberSort[number], shape2[number];

	for (int i = 0; i < 8; i++) {
		printf("input %d number and shape:", i);
		scanf("%s %s", &array[i], &shape[i]);
		if (array[i] == '1') {
			array[i] = 10;
		}
	}
	NumberChange(array);
	color(shape);
	XXX(array, shape, NumberSort, shape2);
	for (int i = 0; i <= 6; i++) {
		if (NumberSort[i] == NumberSort[i + 1]) {
			if (shape2[i] > shape2[i + 1]) {
				int min;
				min = shape2[i + 1];
				shape2[i + 1] = shape2[i];
				shape2[i] = min;
			}
		}
	}
	//GGC(NumberSort, shape2);				//這個有錯 
	for (int i = 0; i < 8; i++) {
		if (NumberSort[i] == 1)
			printf("A");
		else if (NumberSort[i] == 11)
			printf("J");
		else if (NumberSort[i] == 12)
			printf("Q");
		else if (NumberSort[i] == 13)
			printf("K");
		else
			printf("%d", NumberSort[i]);
		if (shape2[i] == 4)
			printf("s ");
		else if (shape2[i] == 3)
			printf("h ");
		else if (shape2[i] == 2)
			printf("d ");
		else if (shape2[i] == 1)
			printf("p ");
		else
			printf("error!");
	}

	system("pause");
	return 0;
}

int XXX(char array[], char shape[], int NumberSort[], int shape2[]) {
	int min_array, shape_change;
	int count = 6;

	for (int i = 0; i < number; i++) {
		for (int j = 0; j <= count; j++) {
			if (array[j] < array[j + 1]) {
				min_array = array[j];
				array[j] = array[j + 1];
				array[j + 1] = min_array;

				shape_change = shape[j];
				shape[j] = shape[j + 1];
				shape[j + 1] = shape_change;
			}
			else if (j == count && array[j] > array[j + 1]) {
				min_array = array[j + 1];
				shape_change = shape[j + 1];
			}
		}
		NumberSort[i] = min_array;
		shape2[i] = shape_change;
		count--;
	}
	NumberSort[7] = array[0];
	shape2[7] = shape[0];
	return NumberSort[number], shape2[number];

}
int NumberChange(char array[]) {

	for (int i = 0; i < number; i++) {
		switch (array[i]) {
			case 'A': array[i] = 1; break;
			case '2': array[i] = 2; break;
			case '3': array[i] = 3; break;
			case '4': array[i] = 4; break;
			case '5': array[i] = 5; break;
			case '6': array[i] = 6; break;
			case '7': array[i] = 7; break;
			case '8': array[i] = 8; break;
			case '9': array[i] = 9; break;
			case 'J': array[i] = 11; break;
			case 'Q': array[i] = 12; break;
			case 'K': array[i] = 13; break;
			default: break;
		}
	}
	return array[number];
}
int color(char shape[]) {
	for (int i = 0; i < number; i++) {
		switch (shape[i]) {
			case 's': shape[i] = 4; break;	//黑桃
			case 'h': shape[i] = 3; break;	//愛心
			case 'd': shape[i] = 2; break;	//方塊
			case 'p': shape[i] = 1; break;	//梅花
			default: break;
		}
	}
	return shape[number];
}
char GGC(int NumberSort[], int shape2[]) {
	for (int i = 0; i < number; i++) {
		switch (NumberSort[i]) {
			case 1: NumberSort[i] = 'A'; break;
			case 11: NumberSort[i] = 'J'; break;
			case 12: NumberSort[i] = 'Q'; break;
			case 13: NumberSort[i] = 'K'; break;
			default: break;
		}
	}
	for (int i = 0; i < number; i++) {
		switch (shape2[i]) {
			case 1: shape2[i] = 'p'; break;
			case 2: shape2[i] = 'd'; break;
			case 3: shape2[i] = 'h'; break;
			case 4: shape2[i] = 's'; break;
			default: break;
		}
	}
	return NumberSort[number], shape2[number];
}
