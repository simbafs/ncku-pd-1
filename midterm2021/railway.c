#include <stdio.h>

int getTime(){
	int h, m;
	scanf("%d:%d", &h, &m);
	return h*60+m;
}

int main(){
	int currentTime = getTime();
	int fastTrain = 0;
	int fastArriveTime = 2147483647;
	int n = 0;

	scanf("%d", &n);
	/* printf("current time: %d\n", currentTime); */
	/* printf("x  time  time+y fastArriveTime\n"); */
	for(; n >= 0; n--){
		int x, time, y;
		scanf("%d", &x);
		time = getTime();
		scanf("%d", &y);
		/* printf("%d %d %d %d\n", x,time, time+y ,fastArriveTime); */
		if(time >= currentTime && time + y < fastArriveTime){
			fastArriveTime = time + y;
			fastTrain = x;
		}
	}
	printf("%d\n", fastTrain);
	
	return 0;
}
