#include <stdio.h>

int main() {
	int d1, d2, d3, d4, d5, d6;
	scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
	if (d1 + d2 + d3 <= 10) {
		if (d4 == d5 && d5 == d6) {
			printf("Player attacks: Critical Hit");
		} else if (d4 + d5 >= d6) {
			printf("Player attacks: Normal Hit");
		} else {
			printf("Player attacks: Miss");
		}
	}else {
		if (d4 == d5 || d5 == d6 || d4 == d6) {
			printf("Dragon attacks: Miss");
		} else if (d4 + d5 != d6) {
			printf("Dragon attacks: Normal Hit");
		} else {
			printf("Dragon attacks: Critical Hit");
		}
	}
	return 0;
}
