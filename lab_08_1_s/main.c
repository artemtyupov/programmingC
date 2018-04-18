#include <stdio.h>
#include "io.h"
#include "funcs.h"

#define IOERR -1
#define COMAND_LINE_ERROR -3

int main(int argc, char **argv)
{
    FILE *f;
    int err_status, max_column, max_row;
    if (argc == 2)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            printf("I/O error\n");
            return IOERR;
        }
        int arr [MAX_ROW][MAX_COLUMN];
        err_status = read(f, arr, &max_row, &max_column);
        if (err_status == OK)
        {
            write(arr, max_row, max_column);
            sort(arr, max_row, max_column);
            printf("\n");
            write(arr, max_row, max_column);
            fclose(f);
        }
    }

    else
    {
        printf("Invalid line command parameters.\n");
        err_status = COMAND_LINE_ERROR;
    }
    return err_status;
}
