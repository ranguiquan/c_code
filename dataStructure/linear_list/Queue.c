#include <stdio.h>
#include <stdlib.h>
#define QueueElementType int//定义队列的数据类型

typedef struct QueueNode{
    QueueElementType Data;
    struct QueueNode* Next;
}QueueNode;//储存队列的链表
typedef QueueNode* PtrToQueueNode; 
typedef struct Node{
    PtrToQueueNode head;
    PtrToQueueNode tail;
}Node;//储存头尾的指针
typedef Node* PtrToNode;
typedef PtrToNode Queue;

PtrToNode Queue_create()
{
    PtrToQueueNode q = (PtrToQueueNode)malloc(sizeof(QueueNode));
    PtrToNode n = (PtrToNode)malloc(sizeof(Node));
    n->head = q;
    n->tail = q;
    return n;
}

void Queue_add(PtrToNode N, QueueElementType A)
{
    N->tail->Data = A;
    PtrToQueueNode tmp = (PtrToQueueNode)malloc(sizeof(QueueNode));
    N->tail->Next = tmp;
    N->tail = tmp;
}

int Queue_isempty(PtrToNode N)
{
    if(N->head == N->tail) return 1;
    else return 0;
}

PtrToQueueNode Queue_delete(PtrToNode N)
{
    if(!Queue_isempty(N)){
        PtrToQueueNode tmp = N->head;
        PtrToQueueNode tmp2 = N->head->Next;
        N->head = tmp2;
        return tmp;
    }else{
        printf("ERROR\nQueue is empty\n");
        return NULL;
    }
}
