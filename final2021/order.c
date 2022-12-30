#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char *, char **);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
	"aluminum",		"ammunition", "orange",		"aspirin",		"ax",
	"basketball",	"zipper",	  "bell",		"blanket",		"drum",
	"canvas",		"flute",	  "eraser",		"mirror",		"comb",
	"eggplant",		"diamond",	  "zucchini",	"door",			"butter",
	"egg",			"dart",		  "chair",		"encyclopedia", "china",
	"fan",			"glue",		  "elevator",	"flower",		"hat",
	"garlic",		"strawberry", "glove",		"flour",		"ice",
	"ship",			"hammer",	  "fur",		"key",			"honey",
	"grape",		"icecream",	  "lock",		"iron",			"ivory",
	"jacket",		"oil",		  "uniform",	"kiwi",			"pan",
	"helmet",		"keyboard",	  "yoyo",		"jet",			"knife",
	"tie",			"lemon",	  "xerox",		"ink",			"mutton",
	"newspaper",	"melon",	  "coconut",	"motorcycle",	"longan",
	"nail",			"rice",		  "magnet",		"peanut",		"ointment",
	"oar",			"jeans",	  "nut",		"arrow",		"oven",
	"jewel",		"wool",		  "noodle",		"pencil",		"lamp",
	"refrigerator", "needle",	  "roast",		"vest",			"yarn",
	"saw",			"hamburger",  "soap",		"glass",		"wine",
	"tangerine",	"pillow",	  "umbrella",	"zinc",			"train",
	"uglifruit",	"toast",	  "underwear",	"vanilla",		"jeep",
	"unicycle",		"vase",		  "rope",		"violin",		"warship",
	"volleyball",	"water",	  "yogurt",		"submarine",	"passionfruit",
	"yacht",		"rose",		  "window",		"yolk",			"kite",
	"liquor",		"xylophone",  "toothbrush", "battery",		"doll"};

int main(void) {
	char order[500] = "", *result = NULL;
	scanf("%s", order);
	recovering_order(order, &result);
	printf("%s", result);
	free(result);
	return 0;
}

int fuz(char *frag) {
	int best = GOODS_SIZE;
	int bestStartAt = MAX_NAME_LEN;
	for (int i = 0; i < GOODS_SIZE; i++) {
		char *sub = strstr(names[i], frag);
		if (sub == NULL) continue;
		int startAt = sub - names[i];
		//  printf("%s %s %d\n", frag, names[i], startAt);

		if (startAt > bestStartAt)
			continue;
		else if (startAt == bestStartAt) {
			int len1 = strlen(names[i]);
			int len2 = strlen(names[best]);
			if (len1 > len2) continue;
			else if(len1 == len2){
				if(strcmp(names[i], names[best]) >= 0) continue;
			}
		}

		best = i;
		bestStartAt = startAt;
	}

	return best;
}

void recovering_order(char *orders, char **result) {
	*result = malloc(sizeof(char *) * MAX_NAME_LEN * (MAX_ORDER_SIZE + 1));

	char *order = strtok(orders, ":");

	while (order != NULL) {
		int t = fuz(order);
		strcat(*result, names[t]);
		strcat(*result, "+");
		order = strtok(NULL, ":");
	}
	(*result)[strlen(*result) - 1] = '\0';
}
