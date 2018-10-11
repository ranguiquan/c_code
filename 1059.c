#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE* f1 = fopen("data.in", "r");
    FILE* f2 = fopen("data.out", "w");
    int n;
    fscanf(f1, "%d", &n);
    int i;
    for(i = 0; i < n; i++)
    {
        fprintf(f2, "hello world\n");
    }
    return 0;
}
