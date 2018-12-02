#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void trans(int a[3][3])
{
    int i, j;
    for(i = 0; i < 2; i++){
        for(j = i+1; j < 3; j++){
            swap(&a[i][j], &a[j][i]);
        }
    }
}

int main(void)
{
    int a[3][3] = {{1,2,3},
        {4,5,6},
        {7,8,9}};
    trans(a);
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
