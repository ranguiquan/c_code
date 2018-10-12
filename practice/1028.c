#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, i;
    int key = 0;
    scanf("%d", &n);
    if(n > 0)
    {
        if(n%10 > 0)
        {
            key = 1;
        }
        if(key == 1)
        {
            printf("%d", n%10);
        }

        while(n/10 != 0)
        {
            n = n/10;
            if(n%10 > 0)
            {
                key = 1;
            }
            if(key == 1)
            {
                printf("%d", n%10);
            }
        }
    }
    else
    {
        n = -n;
        printf("-");
        if(n%10 > 0)
        {
            key = 1;
        }
        if(key == 1)
        {
            printf("%d", n%10);
        }

        while(n/10 != 0)
        {
            n = n/10;
            if(n%10 > 0)
            {
                key = 1;
            }
            if(key == 1)
            {
                printf("%d", n%10);
            }
        }

    }
    return 0;
}
