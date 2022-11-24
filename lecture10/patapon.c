#include <stdio.h>
#include <string.h>

#define move_forward 0x1112
#define attack 0x2212
#define withstand 0x3312

#define move_forward_i 0x01
#define attack_i 0x02
#define withstand_i 0x03

void printBits(size_t const size, void const *const ptr) {
	unsigned char *b = (unsigned char *)ptr;
	unsigned char byte;
	int i, j;

	for (i = size - 1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}

unsigned long long parseCmd(const char *str) {
	if (strcmp(str, "PATA") == 0) return 0x01;
	if (strcmp(str, "PON") == 0) return 0x02;
	if (strcmp(str, "CHAKA") == 0) return 0x03;
	return 0x00;
}

unsigned long long toI(unsigned long long cmd) {
	if (cmd == move_forward) return move_forward_i;
	if (cmd == attack) return attack_i;
	if (cmd == withstand) return withstand_i;
	return 0;
}

int main() {
	//  printf("%d %d %d\n", parseCmd("PATA"), parseCmd("PON"),
	//  parseCmd("CHAKA"));
	int distance, hp;
	scanf("%d %d", &distance, &hp);
	getchar();	// \n

	unsigned long long movements = 0;
	int movementsIndex = 0;

	char cmdstr[10] = {};
	int cmdstrIndex = 0;
	unsigned long long cmds = 0;
	char c = 0;
	do {
		c = getchar();
		if (c == ' ' || c == ',' || c == '.' || c == '\n') {
			cmdstr[cmdstrIndex++] = '\0';
			cmdstrIndex = 0;
			int cmd = parseCmd(cmdstr);
			//  printf("cmd = %s -> %d\n", cmdstr, cmd);
			if (cmd != 0x00) cmds = (cmds << 4) | cmd;

			if (c != ' ') {
				int i = toI(cmds);
				if (i != 0) {
					//  printf("new movement 0x%llx -> 0x%x\n", cmds, i);
					movements = movements | (i << movementsIndex * 2);
					movementsIndex++;
				}
				cmds = 0;
			}
			continue;
		}
		cmdstr[cmdstrIndex++] = c;
	} while (c != '\n');
	//  printBits(sizeof(movements), &movements);

	int i = 1;
	int flag = 1;
	unsigned long long movement = 0;
	while (movements) {
		movement = movements % (1 << 2);
		switch (movement) {
			case move_forward_i:
				//  printf("move_forward_i\n");
				distance--;
				break;
			case attack_i:
				//  printf("attack_i\n");
				if (distance <= 3) {
					hp--;
				}
				break;
			case withstand_i:
				//  printf("withstand_i\n");
				distance++;
				break;
		}

		if (hp <= 0) {
			printf("YES %d\n", i);
			flag = 0;
			break;
		}
		if (distance <= 0 || (i % 10 == 0 && movement != withstand_i)) {
			printf("NO %d\n", hp);
			flag = 0;
			break;
		}
		i++;
		movements = movements >> 2;
	}
	if (flag) printf("NO %d\n", hp);
	//  printf("distance = %d, movement = %lld\n", distance, movement);
	return 0;
}
