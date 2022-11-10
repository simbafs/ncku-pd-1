#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define bExRate 0.2966f
#define aExRate 0.2178f
#define bTaxRate 1.08f
#define aTaxRate 1.10f

int main() {
	long int unTax = 0;
	long int before, after;
	scanf("%ld", &unTax);

	// tax
	before = lround(unTax * (unTax > 5000 ? 1 : bTaxRate));
	after = lround(unTax * (unTax > 5000 ? 1 : aTaxRate));
	//  printf("> %ld -> %ld %ld\n", unTax, before, after);

	// ex
	before = lround(before * bExRate);
	after = lround(after * aExRate);
	//  printf("> -> %ld %ld\n", before, after);


	printf("%ld\n", labs(before - after));

	return 0;
}
