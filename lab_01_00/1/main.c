#include <stdio.h>
#include <math.h>
 int main(void)
{
    float h,l1,l2;
    float bmi,p,bok;

    printf("Input L1: ");
    scanf("%f", &l1);
    printf("Input L2: ");
    scanf("%f", &l2);
    printf("Input h: ");
    scanf("%f", &h);
    bmi = abs(l1-l2)/2;
    bok = sqrt(bmi*bmi + h*h);
    p = 2 * bok + l1 + l2;
    printf("P =  %f\n", p);
}
