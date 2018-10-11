#include <stdio.h>
#include <stdlib.h>
int su(int a)
{
    int i;
    int key = 1;
    if(a == 1)
    {
        return 0;
    }else if(a == 2)
    {
        return 1;
    }else
    {
        for(i = 2; i < a/2 + 1; i++)
        {
            if(a%i == 0)
            {
                key = 0;
                return key;
            }
        }
        return key;
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    int i;
    for(i = 0; i < n; i ++)
    {
        scanf("%d", a+i);
    }
    for(i = 0; i < n; i ++)
    {
        if(su(*(a + i)))
        {
            printf("YES ");
        }else
        {
            printf("NO ");
        }
    }
    return 0;
}
