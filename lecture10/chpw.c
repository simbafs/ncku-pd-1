#include <stdio.h>
#include <string.h>

#define SIZE 25

int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

int main() {
	char password1[SIZE];
	char password2[SIZE];

	// Enter the password
	scanf("%s", password1);
	// Enter the password again
	scanf("%s", password2);

	// Check Password
	// First: Check length
	if (length(password1, password2) == 1) {
		printf("Length does not match the requirements");
	} else {
		// Second: Check for consistency
		if (compare(password1, password2) == 1) {
			printf("Not the same password");
		} else {
			// Third: Check for compliance
			if (content(password1) == 1) {
				printf("Do not satisfy the conditions");
			} else {
				printf("Everything is good");
			}
		}
	}

	return 0;
}

int len(char *str) {
	int i = 0;
	for (; *(str + i) != '\0'; i++)
		;
	return i;
}

int l1 = 0;
int l2 = 0;

int length(char pwd1[], char pwd2[]) {
	l1 = len(pwd1);
	l2 = len(pwd2);
	if (l1 < 6 || l1 > 16) return 1;
	if (l2 < 6 || l2 > 16) return 1;
	return 0;
}

int compare(char pwd1[], char pwd2[]) {
	if (l1 != l2) return 1;
	for (int i = 1; i < l1; i++) {
		if (pwd1[i] != pwd2[i]) return 1;
	}
	return 0;
}

int content(char pwd1[]) {
	int uppercase = 0;
	int lowercase = 0;
	int digit = 0;
	for (; *pwd1 != '\0'; pwd1++) {
		if('a' <= *pwd1 && *pwd1 <= 'z') lowercase = 1;
		if('A' <= *pwd1 && *pwd1 <= 'Z') uppercase = 1;
		if('0' <= *pwd1 && *pwd1 <= '9') digit = 1;
		if(uppercase && lowercase && digit) return 0;
	}
	return 1;
}
