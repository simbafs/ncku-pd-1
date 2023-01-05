#include <stdio.h>

#define land 0
#define dike 1
#define house 2

int beginX, beginY;
int map[5][5] = {{0}};
int has[5][5] = {{0}};

// take the current (x, y), return how many house are distoried.
int flood(int x, int y, int distoried) {
	if (has[x][y]) return distoried;
	has[x][y] = 1;

	//  printf("> %d %d %d\n", x, y, distoried);
	if (map[x][y] == house) {
		distoried++;
		//  printf(">> %d %d\n", x, y);
	}
	if (map[x][y] != dike) {
		if (x > 0) distoried = flood(x - 1, y, distoried);
		if (x < 4) distoried = flood(x + 1, y, distoried);
		if (y > 0) distoried = flood(x, y - 1, distoried);
		if (y < 4) distoried = flood(x, y + 1, distoried);
	}

	return distoried;
}

int main() {
	scanf("%d %d", &beginX, &beginY);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", flood(beginX, beginY, 0));

	return 0;
}
