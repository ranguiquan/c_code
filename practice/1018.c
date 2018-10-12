#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, n, i;
    scanf("%d %d %d", &a, &b, &n);
    int* array = (int *)malloc(sizeof(int) * n);
    *(array) = 1;
    *(array + 1) = 1;
    for(i = 2; i < n; i++){
        *(array + i) = (a * *(array + i - 1) + b * *(array + i -2))%7;
    }
    printf("%d\n", *(array + n -1));
    return 0;
}
