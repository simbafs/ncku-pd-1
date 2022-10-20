#include <stdio.h>

int main(){
	int lock[6] = {};
	int d1, d2;
	for(int i = 0; i < 75; i++){
		scanf("%d %d", &d1, &d2);
		d1--;
		if(d2%2){
			lock[d1] = (lock[d1]+1)%10;
		}else{
			lock[d1] = (lock[d1]+9)%10; // +9 = -1+10
		}
	}
	printf("%d %d %d %d %d %d\n", lock[0], lock[1], lock[2], lock[3], lock[4], lock[5]);
}
