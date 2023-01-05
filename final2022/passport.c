#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 15

void convert(char *last, char *first);

int main() {
	char last_name[MAX_LEN + 2];
	char first_name[MAX_LEN + 2];

	// Enter last name
	fgets(last_name, MAX_LEN * 2, stdin);
	if (last_name[strlen(last_name) - 1] == '\n')
		last_name[strlen(last_name) - 1] = '\0';

	// Enter first name
	fgets(first_name, MAX_LEN * 2, stdin);
	if (first_name[strlen(first_name) - 1] == '\n')
		first_name[strlen(first_name) - 1] = '\0';

	// Convert and print the name by using the function convert
	convert(last_name, first_name);

	return 0;
}

char toUppercase(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
	return c;
}

int isAlphabat(char c) { return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'; }

void convert(char *last, char *first) {
	if (strlen(last) > 15 || strlen(first) > 15) {
		printf("illegal\n");
		return;
	}

	for (char *c = last; *c; c++) {
		if (isAlphabat(*c)) putchar(toUppercase(*c));
		else putchar(' ');
	}
	putchar(',');
	putchar(' ');
	for(char *c = first; *c; c++){
		if (isAlphabat(*c)) putchar(toUppercase(*c));
		else putchar('-');
	}
}
