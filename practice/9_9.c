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
    return head;
}


