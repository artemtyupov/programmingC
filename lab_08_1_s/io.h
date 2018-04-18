#ifndef IO_H
#define IO_H

#include <stdio.h>
#define WRONG_INPUT -2
#define OK 0
#define MORE_MAX_ELEMENTS -6
#define MAX_COLUMN 7
#define MAX_ROW 5

int read(FILE *f, int arr[][7], int *max_row, int *max_column);
int write(int arr[][7], int max_row, int max_column);

#endif // IO_H
