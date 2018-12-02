#include <stdio.h>
#include <stdlib.h>
#define BUF 1000

int get_strlen(char a[]);

int main(void)
{
    char a[BUF];
    scanf("%s", a);
    printf("%d", get_strlen(a));
    return 0;
}

int get_strlen(char a[])
{
    int ans = 0;
    while(a[ans++] != '\0');
    return --ans;
}
