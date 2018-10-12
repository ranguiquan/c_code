#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int tmp;
    tmp = *(a);
    *a = *b;
    *b = tmp;
    return;
}
void bubbleSolution(int* a, int n)
{
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(*(a+i) > *(a+j)){
                swap(a+i, a+j);
            }
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
}
int main(void)
{
    int* a = (int*) malloc(sizeof(int) * 4);
    int i;
    for(i = 0; i < 4; i++){
        scanf("%d", a+i);
    }
    bubbleSolution(a, 4);
    return 0;
}
