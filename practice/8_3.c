#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void input(int a[]);
void swap(int a[]);
void output(int a[]);


int main(void)
{
    int a[SIZE];
    input(a);
    swap(a);
    output(a);
    return 0;
}

void swap(int a[])
{
    int min = 0, max = 0;
    int i;
    int tmp;
    for(i = 0; i < SIZE; i++){
        if(a[i] < a[min]) min = i;
    }
    tmp = a[0];
    a[0] = a[min];
    a[min] = tmp;
    for(i = 0; i < SIZE; i++){
        if(a[i] > a[max]) max = i;
    }
    tmp = a[SIZE-1];
    a[SIZE-1] = a[max];
    a[max] = tmp;
    return;
}

void input(int a[])
{
    int i;
    for(i = 0; i < SIZE; i++){
        scanf("%d", a+i);
    }
    return;
}

void output(int a[])
{
    int i;
    for(i = 0; i < SIZE; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
    return;
}
