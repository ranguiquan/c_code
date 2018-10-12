#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    typedef struct student
    {
        int number;
        int grade;
        int ranking;
    }student;
    student* a = (student*)malloc(sizeof(student) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &(a+i)->number, &(a+i)->grade);
    }
    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n; j++)
        {
            if((a+i) -> grade < (a+j) -> grade)
            {
                swap(&(a+i)->number, &(a+j)->number);
                swap(&(a+i)->grade, &(a+j)->grade);
            }
        }
    }
    a->ranking = 1;
    for(i = 2; i <= n; i++)
    {
        if((a+i-1)->grade == (a+i-2)->grade)
        {
            (a+i-1)->ranking = (a+i-2)->ranking;
        }else
        {
            (a+i-1)->ranking = i;
        }
    }
    for(i = 0; i < n-1; i++)
    {
        for(j = i; j < n; j++)
        {
            if((a+i)->grade == (a+j)->grade && (a+i)->number > (a+j)->number)
            {
                swap(&(a+i)->number, &(a+j)->number);
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d %d %d\n",(a+i)->ranking, (a+i)->number, (a+i)->grade);
    }
    return 0;
}
