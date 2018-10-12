#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, k;
    scanf("%d", &n);
    for(i = 0; i < n - 1; i++)
    {
        printf(" ");
    }
    for(i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    for(i = n - 2; i > -1; i--)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("*");

        for(j = 0; j < 3*n - 2*i - 4; j ++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    
    for(i = 1; i <= n - 2; i++)
    {
        for(j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("*");

        for(j = 0; j < 3*n - 2*i - 4; j ++)
        {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }

    for(i = 0; i < n - 1; i++)
    {
        printf(" ");
    }
    for(i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");

    return 0;
}
