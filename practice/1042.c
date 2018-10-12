#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c;
    int i, j, k;
    scanf("%d %d %d", &a, &b, &c);
    int counter = 0;
    for(i = -100; i <= 100; i++)
    {
        for(j = -100; j <= 100; j++)
        {
            for(k = -100; k <= 100; k++)
            {
                if( a*i + b*j +c*k == 0 && i*i + j*j + k*k !=0 )
                {
                    printf("%d %d %d\n", i, j, k);
                    counter++;
                }
            }
        }
    }
    if(counter == 0)
    {
        printf("no solution\n");
    }
    return 0;
}
