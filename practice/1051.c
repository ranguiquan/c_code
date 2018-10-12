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
    int n, m;
    int i, j, k;
    scanf("%d %d", &n, &m);
    int* scorePerCourse = (int*)malloc(sizeof(int) * m);
    for(i = 0; i < m; i++)
    {
        scanf("%d", scorePerCourse+i);
    }

    typedef struct students
    {
        int number;
        int* scores;
        int tottalScore;
    }students;
    students* ptrToSample = (students*)malloc(sizeof(students) * n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &(ptrToSample + i)->number);
        (ptrToSample+i)->scores = (int*)malloc(sizeof(int)*m);
        (ptrToSample+i)->tottalScore = 0;
        for(j = 0; j < m; j++)
        {
            scanf("%d", (ptrToSample+i)-> scores+j);
            if( *((ptrToSample+i) -> scores+j) >= 60 )
            {
                (ptrToSample+i)->tottalScore += *(scorePerCourse+j);
            }
        }
    }
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if((ptrToSample+i)-> tottalScore <(ptrToSample+j)-> tottalScore)
            {
                swap(&(ptrToSample+i)-> tottalScore,  &(ptrToSample+j)-> tottalScore);
                swap(&(ptrToSample+i)-> number,  &(ptrToSample+j)-> number);
            }
            if((ptrToSample+i)-> tottalScore == (ptrToSample+j)-> tottalScore  &&  
                    (ptrToSample+i)-> number > (ptrToSample+j)-> number)
            {
                swap(&(ptrToSample+i)-> number, &(ptrToSample+j)-> number);
            }
        }
    }
    for(i = 0; i < n; i++)
    {
        printf("%d %d\n", (ptrToSample+i)-> number, (ptrToSample+i)-> tottalScore);
    }

}
