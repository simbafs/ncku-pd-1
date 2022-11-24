#include <stdio.h>
#include <string.h>

#define move_forward 0x01
#define attack 0x02
#define withstand 0x03

void printBits(unsigned long long n) {
	for (int i = 63; i >= 0; i--) {
		putchar((n >> i) & 0x01 ? '1' : '0');
	}
	putchar('\n');
}

unsigned long long parseCmd(const char *str) {
	if (strcmp(str, "PATA PATA PATA PON") == 0) return move_forward;
	if (strcmp(str, "PON PON PATA PON") == 0) return attack;
	if (strcmp(str, "CHAKA CHAKA PATA PON") == 0) return withstand;
	return 0x00;
}

int main() {
	int distance, hp;
	scanf("%d %d", &distance, &hp);
	getchar();	// \n

	unsigned long long movements = 0;
	int movementsIndex = 0;

	char cmdstr[100] = {};
	int cmdstrIndex = 0;
	char c = 0;
	do {
		c = getchar();
		if (c == ',' || c == '.' || c == '\n') {
			cmdstr[cmdstrIndex++] = '\0';
			unsigned long long movement = parseCmd(cmdstr);
			if (movement != 0x00) {
				movements = movements | (movement << 2 * movementsIndex);
				movementsIndex++;
				//      printf("%s -> 0x%02llx\n", cmdstr, movement);
				//      printBits(movements);
				//  } else {
				//      printf("%s -> not a cmd\n", cmdstr);
			}
			cmdstrIndex = 0;
		} else {
			cmdstr[cmdstrIndex++] = c;
		}
	} while (c != '\n');
	//  printBits(movements);

	int i = 1;
	while (movements) {
		unsigned long long movement = movements % (1 << 2);
		switch (movement) {
			case move_forward:
				//  printf("move_forward\n");
				distance--;
				break;
			case attack:
				//  printf("attack\n");
				if (distance <= 3) {
					hp--;
				}
				break;
			case withstand:
				//  printf("withstand\n");
				distance++;
				break;
		}

		if (hp <= 0) {
			printf("YES %d\n", i);
			return 0;
		}
		if (distance <= 0 || (i % 10 == 0 && movement != withstand)) {
			printf("NO %d\n", hp);
			return 0;
		}
		i++;
		movements = movements >> 2;
	}
	printf("NO %d\n", hp);
	//  printf("distance = %d, movement = %lld\n", distance, movement);
	return 0;
}
