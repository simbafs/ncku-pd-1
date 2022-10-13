#include <stdio.h>
#include <stdlib.h>

int dragonAttact(int d4, int d5, int d6);
int playerAttact(int d4, int d5, int d6);

int main() {
	int dragonHP = 100;
	int playerHP = 100;
	int d1, d2, d3, d4, d5, d6;

	while (dragonHP > 0 && playerHP > 0) {
		scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
		if ((d1 + d2 + d3) % 2) {
			dragonHP -= playerAttact(d4, d5, d6);
		} else {
			playerHP -= dragonAttact(d4, d5, d6);
		}
	}

	if (dragonHP > 0) {
		printf("Dragon wins");
	} else {
		printf("Player wins");
	}

	return 0;
}

int dragonAttact(int d4, int d5, int d6) {
	if (abs(d4 - d5) > d6) {
		return 15;
	} else if (d4 + d5 != d6) {
		return 5;
	}
	return 0;
}

int playerAttact(int d4, int d5, int d6) {
	if (d4 < d5 && d5 < d6) {
		return 25;
	} else if (d4 % 2 == d5 % 2 || d5 % 2 == d6 % 2) {
		return 5;
	}
	return 0;
}
