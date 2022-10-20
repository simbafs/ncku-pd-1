#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int c = *(int *)a;
	int d = *(int *)b;
	return c > d;
}

int main() {
	int scores[2000] = {};
	int N, A, B;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", scores + i);
	qsort(scores, N, sizeof(scores[0]), compare);
	/* for (int i = 0; i < N; i++) printf("%d ", scores[i]); */
	/* printf("\n"); */

	scanf("%d", &A);
	while (scanf("%d %d", &B, &A) != EOF) {
		int i = 0;
		int j = 0;
		for (; scores[i] < B && i < N; i++) ;
		j = i;
		printf("%d ", i);
		for (; scores[i] < A && i < N; i++) ;
		printf("%d %d\n", i - j, N - i);
	}
	return 0;
}
