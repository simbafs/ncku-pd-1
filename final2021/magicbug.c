#include <stdio.h>

void printBinary(unsigned long int addr) {
	for (int i = 63; i >= 0; i--) {
		putchar((addr >> i) & 0x01 ? '1' : '0');
		if (i % 8 == 0) putchar(' ');
	}
	putchar('\n');
}

int main() {
	int N, stb;
	unsigned long int addr, mask = 0xff;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d-0x%lx", &stb, &addr);
		addr = addr & (mask << stb);
		printBinary(addr);
	}
	return 0;
}
