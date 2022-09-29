#include <stdio.h>

int printN(char c, int n);

int main() {
	int type, layer;
	scanf("%d %d", &type, &layer);
	switch (type) {
		case 1:
			for (int i = 0; i < layer; ++i) {
				printN('*', layer - i);
				printN('\n', 1);
			}
			break;
		case 2:
			for (int i = 0; i < layer; ++i) {
				printN('*', i + 1);
				printN('\n', 1);
			}
			break;
		case 3:
			for (int i = 0; i < layer; ++i) {
				printN(' ', i);
				printN('*', layer - i);
				printN('\n', 1);
			}
			break;
		case 4:
			for (int i = 0; i < layer; ++i) {
				printN(' ', layer - i - 1);
				printN('*', i + 1);
				printN('\n', 1);
			}
			break;
	}
	return 0;
}

int printN(char c, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%c", c);
	}
	return 0;
}
