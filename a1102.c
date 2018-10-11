/*程序说明：清橙a1102
 * 作者：冉桂全*/


#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char* a = (char*)malloc(40 * sizeof(char));
    char* out = (char*)malloc(40 * sizeof(char));
    int i = 0;
    int j;
    char com;
    while((a[i] = getchar()) != '.')
    {
      i++;
    }
    getchar();
    com = getchar();
    if(com == 'D')
    {
        getchar();
        char para = getchar();
        int flag = 0;
        for(j = 0; j < 39; j++)
        {
            if(flag == 0 && a[j] == para)
            {
                flag = 1;
                continue;
            }
            if(flag == 0)
            {
                out[j] = a[j];
            }else
            {
                out[j-1] = a[j];
            }
        }
    }else if(com == 'I')
    {
        getchar();
        char para1 = getchar();
        getchar();
        char para2 = getchar();
        int flag = 0;
        for(j = 0; j <40; j++)
        {
            if(a[j] == para1 && flag == 0)
            {
                out[j] = para2;
                out[j+1] = para1;
                flag = 1;
                continue;
            }
            if(flag == 0)
            {
                out[j] = a[j];
            }else
            {
                out[j+1] = a[j];
            }
        }
    }else if(com == 'R')
    {
        getchar();
        char para1 = getchar();
        getchar();
        char para2 = getchar();
        int flag = 0;
        for(j = 0; j <40; j++)
        {
            if(a[j] == para1 && flag == 0)
            {
                out[j] = para2;
                flag = 1;
                continue;
            }
            out[j] = a[j];
        }
    }

    for(i = 0; i < 39; i++)
    {
        printf("%c", out[i]);
    }
    return 0;
}   
