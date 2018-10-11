#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, k;
    int counter = 0;
    scanf("%d", &n);
    for(i = 0; i <= 10*n/5; i++)
    {
        for(j = 0; j <= (10*n - 5*i)/2; j++)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}
