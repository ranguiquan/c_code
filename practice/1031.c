#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int a, b, c;//a手雷 b冲锋枪 c大杀器
    int priceOfA = 2, priceOfB = 6, priceOfC = 1;
    int counter = 0;
    //b<a<c or c<a<b
    for(a = 2; a <= n/priceOfA; a += 2)
    {
        for(b = 1; b <= n/priceOfB; b++)
        {
            for(c = 8; c <= n/priceOfC; c += 10)
            {
                if(a != b && b != c && a != c  &&
                        ((b<a && a<c) || (c<a && a<b)) &&
                        (a * priceOfA + b *priceOfB + c * priceOfC) > (float)0.9*n &&
                        (a * priceOfA + b *priceOfB + c * priceOfC) <= n)
                {
                    if((b/10 == 0 && a/10 > 0 && a/100 == 0) || b/10 > 0)
                    {
                        printf("%d %d %d\n", a, b, c);
                        counter++;
                    }
                }
            }
        }
    }
    if(counter == 0)
    {
        printf("no answer\n");
    }
    return 0;
}
