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

#define W_INVALID 0
#define W_ALPHABAT 1
#define W_PUNTUATION 2
// invalid -> 0
// a-zA-Z -> 1;
// .,!? -> 2;
int characterType(char c) {
	if ('a' <= c && c <= 'z') return W_ALPHABAT;
	if ('A' <= c && c <= 'Z') return W_ALPHABAT;
	if (c == '.' || c == ',' || c == '!' || c == '?') return W_PUNTUATION;
	return W_INVALID;
}

void recovery(char *homework) {
	char *read = homework;
	char *write = homework;

	while (*read != '\0') {
		int len = nextWordLen(read);

		int flag = 1;
		if (len < 1 || len > 21) {
			flag = 0;
		} else {
			for (int i = 0; i < len; i++) {
				//  if(characterType(read[i]) == 2){
				//      printf("> %c i = %d, len = %d\n", read[i], i, len);
				//  }
				if (!characterType(read[i]) ||	// invalid character
					(characterType(read[i]) == W_PUNTUATION &&
					 i != len - 1)) {  // the last is puntuation
					flag = 0;
					break;
				}
			}
			if (characterType(read[0] == W_PUNTUATION)) {
				flag = 0;
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

		// jump to next character
		read += len + 1;
	}
	*write = '\0';
}
