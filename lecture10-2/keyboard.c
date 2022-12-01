#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main() {
	char line[BUFFER_LEN];
	char buffer[LINE_LEN][BUFFER_LEN];
	char *arr[LINE_LEN];

	int count = 0;
	while (fgets(line, BUFFER_LEN - 1, stdin) != NULL) {
		arr[count] = buffer[count];
		strncpy(buffer[count++], line, BUFFER_LEN - 1);
	}
	convert(arr, count);
	for (int i = 0; i < count; i++) {
		printf("%s", arr[i]);
	}
}

// alhpabet to int
const char a2i[] = {
	['a'] = '2', ['b'] = '2', ['c'] = '2', ['d'] = '3', ['e'] = '3',
	['f'] = '3', ['g'] = '4', ['h'] = '4', ['i'] = '4', ['j'] = '5',
	['k'] = '5', ['l'] = '5', ['m'] = '6', ['n'] = '6', ['o'] = '6',
	['p'] = '7', ['q'] = '7', ['r'] = '7', ['s'] = '7', ['t'] = '8',
	['u'] = '8', ['v'] = '8', ['w'] = '9', ['x'] = '9', ['y'] = '9',
	['z'] = '9',
};

// alpha to times
const char a2t[] = {
	['a'] = '1', ['b'] = '2', ['c'] = '3', ['d'] = '1', ['e'] = '2',
	['f'] = '3', ['g'] = '1', ['h'] = '2', ['i'] = '3', ['j'] = '1',
	['k'] = '2', ['l'] = '3', ['m'] = '1', ['n'] = '2', ['o'] = '3',
	['p'] = '1', ['q'] = '2', ['r'] = '3', ['s'] = '4', ['t'] = '1',
	['u'] = '2', ['v'] = '3', ['w'] = '1', ['x'] = '2', ['y'] = '3',
	['z'] = '4',
};

void convert(char *arr[], int count) {
	for (int i = 0; i < count; i++) {
		char line[BUFFER_LEN];
		int lineIndex = 0;
		//  printf("> %s", arr[i]);
		for (int j = 0; arr[i][j] != '\0'; j++) {
			if (arr[i][j] < 'a' || arr[i][j] > 'z') {
				line[lineIndex++] = arr[i][j];
				continue;
			}
			line[lineIndex++] = '(';
			line[lineIndex++] = a2i[arr[i][j]];
			line[lineIndex++] = ')';
			line[lineIndex++] = a2t[arr[i][j]];
		}
		line[lineIndex++] = '\0';
		//  printf("%s", line);
		strcpy(arr[i], line);
	}
}
