#include <stdio.h>
#include <stdlib.h>

const int size=10;

int scan(int a[], int size) {
	int count=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){	//run 完一輪,最大數字在a[size-1], 減i是讓檢查的數字往前挪i格 
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count++;
			}
		}
	} 
	return count;
}

int main() {
	int count;
	int a[] = { 3,2,6,2,4,1,8,7,6,5 };

	count = scan(a, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n==>%d \n", count);

	system("pause");
	return 0;
}
