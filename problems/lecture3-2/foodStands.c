#include <stdio.h>

int main(){
	int min = 0;
	int max = 0;
	int current = 0;
	scanf("%d", &current);
	min = current;
	while(current != -1){
		if(current > max){
			max = current;
		}
		if(current < min){
			min = current;
		}
		scanf("%d", &current);
	}
	printf("%d", max - min);
	return 0;
}
