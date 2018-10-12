#include <stdio.h>
int main(void)
{
    int k, n;
    double s = 0.0;

    scanf("%d", &k);
    n = 1;
    while(1)
    {
        s += (double)1/n;
        if(s > k)
        {
            break;
        }
        n++;
    }
    printf("%d", n);
    return 0;
}
