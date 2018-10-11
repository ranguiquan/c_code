#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        *(a + i) = -1;
    }
    for(i = 2; i <= n; i++)
    {
        for(j = i; j <= n; j+= i)
        {
            *(a + j-1) = - *(a + j-1);
        }
    }
    for(i = 0; i < n; i++)
    {
        if(*(a + i) == 1)
        {
            printf("%d ", i+1);
        }
    }
    return 0;
}
