#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, i, j;
    float out1, tmp;
    out1 = 0;
    float out2 = 0;
    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        tmp = (float)1/i;
        out1 += tmp;
    }
    for(i = 1; out2 < m; i++)
    {
        tmp = (float)1/i;
        out2 += tmp;
    }
    printf("%.2f\n%d", out1, --i);
}
