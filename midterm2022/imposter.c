#include <stdio.h>

int a2i(char c) {
	char d;
	if ('a' <= c && c <= 'z') d = c - 'a' + 'A';
	else d= c;
	switch (d) {
		case 'A':
		case 'L':
			return 0;
		case 'B':
			return 1;
		case 'C':
		case 'N':
		case 'Z':
			return 2;
		case 'D':
		case 'P':
			return 3;
		case 'E':
		case 'F':
		case 'Q':
			return 4;
		case 'R':
			return 5;
		case 'H':
		case 'S':
			return 6;
		case 'I':
		case 'T':
			return 7;
		case 'J':
		case 'U':
			return 8;
		case 'K':
		case 'V':
			return 9;
	}
	//  printf("<%d>", c-'0');
	return c - '0';
}

int main() {
	char id[10] = "";
	while (scanf("%s", id) != EOF) {
		int s = 0;
		for (int i = 0; i < 9; i++) {
			//  printf("%d ",a2i(id[i]));
			s += a2i(id[i]) * (9 - i);
		}
		//  printf("\n");
		//  printf("%d\n", s);
		if (s % 10 != 0) printf("%s is the imposter!!!\n", id);
	}
	return 0;
}
