#include <stdio.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main() {
	char c = 0;
	int i = 0;
	Strength s = INIT_STRENGTH;
	Obedience o = INIT_OBEDIENCE;
	while (1) {
		c = getchar();
		if (c == '\n') {
			/* return 0; */
			break;
		} else if (c == 'e') {
			s += STRENGTH_EAT;
			o -= OBEDIENCE_EAT;
		} else if (c == 't') {
			s -= STRENGTH_TRAIN;
			o += OBEDIENCE_TRAIN;
		}
		if (o >= LEARN_OBEDIENCE && s <= LEARN_STRENGTH) {
			o = INIT_OBEDIENCE;
			i++;
			if (i >= 5) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}
