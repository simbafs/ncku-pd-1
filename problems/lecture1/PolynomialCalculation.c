#include <stdio.h>
#include <math.h>

int main(void){
	float x = 0;
	scanf("%f", &x);
	printf("%.1f", 7*powf(x, 4) - 8*powf(x, 3) - powf(x, 2) + 6*x -22);
    return 0;
}

