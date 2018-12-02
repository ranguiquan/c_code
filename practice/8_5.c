#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node* next;
}node;

void solution(int n);

int main(void)
{
    int n;
    printf("n=");
    scanf("%d", &n);
    solution(n);
    return 0;
}

void solution(int n)
{
    int i;
    node* head = (node*)malloc(sizeof(node));
    head->number = 1;
    head->next = NULL;
    node* tmp = head;
    for(i = 2; i <= n; i++){
        tmp->next = (node*)malloc(sizeof(node));
        tmp->next->number = i;
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
    tmp->next = head;
    tmp = head;
    node* tempkey;
    while(tmp->next != tmp){
        tempkey = tmp->next->next->next;
        free(tmp->next->next);
        tmp->next->next = tempkey;
        tmp = tempkey;
    }
    printf("%d\n", tmp->number);
}
