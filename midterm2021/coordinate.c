#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	char str[10001];
	int len;
} Hex;

uint64_t hexToInt(char c) {
	if ('0' <= c && c <= '9') return c - '0';
	if ('a' <= c && c <= 'f') return c - 'a' + 10;
	if ('A' <= c && c <= 'F') return c - 'A' + 10;
	return 0;
}

// split splits h into a and b
int split(Hex *h, Hex *a, Hex *b) {
	if (h->len == 0) return 0;
	for (int i = 0; i <= h->len / 2; i++) {
		if (2 * i < h->len) {
			a->str[i] = h->str[2 * i];
			a->len++;
		}
		if (2 * i + 1 < h->len) {
			b->str[i] = h->str[2 * i + 1];
			b->len++;
		}
	}
	a->str[a->len] = '\0';
	b->str[b->len] = '\0';
	return 0;
}

// **Warning** this is not a pure function
int sumOfHex(Hex *h) {
	int s = 0;

	for (int i = 0; i < h->len; i++) {
		s += hexToInt(h->str[i]);
	}
	//  printf("sumOfHex, %s -> %d\n", h->str, s);
	if (s == 0) {
		h->str[0] = '0';
		h->str[1] = '\0';
		h->len = 1;
		return 0;
	}

	int i = 0;
	char tmp[10001] = "";
	for (; s; i++) {
		int t = s % 16;
		s /= 16;
		tmp[i] = t < 10 ? t + '0' : t - 10 + 'a';
	}
	for (int j = 0; j < i; j++) {
		h->str[j] = tmp[i - j - 1];
	}
	h->str[i] = '\0';
	h->len = i;

	return 0;
}

int getCoordinate(Hex *h, Hex *coordinate) {
	//  printf("> %s %d\n", h->str, h->len);
	if (h->len <= 1) {
		strcpy(coordinate->str, h->str);
		coordinate->len = h->len;
		return 0;
	}

	Hex e, o, ec, oc;  // even, odd
	split(h, &e, &o);
	//  printf(">> %s %d split %s %d; %s %d\n", h->str, h->len, e.str, e.len, o.str,
	//         o.len);
	//  return 0;
	sumOfHex(&e);
	sumOfHex(&o);
	//  printf(">> sum %s %d %s %d\n", e.str, e.len, o.str, o.len);
	//  return 0;
	getCoordinate(&e, &ec);
	getCoordinate(&o, &oc);
	//  printf(">> get coordinate %s %d %s %d\n", ec.str, ec.len, oc.str, oc.len);

	strcat(coordinate->str, ec.str);
	strcat(coordinate->str, oc.str);

	coordinate->len = ec.len + oc.len;
	return 0;
}

int main() {
	Hex h = {}, coordinate = {};
	scanf("%s", h.str);

	h.len = strlen(h.str);

	getCoordinate(&h, &coordinate);
	printf("%s\n", coordinate.str);

	return 0;
}
