#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char a[1000];
    char tmp[1000];
    int i;
    scanf("%s", a);
    for(i = strlen(a) - 1; i >= 0; i--)
    {
        tmp[strlen(a) - 1 - i] = a[i];
    }
    tmp[strlen(a)] = '\0';
    if(strcmp(a, tmp) == 0)
    {
        printf("Yes\n");
    }else
    {
        printf("No\n");
    }
}
