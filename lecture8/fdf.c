#include <stdio.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1);

int main() {
	unsigned k;
	scanf("%u", &k);

	uint64_t f2k, f2k1;
	fib_fast_doubling(k / 2, &f2k, &f2k1);

	printf("%llu", (k & 0x1) ? f2k1 : f2k);

	return 0;
}

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1) {
	/* printf("k = %d\n", k); */
	if (k == 0) {
		*f2k = *f2k1 = 1;
		return;
	}
	if (k == 1) {
		*f2k = 1;
		*f2k1 = 2;
		return;
	}

	uint64_t fk, fk1;
	if (k & 0x1) {
		uint64_t a, b;
		fib_fast_doubling(k / 2, &a, &b);
		fk = b;
		fib_fast_doubling(k / 2 + 1, &a, &b);
		fk1 = a;
	} else {
		fib_fast_doubling(k / 2, &fk, &fk1);
	}

	/* printf("k = %d, fk = %lld, fk1 = %lld\n", k, fk, fk1); */

	*f2k = fk * (2 * fk1 - fk);
	*f2k1 = fk * fk + fk1 * fk1;
	/* printf("       f2k = %lld, f2k1 = %lld\n", *f2k, *f2k1); */
}
