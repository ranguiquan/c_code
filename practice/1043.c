#include <stdio.h>
#include <stdlib.h>
int abs(int a)
{
    if(a < 0)
    {
        return -a;
    }else return a;
}
int main(void)
{
    int n;
    int i, j;
    scanf("%d", &n);
    for(j = 0; j < n-1; j++)
    {
        printf(" ");
    }
    printf("*\n");



    for(i = 1; i < 2*n - 2; i++)
    {
        for(j = 0; j < abs(i - n+1); j++)
        {
            printf(" ");
        }
        printf("*");
        for(j = 0; j < 2*(n-1-abs(i - n+1)) - 1; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }


    for(j = 0; j < n-1; j++)
    {
        printf(" ");
    }
    printf("*\n");
    return 0;
}
