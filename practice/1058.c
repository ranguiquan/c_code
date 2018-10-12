#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, m, i, j, k;
    int left, right;
    int counter = 0;
    scanf("%d %d", &l, &m );
    int* a = (int*) malloc(sizeof(int) * (l+1));
    for(i = 0; i <= l; i++)
    {
        *(a+i) = 1;
    }
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &left, &right);
        for(j = left; j <= right; j++)
        {
            *(a + j) = 0;
        }
    }
    for(i = 0; i <= l; i++)
    {
        if(*(a+i) == 1)
        {
            counter++;
        }
    }
    printf("%d\n", counter);
    return 0;
}
