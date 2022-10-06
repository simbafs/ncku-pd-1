#include <stdio.h>

int main(){
	double P = 1;
	double p = 0;
	for(int i = 0; i < 5; i++){
		scanf("%lf", &p);
		P*=p;
	}
	printf("%.15f\n", P);
	return 0;
}
