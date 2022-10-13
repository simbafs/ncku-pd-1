#include <stdio.h>

char normalize(char c) {
	if (c >= 'a' && c <= 'z') return c;
	if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
	return c;
}

int isAlphabet(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

int main() {
	int shouldBeCapital = 1;
	char c = 0;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; scanf("%c", &c)) {
		if (c == ',' || c == ';' || c == '.') {
			printf("\n");
			shouldBeCapital = 1;
			i++;
		} else if (c == ' ') {
			printf(" ");
			shouldBeCapital = 1;
		} else if (isAlphabet(c)){
			/* fprintf(stderr, "%c %d %d\n", c, c, shouldBeCapital); */
			printf("%c", normalize(c) + (shouldBeCapital ? 'A' - 'a' : 0));
			shouldBeCapital = 0;
		}
	}
	return 0;
}
