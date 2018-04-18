#include <stdio.h>
#include <stdbool.h>
#define OK 0
#define WRONG_INPUT -1
#define NULL_NEGATIVE -2
#define NULL_NUMBER -3
int process(FILE *f, int *max)
{
    int num;
    bool flag1 = false;
    bool flag2 = false;
	bool flag3 = false;
    if (fscanf(f, "%d", max) == 1)
    {
        if (*max < 0)
		{
            flag1 = true;
			flag3 = true;
		}
        *max = 0;
        while (fscanf(f, "%d", &num) == 1)
        {
            if (num < 0 && flag3 == true) 
            {
                flag3 = false;
            }
            if (num > *max && flag1 == true)
            {
                *max = num;
            }
            flag1 = false;
            if (num < 0)
            {
                flag1 = true;
                flag2 = true;
            }
        }
        if (flag3 == false)
        {
            return NULL_NUMBER;
        }
        if (flag2 == false)
        {
            return NULL_NEGATIVE;
        }
        else
        {
            return OK;
        }

    }
    return WRONG_INPUT;
}


int main(void)
{
    int max;
    int re = process(stdin, &max);

    if (re == WRONG_INPUT)
    {
        printf("Wrong input.\n");
    }
    else
        if (re == NULL_NEGATIVE)
    {
       printf("Null negative.\n");
    }
	else
		if (re == NULL_NUMBER)
			printf("There is not max number\n");
        else
        {
            
            printf("max is %d\n", max);
            return OK;
        }
}