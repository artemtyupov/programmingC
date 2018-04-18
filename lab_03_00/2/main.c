#include <stdio.h>
#include <math.h>
#define IOERR -1
#define WRONG_INPUT -2
#define COMAND_LINE_ERROR -3
#define OK 0

int findsr(FILE *f, float *sr)
{
    float num;
    float sum;
    int n = 1;
    if (fscanf(f, "%f", &sum) == 1)
    {
        while (fscanf(f, "%f", &num) == 1)
        {
            sum += num;
            n += 1;
        }
        *sr = sum / n;

        return OK;
    }
    return WRONG_INPUT;
}

int findnb(FILE *f, float *nb, float *sredznach)
{
    float num;
    float raz1,raz2;
    if (fscanf(f, "%f", nb) == 1)
    {
        raz1 = fabs(*nb - *sredznach);
        while (fscanf(f, "%f", &num) == 1)
        {
            raz2 = fabs(num - *sredznach);
            if (raz2 < raz1)
            {
                *nb = num;
                raz1 = raz2;
            }
        }

        return OK;
    }
    else
        return WRONG_INPUT;
}
int main(int argc, char **argv)
{
    FILE *f;
    float nb,sr;
    float sredznach;
    int funcvalue, err_status;
    if (argc == 2)
    {
        f = fopen(argv[argc-1], "r");
        if (f == NULL)
        {
            printf("I/O error\n");
            return IOERR;
        }
        funcvalue = findsr(f, &sr); 
        if (funcvalue == OK)
        {
            sredznach = sr;
            rewind(f);
            funcvalue = findnb(f, &nb, &sredznach);
            if (funcvalue == OK)
            {
                printf("Number is %f\n", nb);
                fclose(f);
                err_status = OK;
            }
            else
            {
                printf("Wrong input.\n");
                err_status = WRONG_INPUT;
            }
        }
        else
        {
            printf("Wrong input.\n");
            err_status = WRONG_INPUT;
        }
    }
    else
    {
        printf("Invalid line command parameters.\n");
        err_status = COMAND_LINE_ERROR;
    }
    return err_status;
}

