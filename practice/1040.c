#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * n);
    int i;
    int counter = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", a+i, b+i);
    }
    for(i = 0; i < n; i++)
    {
        if(*(b+i) < 10 || *(b+i) > 20)
        {
            continue;
        }else if(*(a+i) == 0)
        {
            if(*(b+i) >= 12 && *(b+i) <= 16)
            {
                counter +=8;
            }else
            {
                counter += 10;
            }
        }else if(*(a+i) == 1)
        {
            counter += 30;
        }
    }

    printf("%d\n", counter);
    return 0;
}
