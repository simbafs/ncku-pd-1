#include <stdio.h>

int page[100][100] = {{}};
int connectN[100] = {};
float pr1[100] = {};
float pr2[100] = {};
float *pr = pr1;
float *newPr = pr2;

int main() {
	int N = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int c;
		while (1) {
			scanf("%d", &c);
			if (c == -1) break;
			page[i][c] = 1;
			connectN[i]++;
		}
	}
	// init pr
	for (int i = 0; i < 100; i++) {
		pr1[i] = pr2[i] = 1.0/N;
	}

	for (int n = 0; n < 1; n++) {
		for(int i = 0; i < N; i++){
			float tmp = 0;
			printf("> %d\n", i);
			for(int j = 0; j < N; j++){
				if(!page[i][j]) continue;
				printf(">> pr[%d] = %f, connectN = %d\n", j, pr[j], connectN[j]);
				tmp += pr[j]/connectN[j];
			}
			newPr[i] = tmp;
		}
		float *tmp = pr;
		pr = newPr;
		newPr = tmp;
	}

	for(int i = 0; i < N; i++){
		printf("%.2f ", pr[i]/3);
	}
	printf("\n");
}
