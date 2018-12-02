#include <stdio.h>
#include <stdlib.h>

void solution(int a[]);
void swap(int* a, int* b);

int main(void)
{
    int a[5][5];
    int i;
    for(i = 0; i < 25; i++){
       // *(*a+i) = i+1;
        scanf("%d", *a+i);
    }
    solution(*a);
    for(i = 0; i < 25; i++){
        printf("%d ", *(*a+i));
        if((i+1)%5 == 0){
            printf("\n");
        }
    }
}

void solution(int a[])
{
    int i;
    for(i = 0; i < 25; i++){
        if(*(a+i) < a[0]){
            swap(a+i, &a[0]);
        }
        if(*(a+i) < a[4]){
            swap(a+i, &a[4]);
        }
        if(*(a+i) < a[20]){
            swap(a+i, &a[20]);
        }
        if(*(a+i) < a[24]){
            swap(a+i, &a[24]);
        }
        if(*(a+i) > a[12]){
            swap(a+i, &a[12]);
        }
    }
}
void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
