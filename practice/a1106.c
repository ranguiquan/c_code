/*程序说明：清橙a1106
 * 作者：冉桂全*/

#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 30
#define SIZE 20
def struct stack
{

}
int main(void)
{
    char input[BUF_SIZE];
    int i, j, k, tmp;
    int a[SIZE];
    int b[2] = {-1, -1};
    int c[2] = {-1, -1};
    unsigned long long  sum = 0;
    int para1 = 0;
    int para2 = 0;

    scanf("%s", input);
    for(i = 0; i < SIZE; i++){
        a[i] = -1;
    }

    for(i = 0; input[i] != '\0'; i++)
    {
        if(input[i] != '<')
        {
            a[i] = (int) input[i] + 1 - '1';
        }else
        {
            break;
        }
    }
    j = 0;
    for(i = i + 1; input[i] != '\0'; i++)
    {
        if(input[i] != '>')
        {
            b[j] = input[i] + 1 - '1';
            j++;
        }else
        {
            break;
        }
    }
    j = 0;
    for(i = i+1; input[i] != '\0'; i++)
    {
        c[j] = input[i] + 1 - '1';
        j++;
    }



    for(j = 0; j < 2; j++)
    {
        if(b[j] != -1)
        {
            para1 = para1 * 10 + b[j];
        }
    }
    for(j = 0; j < 2; j++)
    {
        if(c[j] != -1)
        {
            para2 = para2 * 10 + c[j];
        }
    }
    for(j = 0; j < SIZE && a[j] != -1; j++)
    {
        sum = sum * para1 + a[j];
    }

    return 0;
}
