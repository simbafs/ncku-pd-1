#include <stdio.h>
#define AMERICANO 110
#define LATTE 150
#define CAPPUCCINO 135
#define MOCHA 145

int main() {
	int i = 0;
	int j = 0;
	int total = 0;
	scanf("%d %d", &i, &j);
	switch (i) {
		case 1:
			total = AMERICANO * j;
			break;
		case 2:
			total = LATTE * j;
			break;
		case 3:
			total = CAPPUCCINO * j;
			break;
		case 4:
			total = MOCHA * j;
			break;
		default: 
			printf("Wait, what?");
			return 0;
	}
	printf("The total price is %d dollars!", total);
	return 0;
}
