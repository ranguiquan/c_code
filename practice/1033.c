#include <stdio.h>
#include <stdlib.h>
#define SIZE 9


int check(char* array)
{
    int i, j, k, l, m;
    for(i = 0; i < SIZE; i++)
    {//one unit to check
        for(j = 0; j < SIZE - 1; j++)
        {//one element
            int flag = 1;
            for(l = j+1; l < SIZE; l++)
            {
                if(*(array + 9*i + j) == *(array + 9*i + l) && *(array + 9*i + j)!='0')
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                return 0;
            }
        }
    }


    for(i = 0; i < SIZE; i++)
    {//one unit to check
        for(j = 0; j < SIZE - 1; j++)
        {//one element
            int flag = 1;
            for(l = j+1; l < SIZE; l++)
            {
                if(*(array + 9*j + i) == *(array + 9*l + i) && *(array + 9*j + i)!='0')
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                return 0;
            }
        }
    }
    
    for(i = 0; i < SIZE; i++)
    {//one unit to check


        for(j = 0; j < SIZE - 1; j++)
        {//one element
            int flag = 1;
            for(l = j+1; l < SIZE; l++)
            {
                if(*(array +((i/3)*3 + j/3 )*SIZE  +  (i%3)*3 + j%3 ) ==  *(array +((i/3)*3 + l/3 )*SIZE  +  (i%3)*3 + l%3 ) && *(array +((i/3)*3 + j/3 )*SIZE  +  (i%3)*3 + j%3 )!='0' )
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                return 0;
            }
        }
    }

    return 1;

}


void display(char* array)
{
    int i;
    for(i = 0; i < SIZE*SIZE; i++)
    {
        printf("%c", *(array + i));
        if(i%SIZE == SIZE -1)
        {
            printf("\n");
        }
    }
    printf("\n");
    return;
}


void put(char* array, int x)
{
    char i;
    if(*(array + x) == '0')
    {
        for(i = '1'; i <= '9'; i++)
        {
            *(array + x) = i;
            if(x < SIZE*SIZE -1)
            {
                if(check(array))
                {
                    put(array, x+1);
                }
            }else if(check(array))
            {
                display(array);
                exit(0);
            }
        }
        *(array + x) = '0';
    }else
    {
        put(array, ++x);
    }
    return;
}


int main(void)
{
    char* array = (char*)malloc(sizeof(char) * SIZE*SIZE);
    int i;
    for(i = 0; i < SIZE*SIZE; i++)
    {
        scanf("%c", array+i);
        if(i % SIZE == SIZE - 1)
        {
            getchar();
        }
    }
    put(array, 0);
    return 0;
}
