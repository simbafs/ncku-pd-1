#include <stdio.h>
#include <stdlib.h>

int array[1500];
int maxChandy(int size);

int main() {
	int size = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; ++i) {
		scanf("%d", &array[i]);
	}
	printf("%d\n", maxChandy(size));
	return 0;
}

int choose(int n, int isChoosen);
int max(int a, int b);

int arrayCacheChoosen[1500] = {};
int arrayCache[1500] = {};
int end = 0;

int maxChandy(int size) {
	// init
	for (int i = 0; i < size; i++) {
		arrayCache[i] = -1;
		arrayCacheChoosen[i] = -1;
	}
	end = size;
	int a = choose(0, 0);
	int b = choose(0, 1);

	/* for (int i = 0; i < size; i++) { */
	/*     printf("%d ", arrayCache[i]); */
	/* } */
	/* printf("\n"); */
	/* for (int i = 0; i < size; i++) { */
	/*     printf("%d ", arrayCacheChoosen[i]); */
	/* } */
	/* printf("\n"); */
	return a > b ? a : b;
}

int max(int a, int b) { return a > b ? a : b; }

// if `n` `isChoosen`, the sum
int choose(int n, int isChoosen) {
	// cache
	int *cache = isChoosen ? arrayCacheChoosen : arrayCache;
	if (cache[n] != -1) return cache[n];

	// only one
	if (n == end - 1) return array[n];
	if (n == end - 2) return isChoosen ? array[n] : array[n + 1];

	int maximum = 0;
	for (int i = (isChoosen ? n + 2 : n + 1); i < end; i++) {
		maximum = max(maximum, max(choose(i, 0), choose(i, 1)));
	}

	/* printf("n = %d, isChoosen = %d, maximum = %d\n", n, isChoosen, maximum); */
	maximum += isChoosen ? array[n] : 0;
	cache[n] = maximum;

	return maximum;
}

// 0 1 2 3 4 5 6 7 8 9 10
// 6 3 8 8 2 8 2 2 4 8 9
// v   v     v     v   v = 35
//
// v x v
// x ? ?
//
// v x ? ?
// x ? ? ?
//
// v x ? ? ?
// x ? ? ? ?
//
// v x ? ? ? ?
// x ? ? ? ? ?
