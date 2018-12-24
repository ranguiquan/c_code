#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    int number;
    char name[20];
    float grade;
    struct student* next;
}student;

int create(student* head_p)
{
    int count = 1;
    student* a = head_p;
    scanf("%d %s %f", &head_p->number, head_p->name, &head_p->grade);
    head_p->next = NULL;
    while(1){
        a->next = (student*)malloc(sizeof(student));
        scanf("%d %s %f", &a->next->number, a->next->name, &a->next->grade);
        a->next->next = NULL;
        if(a->next->number == 0){
            free(a->next);
            a->next = NULL;
            break;
        }
        count++;
        a = a->next;
    }
    free(a);
    return count;
}

int main(void)
{
    student* head = (student*)malloc(sizeof(student));
    printf("%d\n", create(head));
    return 0;
}
