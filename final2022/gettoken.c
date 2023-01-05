#include <stdio.h>
#include <stdlib.h>

char *strtok(char *s, const char *sep) {
	printf("strtok banned\n");
	exit(1);
}

char *strtok_r(char *str, const char *sep, char **lasts) {
	printf("strtok_r banned\n");
	exit(1);
}

char *strsep(char **stringp, const char *delim) {
	printf("strsep banned\n");
	exit(1);
}

char *gettoken(char *str, const char *sep);

int main() {
	char buffer[4096];
	char *sep = " \t\n;,.?!";
	char *word;
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		fgets(buffer, 4095, stdin);
		for (word = gettoken(buffer, sep); word != NULL;
			 word = gettoken(NULL, sep)) {
			printf("%s\n", word);
		}
	}
}

#include <string.h>
char *s = NULL;

char *gettoken(char *str, const char *sep) {
	if (str == NULL) {
		str = s;
	} else {
		s = str;
	}

	if (!(*s)) return NULL;
	if(s == NULL) return NULL;

	char *result = malloc(sizeof(char) * 40);
	int resultIndex = 0;

	long begin = strcspn(s, sep);

	for (int i = 0; i < begin; i++) {
		result[resultIndex++] = *(s + i);
	}
	result[resultIndex++] = '\0';

	long next = strspn(s + begin, sep);

	s += begin + next;

	return result;
}
