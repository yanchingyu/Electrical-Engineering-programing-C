#include <stdio.h>
#include <stdlib.h>

int main(){
	int temp, a[8], count = 0, num = 0;

	for(int i=0;i<8;i++)
		scanf("%d",&a[i]);

	for (int i = num; i < 7; i++) {
		for (int j = num; j < 7; j++) {
			if (a[num] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[num];
				a[num] = temp;
				count++;
			}
		}
		num++;
	}
	for (int i = 0; i < 8; i++)
		printf("%d==>%d\n", i, a[i]);

	printf("%d\n%d", count);			

	system("pause");
	return 0;
}