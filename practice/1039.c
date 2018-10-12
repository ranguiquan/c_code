#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    int counter = 0;
    int i;
    for(i = m; i <=n; i++)
    {
        if(i%400 == 0)
        {
            counter++;
        }else if(i%4 == 0 && i %100 != 0)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}
