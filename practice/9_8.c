#include <stdio.h>
#include <stdlib.h>

void insert(SOMESTRUCT* a, SOMESTRUCT* b)
{
    SOMESTRUCT* tmp = a->next;
    a->next = b;
    b->next = tmp;
    return;
}
