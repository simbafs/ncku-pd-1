#include <stdio.h>
#include <stdlib.h>

int main() {
	char *ean = malloc(sizeof(char) * 13);
	int a = 0;
	int b = 0;
	int i = 0;
	scanf("%s", ean);
	while(ean[0] != '\0'){
		if(i){
			a += ean[0] -'0';
		}else{
			b += ean[0] -'0';
		}
		i = !i;
		ean += 1;
	}
	printf("%d", 9 - (a * 3 + b - 1) % 10);
	return 0;
}
