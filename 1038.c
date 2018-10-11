#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }else 
    {
        return b;
    }
}
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int i;
    for(i = max(m, n) + 1; i <= m*n; i++)
    {
        if(i%m == 0 && i%n == 0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
