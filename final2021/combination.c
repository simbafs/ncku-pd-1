#include <stdio.h>

// 整理 index，使所有 index 不超過上限
int orgIndex(int *index, int n, int k) {
	// 如果最後一個合法，那一定全部合法
	if (index[k - 1] <= k - 1 + n - k) return 0;
	for (int i = k - 1; i >= 0; i--) {
		if (index[i] < i + n - k) {
			// 第一個不超過上限的位置
			index[i]++;
			for (int j = i + 1; j < k; j++) {
				index[j] = index[j - 1] + 1;
			}
			return 0;
		}
	}

	// 找不到合法的 -> 結束了
	return 1;
}

void printIndex(int *index, int k){
	for(int i = 0; i < k; i++){
		printf("%d ", index[i]);
	}
	printf("\n");
}

int main() {
	int n, k;
	char str[40][40] = {{0}};
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	int index[40] = {0};
	for (int i = 0; i < k; i++) {
		index[i] = i;
	}

	while (1) {
		// print
		for (int i = 0; i < k; i++) {
			printf("%s ", str[index[i]]);
		}
		printf("\n");

		// update index
		index[k - 1]++;
		if (orgIndex(index, n, k) == 1) break;
	}

	return 0;
}
