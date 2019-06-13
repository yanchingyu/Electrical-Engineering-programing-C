#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
	int order;
	char ser[7];
	char ID[10];
	char name[5];
	char smail[30];
	char imail[30];
};

int main() {
	FILE *file;
	Student *data = NULL;

	file = fopen("C:\\Users\\student\\Downloads\\abc.txt", "r");
	if (file == NULL)
		return 0;

	int order, count = 0;
	char ser[7], ID[10], name[5], smail[30], imail[30];

	while (!feof(file)) {
		fscanf(file, "%d %s %s %s %s %s", &order, ser, ID, name, smail, imail);
		count++;
	}
	fclose(file);

	data = new Student[count];
	file = fopen("C:\\Users\\student\\Downloads\\abc.txt", "r");
	if (file == NULL)
		return 0;
	
	for (int i = 0; i < count - 1; i++) {
		fscanf(file, "%d %s %s %s %s %s", &data[i].order, data[i].ser, data[i].ID, data[i].name, data[i].smail, data[i].imail);
		if (data[i].ID[0] != 'A' || data[i].ID[1] != '7' || data[i].ID[2] != '2') {
			printf("%d %s %s %s %s %s\n", data[i].order, data[i].ser, data[i].ID, data[i].name, data[i].smail, data[i].imail);

		}
	}

	fclose(file);

	system("pause");
	return 0;

}