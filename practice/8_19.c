#include <stdio.h>
#include <stdlib.h>

void* new(int n)
{
    return malloc(n*sizeof(char));

}

void free
