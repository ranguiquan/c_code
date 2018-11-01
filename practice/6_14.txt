#include<stdio.h>
#include<stdlib.h>
#define BUF 1000
int strcmp(char* a, char* b);

int main(void)
{
    char a[BUF], b[BUF];
    printf("输入第一个字符串\n");
    scanf("%s", a);
    printf("输入第二个字符串\n");
    scanf("%s", b);
    printf("%d\n", strcmp(a,b));
    return 0;
}

int strcmp(char* a, char* b)
{
    int x = 0;
    while(a[x] != '\0' && b[x] != '\0' && a[x] == b[x]){
        x++;
    }
    return (int)a[x] - b[x];
}
