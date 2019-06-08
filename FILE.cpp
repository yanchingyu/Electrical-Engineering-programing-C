#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int a[], int n) {
	for(int i=0;i<n;i++){
		int change=0;
		for (int j = 0; j < n-1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				change++;
			}
		}
		if(change==0)
			break;
	}
	
}

void average(int a[], int n) {
	double total=0;
	
	for (int i = n/10; i < n-(n/10); i++) {
		total += a[i];
	}
	printf("%0.2f",(total*1.0) / (n - (n / 10) * 2));
}

int main() {
	FILE *fp1;
	int *a, n;

	fp1 = fopen("C:\\Users\\yan\\Downloads\\bbb.txt","r");
	if(fp1 == NULL) 
		return 0;
	
	fscanf(fp1,"%d",&n);
	a = new int[n];
	
	for(int i=0;i<n;i++){
		fscanf(fp1,"%d",&a[i]);
		printf("%d\n",a[i]);
	
	}
	
	bubbleSort(a, n);
	average(a, n);

	fclose(fp1);

	system("pause");
	return 0;
}
