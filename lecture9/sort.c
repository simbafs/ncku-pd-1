#include <stdio.h>
#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr);

int main() {
	int N, a, b;
	scanf("%d%d%d", &N, &a, &b);
	int arr[ARR_MAX] = {0};
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}
	sort_section(&arr[a], &arr[b]);
	for (int i = 0; i < N; i++) {
		printf("%d ", *(arr + i));
	}
}

void printSection(int *ptr, int *qtr) {
	for (int *i = ptr; i <= qtr; i++) {
		printf("%d ", *i);
	}
	printf("\n");
}

void swapIfNeed(int *ptr, int *qtr) {
	if (*ptr > *qtr) {
		//  printf("swap %d %d\n", *ptr, *qtr);
		int c = *ptr;
		*ptr = *qtr;
		*qtr = c;
	}
}

void sort_section(int *ptr, int *qtr) {
	if(ptr > qtr){
		int *c = ptr;
		ptr = qtr;
		qtr = c;
	}
	if (ptr >= qtr) return;
	for (int *i = ptr; i < qtr; i++) {
		for (int *j = ptr; j < qtr; j++) {
			swapIfNeed(j, j+1);
		}
		printSection(ptr, qtr);
	}
}
