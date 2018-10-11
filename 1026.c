#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int counter = 1;
    float e = 0.00001;
    float x1, x2, tmp;
    scanf("%d", &a);
    x1 = (float)a/2.0;
    x2 = 1.0/2.0 * (x1 + a/x1);
    while(x1 - x2 > e || x1 - x2 < -e)
    {
        tmp = x2;
        x2 = 1.0/2.0 * (x2 + a/x2);
        x1 = tmp;
        counter ++;
    }
    printf("%f\n%d", x2, counter);
    return 0;
}
