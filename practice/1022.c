#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, max1, max2, max3, a1, a2, a3;
    int counter = 0;
    scanf("%d", &n);
    max1 = n / 5;
    max2 = n / 3;
    for(i = 0; i <= max1; i++)
    {
        for(j = 0; j <= max2; j++)
        {
            if(i + j + (n - 5*i - 3*j) * 3 == n)
            {
                printf("%d %d %d\n", i, j, (n - 5*i - 3*j) * 3);
                counter++;
            }
        }
    }
    printf("%d", counter);
    return 0;
}
