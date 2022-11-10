#include <stdio.h>

int money(int n) {
	if (1 <= n && n <= 10) return 10;
	if (11 <= n && n <= 20) return 20;
	if (21 <= n && n <= 30) return 30;
	return 0;
}

int main() {
	int n = 0;
	int vender[30] = {};
	int earned = 0;

	// init vender
	for (int i = 0; i < 30; i++) {
		vender[i] = 10;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int number, count;
		scanf("%d %d", &number, &count);
		if (vender[number - 1] < count) {
			count = vender[number - 1];
		}

		vender[number - 1] -= count;
		earned += count * money(number);
	}

	for (int j = 0; j < 30; j++) {
		printf("%d ", vender[j]);
		if (j == 9 || j == 19 || j == 29) printf("\n");
	}
	printf("Earned: $%d\n", earned);

	return 0;
}
