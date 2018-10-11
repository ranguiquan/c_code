#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int counter1 = 0, counter2 = 0;
    int* a =  (int*)malloc(sizeof(int) * n);
    int* b =  (int*)malloc(sizeof(int) * n);
    int* c =  (int*)malloc(sizeof(int) * n);
    int* d =  (int*)malloc(sizeof(int) * n);
    int* e =  (int*)malloc(sizeof(int) * n);
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", a+i, b+i, c+i, d+i);
        *(c+i) = round(*(b+i)* 0.2  +  *(c+i)* 0.1  +  *(d+i)* 0.7);
    }
    for(i = 0; i < n; i++)
    {
        printf("%d %d\n", *(a+i), *(c+i));
        if(*(c+i) >= 90)
        {
            counter1++;
        }else if(*(c+i) < 60)
        {
            counter2++;
        }
    }
    printf("%d\n%d\n", counter1, counter2);

}
