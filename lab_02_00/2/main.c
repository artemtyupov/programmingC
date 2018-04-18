#include <math.h>
#include <stdio.h>
#define RECTANGULAR 1
#define OBTUSE 2
#define ACUTE 3
#define IO_ERROR 4
#define TRIANGLE_ERROR 5
int typeoftriangle(float x1, float x2, float x3, float y1, float y2, float y3)
{
    int a,b,c;

    a = pow((x2-x1),2)+pow((y2-y1),2);
    b = pow(x3-x2,2)+pow(y3-y2,2);
    c = pow(x1-x3,2)+pow(y1-y3,2);

    if (a>b+c || b>a+c || c>a+b)
    {
        return TRIANGLE_ERROR;
    }

    if (a==b+c || b==a+c || c==a+b)
    {
        return RECTANGULAR;
    }
    if ((a>b+c) || (b>a+c) || (c>a+b))
    {
        return OBTUSE;
    }
    else return ACUTE;
}

int main (void)
{
   float x1,x2,x3,y1,y2,y3;
   float f;
   printf("Input (x1,y1):  ");
   if (scanf("%f, %f", &x1, &y1) == 2)
   {
       printf("Input (x2,y2): ");
       if (scanf("%f",&f) == 1) 
           printf(" ");
       if (scanf("%f, %f", &x2, &y2) == 2)
       {
           printf("Input (x3,y3): ");
           if (scanf("%f",&f) == 1)
               printf(" ");
           if (scanf("%f, %f", &x3, &y3) == 2)
           {
               int k = typeoftriangle(x1,x2,x3,y1,y2,y3);
               if (k == TRIANGLE_ERROR)
                   printf("Triangle does not exist");
               if (k == RECTANGULAR)
                   printf("Triangle is rectangular");
               if (k == OBTUSE)
                   printf("Triangle is obtuse");
               if (k == ACUTE)
                   printf("Triangle is acute");
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
   else
   {
       printf("Wrong input, enter only numbers");
       return IO_ERROR;
   }

}
