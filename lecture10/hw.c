#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main() {
	char homework[MAX_LEN + 1];

	// Get the homework content.
	fgets(homework, MAX_LEN, stdin);
	recovery(homework);

	// Print the recovered homework.
	fputs(homework, stdout);

	return 0;
}

int nextWordLen(char *str) {
	int i = 0;
	for (; str[i] != ' ' && str[i] != '\0' && str[i] != '\n'; i++)
		;
	return i;
}

// invalid -> 0
// a-zA-Z -> 1;
// .,!? -> 2;
int wordType(char c) {
	if ('a' <= c && c <= 'z') return 1;
	if ('A' <= c && c <= 'Z') return 1;
	if (c == '.' || c == ',' || c == '!' || c == '?') return 2;
	return 0;
}

void recovery(char *homework) {
	char *read = homework;
	char *write = homework;

	for (; *read != '\0';) {
		int len = nextWordLen(read);

		int flag = 1;
		if (len < 1 || len > 21) {
			flag = 0;
		} else {
			for (int i = 0; i < len; i++) {
				//  if(wordType(read[i]) == 2){
				//      printf("> %c i = %d, len = %d\n", read[i], i, len);
				//  }
				if (!wordType(read[i]) ||
					(wordType(read[i]) == 2 && i != len - 1)) {
					flag = 0;
					break;
				}
			}
		}

		if (flag) {
			for (int i = 0; i < len; i++) {
				*write = read[i];
				write++;
			}
			*write = ' ';
			write++;
		}

		//  printf("i = %ld, len = %d, flag = %d\n", read - homework, len,
		//  flag);

		// jump to next word
		read += len + 1;
	}
	*write = '\0';
}
