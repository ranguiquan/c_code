#include <stdio.h>
#include <stdlib.h>
int check(int n)
{
    int i;
    int key = 1;
    for(i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            key = 0;
            break;
        }
    }
    return key;
}
int main(void)
{
    int n;
    int i, j, k;
    scanf("%d", &n);
    for(i = 3; i <= n/2; i += 2)
    {
        if(check(i) && check(n-i))
        {
            printf("%d=%d+%d\n", n, i, n-i);
            break;
        }
    }
    return 0;
}
