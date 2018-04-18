#include <stdio.h>
#define VALUE_ERROR 1
#define IO_ERROR 2
int mypow(int a,int b)
{
    int pr = 1;
    for (int i = 1; i <= b; i++)
    {
        pr = pr * a;
    }
    return pr;
}



int main (void)
{
   int n, a;
   printf("Input n: ");
   if (scanf("%d", &n) == 1)
   {
       if (n < 0)
       {
           printf("Wrong input, enter n >= 0");
           return VALUE_ERROR;
       }
       printf("Input a: ");
       if (scanf("%d", &a) == 1)
       {
           printf("%d\n", mypow (a, n) );
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
