#include <stdio.h>
 int main(void)
{
    int h,t,m;
    float bmi,p;
    printf("Input h(cm): ");
    scanf("%d", &h);
    printf("Input t(cm): ");
    scanf("%d", &t);
    printf("Input m(kg): ");
    scanf("%d", &m);
    p = h * t / 240;
    bmi = m / (h*h/10000);
    printf("P =  %f\n", p);
    printf("BMI =  %f", bmi);
}
