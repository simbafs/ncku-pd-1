#include<stdio.h>
int N;

void solve(int *A, int *B, int *op_cnt);

int main(){
    int A[1<<17] = {0};
    int B[1<<17] = {0};
    int op_cnt = 0;

    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i<N; i++)
        scanf("%d", &B[i]);

    solve(A, B, &op_cnt);
    printf("%d\n", op_cnt);
    for(int i = 0; i<N; i++)
        printf("%d ", A[i]);
}

int swapIfNeed(int *ptr, int *qtr) {
	if (*ptr > *qtr) {
		//  printf("swap %d %d\n", *ptr, *qtr);
		int c = *ptr;
		*ptr = *qtr;
		*qtr = c;
		return 1;
	}
	return 0;
}

void solve(int *A, int *B, int *op_cnt){
	for(int *i = A, *j = B; i < A+N; i++, j++){
		*op_cnt += swapIfNeed(j, i);
	}
}
