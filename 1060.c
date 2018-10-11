#include <stdio.h>
#incldue <stdlib.h>
int power(int x, int y)
{
    int i;
    int out = 1;
    for(i = 0; i < y; i++)
    {
        out *= x;
    }
    return out;
}
