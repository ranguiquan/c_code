#include<stdio.h>
#define BUF 1000
void strcpy_diy(char* a, char* b);

int main(void)
{
    char a[BUF], b[BUF];
    printf("输入一个字符串，赋给b\n");
    scanf("%s", b);
    printf("执行strcpy_diy(a,b)\n");
    strcpy_diy(a,b);
    printf("打印a\n%s", a);
    return 0;
}

void strcpy_diy(char* a, char* b)
{
    int x = 0;
    while(b[x] != '\0'){
        a[x] = b[x];
        x++;
    }
    a[x] = b[x];
    return;
}
