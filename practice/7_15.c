#include <stdlib.h>
#include <stdio.h>
#define SIZE 3

typedef struct employee{
    int number;
    char name[20];
}employee;

void input(employee*);
void sortByNumber(employee*);
void binarySearch(employee*, int);
void swap(employee*, employee*);

int main(void)
{
    employee a[SIZE];
    int key;
    input(a);
    sortByNumber(a);
    for(int i = 0; i < 3; i++)
    {
        printf("name:%s ", (a+i)->name);
        printf("number:%d\n", (a+i)->number);
    }
    printf("input the number of a employee:");
    scanf("%d", &key);
    binarySearch(a, key);
    return 0;
}

void swap(employee* a, employee* b)
{
    employee tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void input(employee* a)
{
    int i;
    for(i = 0; i < SIZE; i++){
        scanf("%s", (a+i)->name);
        scanf("%d", &((a+i)->number));
    }
}

void sortByNumber(employee* a)
{
    int i, j;
    for(i = 0; i < SIZE-1; i++){
        for(j = i+1; j < SIZE; j++){
            if((a+i)->number > (a+j)->number){
                swap(a+i, a+j);
            }
        }
    }
}

void binarySearch(employee* a, int key)
{
    int left = 0, right = SIZE-1;
    int mid = (left+right)/2;
    while(left <= right){
        if((a+mid)->number > key){
            right = mid-1;
        }else if((a+mid)->number < key){
            left = mid+1;
        }else{
            printf("name:%s\n", (a+mid)->name);
            return;
        }
        mid = (left+right)/2;
    }
    printf("not found\n");
    return;
}
