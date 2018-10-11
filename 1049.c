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
    char array[BUFSIZE];
    scanf("%s", array);
    int i, j;
    i = 0;
    int counter = 0;
    while(array[i] != '\0')
    {
        if(array[i] >= 'A' && array[i] <= 'Z')
        {
            array[i] = array[i] + 'a' - 'A';
        }
        counter++;
        i++;

    }

    typedef struct element
    {
        char character;
        int number;
    } element;
    element* ele = (element*)malloc(sizeof(element) * 26);
    for(i = 0; i < 26; i++)
    {
        (ele+i)->character = 'a' + i;
        (ele+i)->number = 0;
    }
    for(i = 0; i < counter; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(array[i] == (ele+j)->character)
            {
                (ele+j)->number++;
            }
        }
    }
    for(i = 0; i < 25; i++)
    {
        for(j = i+1; j < 26; j++)
        {
            if((ele+i)->number < (ele+j)->number)
            {
                swapchar(&(ele+i)->character, &(ele+j)->character);
                swapint(&(ele+i)->number, &(ele+j)->number);
            }
            if((ele+i)->number == (ele+j)->number && (ele+i)->character > (ele+j)->character)
            {
                swapchar(&(ele+i)->character, &(ele+j)->character);
            }
        }
    }
    for(i = 0; i < 26; i++)
    {
        if((ele+i)->number > 0)
        {
            printf("%c %d\n", (ele+i)->character, (ele+i)->number);
        }
    }
    return 0;
}
