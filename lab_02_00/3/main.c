#include <stdio.h>
#include <math.h>
#define IO_ERROR 1
#define VALUE_ERROR 2
float fact(int k)
{
    float f = 1;
    for (int i = 1; i <= k; f  *= (i++));
    return f;
}

float rowsum(float eps, float x)
{
    float sum = 1 + x;
    float x1 = x;
    float x2 = x;
    float x3 = 1;
    int k = 1;
    while ( fabs(x2) >= eps )
    {
        k += 1;
        x1 = x1 * x;
        x3 = x3 * k;
        x2 = x1 / x3;
        sum += x2;
    }
    return sum;
}

int main (void)
{
   float x, eps, abser, otnoser, znachf, sum;
   printf("Input eps: ");
   if (scanf("%f", &eps) == 1)
   {
       if (eps <= 0)
       {
           printf("Value can not be negative or equal to zero");
           return VALUE_ERROR;
       }
       printf("Input x: ");
       if (scanf("%f", &x) == 1)
       {
           sum = rowsum(eps,x);
           znachf = exp(x);
           abser = fabs(znachf - sum);
           otnoser = fabs((znachf - sum)/znachf);
           printf("s(x) = %f\n", sum);
           printf("f(x) = %f\n", znachf);
           printf("Absolute error = %.7f\n", abser);
           printf("Relative error = %.7f\n", otnoser);
       }
       else
       {
           printf("Wrong input, enter only numbers");
           return IO_ERROR;
       }
   }
   else
   {
       printf("Wrong input, enter only numbers");
       return IO_ERROR;
   }
}
