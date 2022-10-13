#include <stdio.h>

float getGpa(int credit, char grade, char sign) {
	if (grade == 'F') return 0;
	float point = 4 - grade + 'A';
	if (sign == '+')
		point += 0.3;
	else if (sign == '-')
		point -= 0.3;

	return point * credit;
}

int isDigit(char c) { return c >= '0' && c <= '9'; }

int main() {
	char c = '\0';

	int credit = 0;
	char grade = '\0';
	char sign = '\0';

	int totalCredit = 0;
	float totalGpa = 0;

	int isGrade = 0;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') break;
		if (c == ',') continue;
		if (isDigit(c)) {
			// calculate the previous part
			totalGpa += getGpa(credit, grade, sign);
			/* printf("%d %.2f %.2f\n", credit, */
			/*        getGpa(credit, grade, sign) / credit, totalGpa); */

			credit = c - '0';
			totalCredit += credit;
			// state
			isGrade = 1;
			grade = sign = '\0';
		} else if (isGrade) {
			grade = c;
			// state
			isGrade = 0;
		} else {
			sign = c;
		}
	}
	// calculate the last part
	totalGpa += getGpa(credit, grade, sign);
	/* printf("%d %.2f %.2f\n", credit, getGpa(credit, grade, sign) / credit, */
	/*        totalGpa); */

	printf("%.2f\n", totalGpa / totalCredit);
	return 0;
}
