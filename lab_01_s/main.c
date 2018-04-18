#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "area.h"

double f1(double x)
{
    return exp(-x+2);
}

double f2(double x)
{
    return 3*x+2;
}

double f3(double x)
{
    return exp(x);
}


double eq_1(double x)
{
    return f1(x) - f2(x);
}

double eq_2(double x)
{
    return f2(x) - f3(x);
}

double eq_3(double x)
{
    return f3(x) - f1(x);
}

// n - number of points


int main(void)
{
    double a = resh(-10.0,10.0,0.001,(*eq_1));
    double b = resh(-10.0,10.0,0.001,(*eq_2));
    double c = resh(-10.0,10.0,0.001,(*eq_3));
    double S1 = integral(a, b, 0.001, trapezium, f2);
    double S2 = integral(c, b, 0.001, trapezium, f3);
    double S3 = integral(a, c, 0.001, trapezium, f1);
    double S = S1 - S2 - S3;
    printf("S = %f \n", S);
    return 0;
}

