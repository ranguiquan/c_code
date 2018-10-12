#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    int* a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    for(i = n-1; i >= 0; i--)
    {
        printf("%d ", *(a+i));
    }
    printf("\n");
    return 0;
}
