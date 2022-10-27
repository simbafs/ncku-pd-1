#include <stdio.h>

int craftTable[22][22] = {{}};

int craft(int n);

int main(){
	int N = 0;
	scanf("%d", &N);
	for(int i = 1; i < N+1; i++){
		int M = 0;
		scanf("%d", &M);
		for(int j = 0; j < M; j++){
			int tmp = 0;
			scanf("%d", &craftTable[i][j]);
		}
	}

	/* // print craft table */
	/* for(int i = 1; i < N+1; i++){ */
	/*     printf("[%d] ", i); */
	/*     for(int j = 0; craftTable[i][j] != 0; j++){ */
	/*         printf("%d ", craftTable[i][j]); */
	/*     } */
	/*     printf("\n"); */
	/* } */

	/* printf("%d\n", craft(1)); */
	int s = 0;
	for(int i = 1; i < N+1; i++){
		s += craft(i);
		/* printf("> %d\n", craft(i)); */
	}

	printf("%d\n", s);
	
	return 0;
}

int craft(int n){
	// origin ingredient
	if(craftTable[n][0] == 0){
		return 1;
	}
	// craftable 
	int s = 0;
	for(int i = 0; craftTable[n][i] != 0; i++){
		s += craft(craftTable[n][i]);
	}
	return s;
}
