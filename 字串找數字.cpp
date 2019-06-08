#include <stdio.h>
#include <stdlib.h>

int main() {
	char x[1000];

	scanf("%s", x);

	int xStart = 0;
	while (x[xStart] != '\0') {
		int score = 0, count = 1;
		while(x[xStart] >= '0' && x[xStart] <= '9') {
			score = score * count + (x[xStart] - '0');

		
			count = 10;
			xStart++;
		}
		if(x[xStart - 1] >= '0' && x[xStart - 1] <= '9')
			printf("%d ", score);
		xStart++;
	}



	system("pause");
	return 0;
}