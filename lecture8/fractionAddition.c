#include <stdio.h>

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);

int main() {
	int a_numerator, a_denominator, b_numerator, b_denominator;
	scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
	int c_numerator, c_denominator;
	fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator, &c_denominator);
	printf("%d/%d\n", c_numerator, c_denominator);
	return 0;
}

void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr) {
	*c_numerator_ptr = a_numerator * b_denominator + a_denominator * b_numerator;
	*c_denominator_ptr = a_denominator * b_denominator;
	/* printf("%d/%d\n", *c_numerator_ptr, *c_denominator_ptr); */

	// gcd 
	int a = *c_numerator_ptr;
	int b = *c_denominator_ptr;
	while ((a %= b) && (b %= a)) ;
	a = a ? a : b;

	*c_numerator_ptr /= a;
	*c_denominator_ptr /= a;
	return;
}
