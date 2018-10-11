#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int a, b, c, out;
    float q;

    scanf("%d %d %d", &a, &b, &c);
    q = (float) (a + b + c)/2;
    out = round((float)sqrt(q * (q - a) * (q - b) * (q - c)));
    printf("%d\n", out);
}
