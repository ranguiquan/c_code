#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, i;
    int h = 0, l = 0;
    double sum = 0.0;
    scanf("%d", &n);
    double* a = (double*)malloc(sizeof(double) * (n + 2));
    char* b = (char*)malloc(sizeof(char) * (n + 2));
    scanf("%lf", a);
    *b = getchar();
    scanf("%lf", a+1);
    *(b+1) = getchar();
    getchar();
    for(i = 2; i < n + 2; i++)
    {
        scanf("%lf", a+i);
        *(b+i) = getchar();
    }

    for(i = 0; i < n + 2; i++)
    {
        if(*(b+i) == 'C')
        {
            *(a + i) = *(a + i) * 1.8 + 32;
        }
    }

    for(i = 2; i < n + 2; i++)
    {
        sum += *(a + i);
        if(*(a + i) >= *a)
        {
            h++;
        }else if(*(a + i) <= *(a + 1))
        {
            l++;
        }
    }
    

    
    printf("%.3lfF\n", sum/n);
    printf("%d %d", h, l);

    
    return 0;
}
