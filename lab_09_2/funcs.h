#ifndef FUNCS_H
#define FUNCS_H

#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct three tr;

struct three 
{
	int a, b, c;
	tr *next;
};

tr *create_elements(tr *head);
void print_list(tr* head);
void check_list(tr* head);

#endif // FUNCS_H
