#include <stdio.h>
#include <stdlib.h>
#define BUF 1000
#define StackElementType int

typedef struct StackNode{
    StackElementType Data[BUF];
    int Top;
}StackNode;
typedef StackNode* Stack;

Stack Stack_create()
{
    Stack s = (Stack)malloc(sizeof(StackNode));
    s->Top = -1;
    return s;
}

void Stack_append(Stack s, StackElementType d)
{
    if(s->Top < BUF-1){
        s->Data[++s->Top] = d;
    }else{
        printf("Stack out of BUF\n");
    }
}

StackElementType Stack_pop(Stack s)
{
    return s->Data[s->Top--];
}

int main(void)
{
    int i;
    Stack s = Stack_create();
    for(i = 0; i < 10; i++){
        Stack_append(s, i);
    }
    for(i = 0; i < 10; i++){
        printf("%d ", Stack_pop(s));
    }
    return 0;
}
