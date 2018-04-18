#include "funcs.h"

int global_int = 0;

int randomize_pro(void)
{
    int result = random() % 10;
    
    return result;
}

tr *take_ints(tr *ptr)
{
    ptr->a = randomize_pro();
    ptr->b = randomize_pro();
    ptr->c = randomize_pro();
    ptr->next = NULL;
    return ptr;
}

tr *create_elements(tr *head)
{
    if (!head)
    {
        head = malloc(sizeof(tr));
        head = take_ints(head);
    }
    else
    {
        tr *ptr = malloc(sizeof(tr));
        ptr = take_ints(ptr);
        ptr->next = head;
        head = ptr;
    }
    return head;
}

void print_list(tr* head)
{
    for(tr *cur = head; cur; cur = cur->next)
    {
        printf("%d %d %d\n", cur->a, cur->b, cur->c);
    }
}

void check_list(tr* head)
{
    for(tr *cur1 = head; cur1; cur1 = cur1->next)
    {
        for(tr *cur2 = head; cur2; cur2 = cur2->next)
        {
            if ((cur1 != cur2)&&(cur1->a == cur2->a && cur1->b == cur2->b && cur1->c == cur2->c))
                puts("YES");
        }
    }
}
























