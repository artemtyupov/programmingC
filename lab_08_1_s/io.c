#include "io.h"

int read(FILE *f, int arr[][7], int *max_row, int *max_column)
{
    int element;
    if (fscanf(f,"%d", max_row) != -1){
        if (fscanf(f,"%d", max_column) != -1)
        {
            if ((*max_row <= MAX_ROW)&(*max_column <= MAX_COLUMN))
            {
                for (int i = 0; i < *max_row; i++)
                {
                    for (int j = 0; j < *max_column; j++)
                    {
                        fscanf(f,"%d", &element);
                        arr[i][j] = element;
                    }
                }
                return OK;
            }
            else
                return MORE_MAX_ELEMENTS;
        }
        else
            return WRONG_INPUT;
    }
    else
        return WRONG_INPUT;
}

int write(int arr[][7], int max_row, int max_column)
{
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_column; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return OK;
}
