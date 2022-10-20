#include <stdio.h>

int main() {
	// because the memory limit, use char insteak of int
	char bingoTable[8][8] = {{}};
	char reverseBingoTable[256] = {};
	int tmp = 0;
	int flag = 1;
	int N = 0;

	// set default
	for (int i = 0; i < 256; i++) {
		reverseBingoTable[i] = -1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%d", &tmp);
			tmp--;
			reverseBingoTable[tmp] = i * 8 + j;
		}
	}
	for (int k = 0; k < 64; k++) {
		int i, j;
		scanf("%d", &tmp);
		tmp--;	// because tmp is 1~256, we want 0~255
		if (reverseBingoTable[tmp] == -1) continue;
		i = reverseBingoTable[tmp] / 8;
		j = reverseBingoTable[tmp] % 8;
		printf("> %d %d %d\n", tmp, i, j);
		bingoTable[i][j] = 1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d ", bingoTable[i][j]);
		}
		printf("\n");
	}

	// horizen
	for (int i = 0; i < 8; i++) {
		flag = 1;
		for (int j = 0; j < 8; j++) {
			if (!bingoTable[i][j]) {
				flag = 0;
				break;
			}
		}
		N += flag;
	}

	// vertical
	for (int j = 0; j < 8; j++) {
		flag = 1;
		for (int i = 0; i < 8; i++) {
			if (!bingoTable[i][j]) {
				flag = 0;
				break;
			}
		}
		N += flag;
	}

	// diagnal
	flag = 1;
	for (int i = 0; i < 8; i++) {
		if (!bingoTable[i][i]) {
			flag = 0;
			break;
		}
	}
	N += flag;

	flag = 1;
	for (int i = 0; i < 8; i++) {
		if (!bingoTable[i][8 - i]) {
			flag = 0;
			break;
		}
	}
	N += flag;

	printf("%d\n", N);

	return 0;
}
