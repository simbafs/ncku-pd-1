#include <stdio.h>
#include <string.h>

#define move_forward 0x01
#define attack 0x02
#define withstand 0x03

unsigned int parseCmd(const char *str) {
	if (strcmp(str, "PATA PATA PATA PON") == 0) return move_forward;
	if (strcmp(str, "PON PON PATA PON") == 0) return attack;
	if (strcmp(str, "CHAKA CHAKA PATA PON") == 0) return withstand;
	return 0x00;
}

int main() {
	int distance, hp;
	scanf("%d %d", &distance, &hp);
	getchar();	// \n

	char cmdstr[100] = {};
	int cmdstrIndex = 0;
	char c = 0;
	int totalCmd = 0;
	int validCmd = 0;
	do {
		c = getchar();
		if (c == ',' || c == '.' || c == '\n') {
			cmdstr[cmdstrIndex++] = '\0';
			unsigned int movement = parseCmd(cmdstr);
			switch (movement) {
				case move_forward:
					//  printf("move_forward\n");
					distance--;

					validCmd++;
					totalCmd++;
					break;
				case attack:
					//  printf("attack\n");
					if (distance <= 3) {
						hp--;
					}

					validCmd++;
					totalCmd++;
					break;
				case withstand:
					//  printf("withstand\n");
					distance++;

					validCmd++;
					totalCmd++;
					break;
				case 0x00:
					totalCmd++;
			}

			if (hp <= 0) {
				printf("YES %d\n", validCmd);
				return 0;
			}
			if (distance <= 0 || (totalCmd % 10 == 0 && movement != withstand)) {
				printf("NO %d\n", hp);
				return 0;
			}
			cmdstrIndex = 0;
		} else {
			cmdstr[cmdstrIndex++] = c;
		}
	} while (c != '\n');

	printf("NO %d\n", hp);
	//  printf("distance = %d, movement = %lld\n", distance, movement);
	return 0;
}
