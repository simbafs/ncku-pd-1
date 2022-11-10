#include <stdio.h>

char magicIndexTable[60] = {'a', 'b', 'c', 'd', 'e'};
char magicTable[60][20] = {};
int magicLevel[60] = {};
int magicAmount[60] = {};

int findIndexByMagic(char c) {
	for (int i = 0; i < 60; i++) {
		if (magicIndexTable[i] == c) return i;
	}
	return -1;
}

int calcLevel(int n) {
	if (n < 5) {
		return 1;
	}
	int maxLevel = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		if (magicTable[n][i] == 0) continue;
		if (magicLevel[i] != 0)
			k = magicLevel[i];
		else
			magicLevel[i] = k = calcLevel(i);
		if (k > maxLevel) maxLevel = k;
	}
	return maxLevel + 1;
}

int calAmount(int n) {
	if (n < 5) return 1;
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (magicTable[n][i] == 0) continue;
		int c;
		if(magicAmount[i] != 0) c = magicAmount[i];
		else magicAmount[i] = c = calAmount(i);
		s += magicTable[n][i] * c;
	}
	printf("> n = %d, s = %d\n", n, s);
	return s;
}

int main() {
	int N = 0;

	scanf("%d", &N);

	for (int i = 5; i < N + 5; i++) {
		getchar();
		char magic;
		int n;
		scanf("%c(%d)", &magic, &n);
		//  printf("> %c %d\n", magic, n);

		magicIndexTable[i] = magic;
		for (int j = 0; j < n; j++) {
			char c = getchar();
			int t = findIndexByMagic(c);
			//  printf(">> %c %d\n", c, t);
			magicTable[i][t]++;
		}
	}
	// get target
	getchar();
	int n;
	scanf("(%d)", &n);

	//  printf("> \n");
	for (int j = 0; j < n; j++) {
		char c = getchar();
		int t = findIndexByMagic(c);
		//  printf(">> %c %d\n", c, t);
		magicTable[N + 5][t]++;
	}

	for(int i = 5; i < N+5; i++){
		for(int j = 0; j < 20; j++){
			printf("%d ", magicTable[i][j]);
		}
		printf("\n");
	}

	printf("%d %d\n", calcLevel(N + 5), calAmount(N + 5));
}
