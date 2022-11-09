#include <stdio.h>
#include <stdlib.h>

struct Str {
	char str[20];
	int id;
	int len;
};

char normalize(char c) {
	if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
	return c;
}

int cmp(const void *a, const void *b) {
	struct Str *c = (struct Str *)a;
	struct Str *d = (struct Str *)b;
	for (int i = 0; i < c->len && i < d->len; i++) {
		if (normalize(c->str[i]) < normalize(d->str[i]))
			return -1;
		else if (normalize(c->str[i]) > normalize(d->str[i]))
			return 1;
	}
	return c->len - d->len;
}

int main() {
	int N;
	scanf("%d", &N);
	struct Str student[40];

	for (int i = 0; i < N + 1; i++) {
		scanf("%d %s", &(student[i].len), student[i].str);
		student[i].id = i;
	}

	qsort(student, N + 1, sizeof(student[0]), &cmp);

	for (int i = 0; i < N + 1; i++) {
		if (student[i].id == 0) {
			printf("%d\n", i + 1);
			return 0;
		}
	}

	return 0;
}
