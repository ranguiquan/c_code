#include <stdio.h>
#include <stdlib.h>
int abs(int a)
{
    if(a > 0)
    {
        return a;
    }else
    {
        return -a;
    }
}
int main(void)
{
    int n, i, j, min;
    scanf("%d", &n);
    int* array = (int*)malloc(sizeof(int) * n);
    int out = 0;
    for(i = 0; i < n; i++ )
    {
        scanf("%d", array+i);
    }
    for(i = 1; i < n; i++)
    {
        min = abs(*(array+i) - *array);
        for(j = 0; j < i; j++)
        {
            if(abs(*(array+i) - *(array+j)) < min)
            {
                min = abs(*(array+i) - *(array+j));
            }
        }
        out += min;
    }
    printf("%d\n", out + *(array));
    return 0;
}
