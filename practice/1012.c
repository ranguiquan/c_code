#include <stdio.h>
int main(void)
{
    int n, m, i, x, y, z;
    scanf("%d %d", &n, &m);
    for(i = n; i <= m; i++)
    {
        x = i%10;
        y = (i/10)%10;
        z = (i/100)%10;
        if(i == x*x*x + y*y*y + z*z*z)
        {
            printf("%d ", i);
        }
    }
    return 0;
}
