#include <stdio.h>
#include <stdlib.h>
#define BUF 1000
#define StackElementType int
#define bool int
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

int Stack_isEmpty(Stack s)
{
    return s->Top == -1;
}

StackElementType Stack_pop(Stack s)
{
    if(!Stack_isEmpty(s)){
        return s->Data[s->Top--];
    }else{
        printf("Stack is empty\n");
        return -1;
    }
}

StackElementType Stack_getTopIndex(Stack s)
{
    return s->Top;
}

StackElementType Stack_getTopElemt(Stack s)
{
    return s->Data[s->Top];
}

bool solution(char* a)
{
    Stack s = Stack_create();
    int i = 1;
    int flag = 1;
    while(*(a + i) != *a){
        switch (*(a + i)){
            case '(':
                Stack_append(s, *(a + i));
                break;
            case '[':
                Stack_append(s, *(a + i));
                break;
            case '{':
                Stack_append(s, *(a + i));
                break;
            case ')':
                if(!Stack_isEmpty(s) && Stack_getTopElemt(s) == '('){
                    Stack_pop(s);
                    break;
                }else{
                    flag = 0;
                    break;
                }
            case '}':
                if(!Stack_isEmpty(s) && Stack_getTopElemt(s) == '{'){
                    Stack_pop(s);
                    break;
                }else{
                    flag = 0;
                    break;
                }
            case ']':
                if(!Stack_isEmpty(s) && Stack_getTopElemt(s) == '['){
                    Stack_pop(s);
                    break;
                }else{
                    flag = 0;
                    break;
                }
        }
        i++;
    }
    if(!Stack_isEmpty(s)) flag = 0;
    return flag;
}

int main(void)
{
    char a[BUF];
    scanf("%s", a);
    printf("%d", solution(a));
    return 0;
}
