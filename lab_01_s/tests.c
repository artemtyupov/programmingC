#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "area.h"

double f1_test(double x)
{
    return x;
}

double f2_test(double x)
{
    return x * x;
}

double f3_test(double x)
{
    return sqrt(x);
}

double f4_test(double x)
{
    return sin(x);
}

double f5_test(double x)
{
    return x*cos(x);
}


double f11_test(double x)
{
    return -x+3;
}

double f12_test(double x)
{
    return x*x-2;
}

double f13_test(double x)
{
    return sqrt(x)+2;
}

double f14_test(double x)
{
    return log(x)+3;
}

double f15_test(double x)
{
    return x*x-4;
}

double f111(double x)
{
    return x;
}

double f222(double x)
{
    return 2;
}

double f1112(double x)
{
    return f11_test(x) - f12_test(x);
}

double f1213(double x)
{
    return f12_test(x) - f13_test(x);
}

double f1311(double x)
{
    return f13_test(x) - f11_test(x);
}

double f1114(double x)
{
    return f11_test(x) - f14_test(x);
}

double f1415(double x)
{
    return f14_test(x) - f15_test(x);
}

double f1511(double x)
{
    return f15_test(x) - f11_test(x);
}

double ftest(double x)
{
    return f111(x) - f222(x);
}

double ff1(double x)
{
    return (3/5)*x;
}

double ff2(double x)
{
    return 3*(x-4);
}

double ff3(double x)
{
    return -1.25;
}

double ftest1(double x)
{
    return ff1(x) - ff2(x);
}

double ftest2(double x)
{
    return ff2(x) - ff3(x);
}

double ftest3(double x)
{
    return ff3(x) - ff1(x);
}

void tests_integral()
{
    float eps = 0.001;
    printf("\nTESTS INTEGRAL: \n \n");
    printf("1) line [2 - 4] %e\n", integral(2.0, 4.0, eps, trapezium, f1_test));
    printf("2) parabola [4 - 10] %e\n", integral(4.0, 10.0, eps, trapezium, f2_test));
    printf("3) square root [1 - 6] %e\n", integral(1.0, 6.0, eps, trapezium, f3_test));
    printf("4) sin [2 - 3] %e\n", integral(2.0, 3.0, eps, trapezium, f4_test));
    printf("5) x * cos(x) [5 - 6] %e\n", integral(5.0, 6.0, eps, trapezium, f5_test));
}

void tests_resh()
{
    printf("\nTESTS RESH: \n \n");
    
    printf("Functions:\n"
           "1) sqrt(x)+2, x^2-2, -x+3 [-10 - 10]\n"
           "2) x^2-4, ln(x)+3, -x+3 [1 - 10]\n");
    
    float i1 = -10.0, i2 = 10.0, eps = 0.001;
    float a,b,c,S1,S2,S3,S;
    //float Ist;

    /*//sqrt(x), x^2-2, -x+3
	Ist = 2.190658;
    a = resh(i1,i2,eps, *f1112);
	b = resh(i1,i2,eps,*f1213);
	c = resh(i1,i2,eps,*f1311);
    S1 = integral(c, b, eps, trapezium, f13_test);
	S2 = integral(c, a, eps, trapezium, f11_test);
	S3 = integral(a, b, eps, trapezium, f12_test);
    S = S1 - S2 - S3;
	if ( Ist == S ) 
		printf("1) S poluchennaya = %f\n"
           "   S poschitannaya = %f\n", S, Ist);
	else
		printf("Error testa");

    //x^2-4, ln(x)+3, -x+3
	Ist = 3.664372;
    a = resh(i1,i2,eps,*f1114);
	b = resh(1,i2,eps,*f1415);
	c = resh(i1,i2,eps,*f1511);
    S1 = integral(a, b, eps, trapezium, f14_test);
	S2 = integral(c, b, eps, trapezium, f15_test);
	S3 = integral(a, c, eps, trapezium, f11_test);
    S = S1 - S2 - S3;
	if ( Ist == S ) 
		printf("2) S poluchennaya = %f\n"
           "   S poschitannaya = %f", S, Ist);
    else
        printf("Error testa");*/
	//TEST1
	a = resh(i1,i2,eps, *ftest);
    printf("TEST1 = %f\n", a);
	//TEST2
    a = resh(4,6,eps,*ftest1);
    b = resh(3,5,eps,*ftest2);
    c = resh(-1,1,eps,*ftest3);
    //printf("%f %f %f", a,b,c);
    S1 = integral(c, a, eps, trapezium, ff1);
    S2 = integral(b, a, eps, trapezium, ff2);
	S3 = integral(c, b, eps, trapezium, ff3);
    S = S1 - S2 - S3;
	printf("TEST2 = %f", S);
	
}

int main(void)
{
    tests_integral();
    tests_resh();
    return 0;
}
