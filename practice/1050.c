#include <stdio.h>
#include <stdlib.h>
#define BUFSIZE 251
void swapchar(char* a, char* b)
{
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void swapint(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main(void)
{
    char array[BUFSIZE], arraynumber[BUFSIZE], arraycharacter[BUFSIZE];
    scanf("%s", array);
    int i, j, k;
    i = 0, j = 0, k = 0;
    int counter = 0;
    while(array[i] != '#')
    {
        if('0' <= array[i] && '9' >= array[i] )
        {
            arraynumber[j] = array[i];
            j++;
            counter++;
        }else
        {
            arraycharacter[k] = array[i];
            k++;
        }
        i++;
    }

    for(i = 0; i < j; i++)
    {
        printf("%c", arraynumber[i]);
    }
    printf("\n");
    for(i = 0; i < k; i++)
    {
        printf("%c", arraycharacter[i]);
    }
    printf("\n");


    typedef struct element
    {
        char character;
        int number;
    } element;
    element* ele = (element*)malloc(sizeof(element) * 10);
    for(i = 0; i < 10; i++)
    {
        (ele+i)->character = '0' + i;
        (ele+i)->number = 0;
    }
    for(i = 0; i < counter; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(arraynumber[i] == (ele+j)->character)
            {
                (ele+j)->number++;
            }
        }
    }
    for(i = 0; i < 10; i++)
    {
        if((ele+i)->number > 0)
        {
            printf("%c %d\n", (ele+i)->character, (ele+i)->number);
        }
    }
    return 0;
}
