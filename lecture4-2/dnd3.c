#include <stdio.h>

#define NUMBER_1 0x38E38E38E38E3800LLU
#define NUMBER_2 0x2AAAAAAAAAAAAAAALLU
#define NUMBER_3 0x1C71C71C71C71C71LLU
#define mod 0x7CE66C50E2840000LLU

int main() {
	unsigned long long int d1, d2, d3;
	scanf("%llu %llu %llu", &d1, &d2, &d3);
	printf("%llu\n", (((d1 * NUMBER_1) % mod + (d2 * NUMBER_2) % mod) % mod + (d3 * NUMBER_3) % mod) % mod);
	return 0;
}
