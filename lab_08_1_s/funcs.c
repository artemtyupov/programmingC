#include "funcs.h"

int exchange(int arr[][7], int row, int column, int max_column)
{
    int tmp;
    for (int i = row; i < (row + 1); i++)
    {
        for (int j = column; j < (column + 1); j++)
        {
            for (int j = 0; j < max_column; j++)
            {
                tmp = arr[i][j];
                arr[i][j] = arr[i+1][j];
                arr[i+1][j] = tmp;
            }
        }
    }
    return OK;
}

int sr(int arr_row[], int max_column)
{
    int sum = 0;
    for (int i = 0; i < max_column; i++)
    {
        sum += arr_row[i];
    }
    return (sum / max_column);
}

int sort(int arr[][7], int max_row, int max_column)
{
    int arr_row[max_column];
    double avg[max_row];
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_column; j++)
        {
            arr_row[j] = arr[i][j];
        }
        avg[i] = sr(arr_row, max_column);
    }
    for (int i = 0; i < max_row; i++)
    {
        for (int j = 0; j < max_row; j++)
        {
            if (avg[i] > avg[j])
                exchange(arr, i , j, max_column);
        }
    }
    return OK;
}

