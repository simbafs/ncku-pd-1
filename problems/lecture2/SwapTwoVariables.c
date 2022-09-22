#include <stdio.h>

int main(void) {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	a ^= b;
	b ^= a;
	a ^= b;
	printf("%d %d", a, b);
	return 0;
}
