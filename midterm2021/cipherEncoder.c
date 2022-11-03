#include <stdio.h>

int main() {
	int k;
	char m;
	scanf("%d %c", &k, &m);
	int j = m == 'a' ? 1 : -1;

	char c;
	getchar();
	for (int i = 0; scanf("%c", &c) != EOF;) {
		int b;
		if ('a' <= c && c <= 'z') {
			b = 'a';
		} else if ('A' <= c && c <= 'Z') {
			b = 'A';
		} else {
			putchar(c);
			putchar('\n');
			continue;
		}

		//  putchar((((c-b+k+i*j)%26)+26)%26+b);
		printf("((((%c-%c = %d)+%d+%d*%d)%%26)+26)%%26 = %d\n", c, b, c-b, k, i, j, (((c-b+k+i*j)%26)+26)%26);
		i++;
	}
	return 0;
}
