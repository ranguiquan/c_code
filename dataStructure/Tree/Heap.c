#include <stdio.h>
#include <stdlib.h>
#define MAXDATA 100000
#define true 1
#define false 0
#define error -1
#define HeapElementType int

typedef struct HeapNode{
    HeapElementType* Data;
    int Size;
    int Capacity;
}HeapNode;
typedef HeapNode* PtrToHeapNode;
typedef HeapNode* MaxHeap;

MaxHeap MaxHeap_create(int maxsize)
{
    MaxHeap out = (MaxHeap)malloc(sizeof(HeapNode));
    out->Data = (HeapElementType*)malloc(sizeof(HeapElementType)*(MAXDATA+1));
    out->Size = 0;
    out->Capacity = maxsize;
    out->Data[0] = MAXDATA;
    return out;
}

int MaxHeap_isfull(MaxHeap h)
{
    if(h->Size == Capacity){
        return true;
    }else return false;
}

int MaxHeap_insert(MaxHeap h, HeapElementType d)
{
    int i;
    if(MaxHeap_isfull(h)){
        printf("MaxHeap_insert ERROR\nheap is full\n");
        return false;
    }
    for(i = ++h->Size; h->Data[i/2] < d; i /= 2){
        h->Data[i] = h->Data[i/2];
    }
    h->Data[i] = d;
    return true;
}

HeapElementType MaxHeap_delet(MaxHeap h)
{
    int parent, child;
    HeapElementType maxitem, x;
    if(MaxHeap_isfull(h)){
        printf("MaxHeap_delet ERROR\nheap is empty\n");
        return error;
    }
    x = h->Data[h->Size--];
    maxitem = h->Data[1];
    parent = 1;
    child = parent * 2;
    for(parent = 1, child = parent * 2; child < h->Size; parent = child, child = parent*2){
        if(child!=h->Size && h->Data[child+1] > h->Data[child]) child++;
        if(x >= h->Data[child]) break;
        else h->Data[parent] = h->Data[child];
    }
    h->Data[parent] = x;
    return maxitem;
}

void MaxHeap_percdown(MaxHeap h, int p)
{//下滤，使以h->Data[p]为根的子堆为最大堆
    int parent, child;
    HeapElementType x = h->Data[p];//取根节点值
    for(parent = p; parent*2 <= h->Size; parent = child)
    {
        child = parent*2;
        if(child != h->Capacity && (h->Data[child+1] > h->Data[child])){
            child++;
        }
        if(h->Data[child] <= x) break;
        h->Data[parent] = h->Data[child];
    }
    h->Data[parent] = x;
}

void MaxHeap_buildheap(MaxHeap h)
{
    int i;
    for(i = H->Size/2; i > 0; i--)
        MaxHeap_percdown(h, i);
}


