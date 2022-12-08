#include <stdio.h>
#include <stdlib.h>
void init(int**** ptr);

int main() {
	int**** ptr = malloc(sizeof(int***) * 2);
	init(ptr);
	int magic_number;
	long long magic_sum = 0;
	scanf("%d", &magic_number);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					ptr[i][j][k][l] = magic_number;
					magic_sum += ptr[i][j][k][l];
				}
			}
		}
	}
	printf("%lld", magic_sum);
}

void init(int**** ptr) {
	for (int i = 0; i < 2; i++) {
		ptr[i] = malloc(sizeof(int**) * 2);
		for (int j = 0; j < 2; j++) {
			ptr[i][j] = malloc(sizeof(int *) * 2);
			for(int k = 0; k < 2; k++){
				ptr[i][j][k] = malloc(sizeof(int) * 2);
			}
		}
	}
}
