#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_MAX 2048
#define KEY_MAX 100

typedef struct search_s {
	char *key;
	char *value;
} search_t;

search_t *get_param_by_key(char *url, char *key);

int main() {
	char url[URL_MAX + 1], key[KEY_MAX + 1];

	fgets(url, URL_MAX, stdin);
	scanf("%s", key);

	search_t *param = get_param_by_key(url, key);

	if (param)
		printf("key: %s, value: %s", param->key, param->value);
	else
		printf("404 Not Found");
}

search_t *get_param_by_key(char *url, char *key) {
	// remove trash
	url = strchr(url, '?');
	if (url == NULL) {
		return NULL;
	} else {
		url++;
	}

	// remove #
	for (char *c = url; *c; c++) {
		if (*c == '#') {
			*c = '\0';
			break;
		}
	}

	int len = strlen(key);

	int found = 0;
	search_t *result = malloc(sizeof(search_t));

	for (char *frag = strtok(url, "&"); frag; frag = strtok(NULL, "&")) {
		int flag = 1;
		for (int i = 0; i < len; i++) {
			if (key[i] != frag[i]) {
				flag = 0;
				break;
			}
		}
		if (!flag) continue;
		found = 1;
		//  printf("frag: %s\n", frag);

		char *value = frag;
		for (; *value != '=' && *value; value++) ;

		if(strlen(value) > 0){
			value++;
		}

		result->key = key;
		result->value = value;
		break;
	}

	if (found) {
		return result;
	} else {
		free(result);
		return NULL;
	}
}
