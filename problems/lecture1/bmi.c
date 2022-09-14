#include<stdio.h>

int main () {
    float h = 0;
    float w = 0;
    scanf("%f %f", &h, &w);
    h = h/100;
    printf("%f", w/(h*h));
    return 0;
}
