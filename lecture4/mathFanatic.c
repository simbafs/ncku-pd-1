#include <stdio.h>

int main() {
	unsigned long long int n = 0;
	unsigned long long int sum = 0;
	unsigned long long int Sn = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n ; i++) {
		scanf("%lld", &Sn);
		sum += Sn;
		if (sum % Sn == 0) {
			printf("%lld %lld\n", sum, Sn);
		}
	}
	return 0;
}
