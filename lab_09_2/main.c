#include "funcs.h"

int main (void)
{
    tr *head = NULL;
    for (int i = 0; i < 100; i++)
        head = create_elements(head);
    print_list(head);
    check_list(head);
    return 0;
}
