#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    if(m >= 7 && m <= 9)
    {
        if(n >= 20)
        {
            printf("10%%\n");
        }else
        {
            printf("5%%\n");
        }
    }else
    {
        if(n >= 20)
        {
            printf("20%%\n");
        }else
        {
            printf("10%%\n");
        }
    }
    return 0;
}
