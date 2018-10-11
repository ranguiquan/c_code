#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int num(int a, int x)
{
    return a/pow(10, x-1) - floor(a/pow(10, x))*10;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    int out = 0;
    int a[4];
    for(i = 0; i < 4; i++)
    {
        a[i] = num(n, i+1);
        a[i] = (a[i] + 5)%10;
    }
    swap(&a[0], &a[3]);
    swap(&a[1], &a[2]);
    for(i = 0; i < 4; i++)
    {
        out += a[i] * pow(10, i);
    }
    printf("%d\n", out);
    return 0;
}
