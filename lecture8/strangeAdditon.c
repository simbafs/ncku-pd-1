#include <stdint.h>
#include <stdio.h>

typedef union v32_union {
	float f;
	uint32_t u;
} v32;

uint32_t float2int(float f) {
	int n = 0;
	uint32_t mask = 1 << 31;
	v32 v;
	v.f = f;

	do {
		n |= v.u & mask;
	} while (mask >>= 1);

	return n;
}

void print_int_bit(uint32_t n) {
	uint32_t mask = 1 << 31;
	do {
		if (mask == 0x800000 || mask == 0x8000 || mask == 0x80) putchar(' ');
		putchar(n & mask ? '1' : '0');
	} while (mask >>= 1);
}

int main(void) {
	float a, b;
	scanf("%f %f", &a, &b);
	uint32_t fa, fb;
	fa = float2int(a);
	fb = float2int(b);

	printf("   ");
	print_int_bit(fa);
	printf("\n");
	
	printf("+) ");
	print_int_bit(fb);
	printf("\n");

	printf("---------------------------------------\n");
	
}
