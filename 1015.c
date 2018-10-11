#include <stdio.h>
#include <math.h>
int main(void)
{
    float x, e, tmp;
    float sin = 0.0;
    float cos = 0.0;
    int i = 1;
    int j = 0;
    int m, n;
    scanf("%f %f", &x, &e);
    x = fmodf(x, M_PI * 2);
    while(1)
    {
        tmp = pow(x, i);
        for(m = i; m > 0; m--)
        {
            tmp = tmp/m;
        }
        sin += pow(-1, i/2) * tmp;
        if(tmp < e)
        {
            break;
        }
        i += 2;
    }
    j = 2;
    cos = 1.0;
    while(1)
    {
        tmp = pow(x, j);
        for(m = j; m > 0; m--)
        {
            tmp = tmp/m;
        }
        cos += pow(-1, j/2) * tmp;
        if(tmp < e)
        {
            break;
        }
        j += 2;
    }

    printf("%f\n%f\n", sin, cos);
    return 0;
}
