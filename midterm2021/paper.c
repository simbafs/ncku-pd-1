#include <stdio.h>

int main() {
	int paper[105][105] = {{}};
	int N;
	scanf("%d", &N);

	// input
	int n;
	while (1) {
		int reference;
		scanf("%d", &n);
		if (n == 0) break;
		while (1) {
			scanf("%d", &reference);
			paper[n][reference] = 1;
			if (getchar() != ' ') {
				break;
			}
		}
	}

	// print
	//  for (int i = 1; i <= N; i++) {
	//      for (int j = 1; j <= N; j++) {
	//          printf("%d ", paper[i][j]);
	//      }
	//      printf("\n");
	//  }
	//  printf("\n");

	// process
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!paper[i][j]) continue;
			for (int k = 0; k <= N; k++) {
				if (paper[k][i]) paper[k][j] = 1;
			}
		}
	}

	// add itself
	for(int i = 1; i <= N; i++){
		paper[i][i] = 1;
	}

	// print
	//  for (int i = 1; i <= N; i++) {
	//      for (int j = 1; j <= N; j++) {
	//          printf("%d ", paper[i][j]);
	//      }
	//      printf("\n");
	//  }

	// out
	for(int i = 1; i <= N; i++){
		printf("%d -> ", i);
		for(int j = 1; j <= N; j++){
			if(paper[i][j]) printf("%d ", j);
		}
		printf("\n");
	}

	return 0;
}
