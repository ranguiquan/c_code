#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;
typedef node* ptrToNode;

ptrToNode creat(void)
{
    ptrToNode head = (ptrToNode)malloc(sizeof(node));
    head->next = NULL;
    ptrToNode n = head;
    scanf("%d", &head->data);
    while(n->data != 0){
        n->next = (ptrToNode)malloc(sizeof(node));
        n = n->next;
        scanf("%d", &n->data);
        n->next = NULL;
    }
    return head;
}

void list_print(ptrToNode head)
{
    ptrToNode a = head;
    while(a != NULL){
        printf("%d\n", a->data);
        a = a->next;
    }
}

void insertByPtr(ptrToNode a,ptrToNode b)
{
    ptrToNode tmp = a->next;
    a->next = b;
    b->next = tmp;
    return;
}

ptrToNode delByData(ptrToNode head, int x)
{
    ptrToNode a = head;
    ptrToNode pre = head;
    if(head->data == x && head->next != NULL){
        a = head->next;
        free(head);
        return a;
    }else if(head->next == NULL){
        return NULL;
    }
    a = head->next;
    while(a->next){
        if(a->data == x){
            pre->next = a->next;
            free(a);
            return head;
        }
        pre = a;
        a = a->next;
    }
    return NULL;
}

int main(void)
{
    ptrToNode head = creat();
    delByData(head, head->next->data);
    list_print(head);

    return 0;
}

