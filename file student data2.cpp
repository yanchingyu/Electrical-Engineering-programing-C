#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	char name[7];
	char tel[11];
	int score1;
	int score2;
};

int main() {
	FILE *file;
	Student *data = NULL;

	file = fopen("C:\\Users\\yan\\Desktop\\student.txt", "r");
	if (file == NULL)
		return 0;
	
	char name[7], tel[11];
	int score1, score2, count = 0;
	while (!feof(file)) {
		fscanf(file, "%s %s %d %d", name, tel, &score1, &score2);
		count++;
	}
	fclose(file);

	data = new Student[count];
	file = fopen("C:\\Users\\yan\\Desktop\\student.txt", "r");
	if (file == NULL)
		return 0;

	for (int i = 0; i < count; i++) {
		fscanf(file, "%s %s %d %d", data[i].name, data[i].tel, &(data[i].score1), &(data[i].score2));
	}

	fclose(file);

	for (int i = 0; i < count; i++) {
		//if(*data[i].name != *"電機系")
		if (strcmp(data[i].name , "電機系")) {
			printf("%s %s %d %d\n", data[i].name, data[i].tel, data[i].score1, data[i].score2);
		}
	}

	system("pause");
	return 0;
}