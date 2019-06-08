#include <stdio.h>
#include <stdlib.h>

int count = 0;
void hanoi(int n, int from, int to, int temp1, int temp2) {
	if (n == 0) {
		return;
	}
	if (n == 1 ) {
		printf("%d-->%d\n", from, to);
		count++;
		return;
	}
	/*int temp1 = 3, temp2 = 4;
	hanoi(n - 2, from, temp2);
	hanoi(1, from, temp1);
	hanoi(1, temp2, temp1);
	hanoi(1, from, temp2);
	hanoi(n - 2, from, to );*/

	hanoi(n - 2, from, temp2, to, temp1);
	hanoi(1, from, temp1, to, temp2);
	hanoi(1, from, to, temp2, temp1);
	hanoi(1, temp1, to, from, temp2);
	hanoi(n - 2, temp2, to, temp1, from);
}

int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3, 4);
	printf("%d\n", count);

	system("pause");
	return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int n, from = 1, to = 2, temp1 = 3, temp2 = 4;

void isTo1(vector<vector<int> > &hanoi) {
	if(!(hanoi[0].empty())) {
		if (hanoi[1][0] < hanoi[0].back() && hanoi[2][0] == 0) {
			printf("%d ==> %d", from, temp1);
			hanoi[2].push_back(hanoi[0].back());
			hanoi[0].pop_back();
			isTo3(hanoi);
		}
		else if (hanoi[1][0] < hanoi[0].back() && hanoi[3][0] == 0) {
			printf("%d ==> %d", from, temp2);
			hanoi[3].push_back(hanoi[0].back());
			hanoi[0].pop_back();
			isTo4(hanoi);
		}
		else if (hanoi[1][0] < hanoi[0].back() && hanoi[1][0] == 0) {
			printf("%d ==> %d", from, to);
			hanoi[1].push_back(hanoi[0].back());
			hanoi[0].pop_back();
		}
	}
}

void isTo2(vector<vector<int> > &hanoi) {
	if(!(hanoi[1].empty())) {

	}

}

void isTo3(vector<vector<int> > &hanoi) {
	if(!(hanoi[2].empty())) {
		if (hanoi[3][0] == 0 && hanoi[1][0] == 0) {
			isTo1(hanoi);
		}
		
	}
}

void isTo4(vector<vector<int> > &hanoi) {
	while (hanoi[3][0] == 0) {
		if (hanoi[3].back() != 0 && hanoi[2].back() < hanoi[3].back()) {
			printf("%d ==> %d", from, temp2);
			hanoi[3].push_back(hanoi[2].back());
			hanoi[2].pop_back();
		}
	}

}

int main() {
	scanf("%d", &n);
	vector<vector<int> > hanoi(4, vector<int> (n));
	vector<int> v;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			hanoi[i][j] = 0;
		}
	}
	for (int i = n; i > 0; i--) 
		v.push_back(i);
	for (int i = 0; i < n; i++)
		hanoi[0][i] = v[i];
	v.clear();

	isTo1(hanoi);
	




	system("pause");
	return 0;
}
*/