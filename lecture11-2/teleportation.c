#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main() {
	unsigned char parts[16];
	for (int i = 0; i < 16; i++) scanf("%hhx", parts + i);

	printf("%lu\n", construct(parts));

	return 0;
}

unsigned long int construct(unsigned char parts[16]) {
	unsigned long int a = 0;
	unsigned long int b = 0;

	for (int i = 0; i < 8; i++) {
		a |= (unsigned long int)parts[i] << i*8;
		b |= (unsigned long int)parts[i + 8] << i*8;
	}
	//  printf("%lx %lx\n\n%lx\n", a, b, a ^ b);
	//  printf("%lx\n", 3515645021722633436u);

	return a ^ b;
}
