#include <stdio.h>
#include <stdlib.h>
#define ListElementType int
#define ERROR -1
#define TRUE 1
typedef struct ListNode{
    ListElementType Data;
    struct ListNode* Next;
}ListNode;
typedef ListNode* List;
typedef List PtrToListNode;

List List_create(void)
{
    List head = (List)malloc(sizeof(ListNode));
    head->Next = (PtrToListNode)malloc(sizeof(ListNode));
    return head;
}

void List_append(List L, ListElementType d)
{
    List tmp = L;
    while(tmp->Next){
        tmp = tmp->Next;
    }
    tmp->Data = d;
    tmp->Next = (PtrToListNode)malloc(sizeof(ListNode));
    return;
}

int List_length(List L)
{
    int counter = -1;
    List tmp = L;
    while(tmp->Next){
        tmp = tmp->Next;
        counter++;
    }
    return counter;
}

int List_numsfind(List L, ListElementType d)
{
    int counter = 0;
    List tmp = L;
    while(tmp->Next && tmp->Data != d){
        counter++;
        tmp = tmp->Next;
    }
    if(!tmp->Next){
        printf("List_numsfind ERROR\nnot found\n");
        return ERROR;
    }else{
        return counter;
    }
}

PtrToListNode List_indexfind(List L, int n)
{
    int counter = 0;
    List tmp = L;
    while(tmp->Next && counter != n){
        counter++;
        tmp = tmp->Next;
    }
    if(!tmp->Next){
        printf("List_indexfind() ERROR\nno such index\n");
        return NULL;
    }else{
        return tmp;
    }
}

void List_insert(List L, ListElementType d, int n)
{
    if(List_indexfind(L, n-1)){
        PtrToListNode pre = List_indexfind(L, n-1);
        PtrToListNode tmp = pre->Next;
        pre->Next = (PtrToListNode)malloc(sizeof(ListNode));
        pre->Next->Data = d;
        pre->Next->Next = tmp;
    }else{
        printf("List_insert() ERROR\nno such index\n");
    }
    return;
}

int List_delet(List L, int n)
{
    if(List_indexfind(L, n)){
        PtrToListNode pre = List_indexfind(L, n-1);
        PtrToListNode tmp = pre->Next;
        pre->Next = pre->Next->Next;
        free(tmp);
        return TRUE;
    }else{
        printf("List_delet() ERROR\nelement not found\n");
        return ERROR;
    }
}

void List_show(List L)
{
    List tmp = L->Next;
    while(tmp->Next){
        printf("%d ", tmp->Data);
        tmp = tmp->Next;
    }
    return;
}
