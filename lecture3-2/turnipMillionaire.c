#include <stdio.h>
#define w 0.9
#define u 0.1
#define b -51
#define U -0.98
#define B 153

int main() {
	float xt;
	float ht = 0;
	scanf("%f", &xt);
	for (int i = 0; i < 5; ++i) {
		ht = w * xt + u * ht + b;
		xt = U * ht + B;
		printf("%.1f ", xt);
	}
}
