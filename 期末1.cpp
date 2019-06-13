#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char x[1000] = {'i'};
	char *str;
	scanf("%s", &x);

	int xStart = 0;
	while (x[xStart] != '\0' && x[xStart] != 'i') {
		while(x[xStart] >= '0' && x[xStart] <= '9') {
			
			xStart++;
		}
		printf("%c", x[xStart]);
		xStart++;
		
	}

	system("pause");
	return 0;
}