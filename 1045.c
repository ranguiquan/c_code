#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, p, m, i, j;
    scanf("%d %d %d", &n, &p, &m);
    int* a = (int*)malloc(sizeof(int) * n*p);
    int* b = (int*)malloc(sizeof(int) * p*m);
    int* c = (int*)malloc(sizeof(int) * n*m);
    for(i = 0; i < n*p; i++)
    {
        scanf("%d", a+i);
    }
    for(i = 0; i < p*m; i++)
    {
        scanf("%d", b+i);
    }
    for(i = 0; i < n*m; i++)
    {
        *(c + i) = 0;
    }
    for(i = 0; i < n*m; i++)
    {
        for(j = 0; j < p; j++)
        {
            *(c+i) += *(a + (i/m)*p + j) * *(b + j*m +i%m);
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", *(c + i*m + j));
        }
        printf("\n");
    }
    return 0;
}
