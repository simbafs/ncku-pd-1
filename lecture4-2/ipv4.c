#include <stdio.h>

int main() {
	unsigned int ip = 0;
	scanf("%x", &ip);
	printf("%d.%d.%d.%d\n", ip>>24, (ip>>16)&0xff, (ip>>8)&0xff, ip&0xff);
	return 0;
}
