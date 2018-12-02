#include <stdio.h>
#include <stdlib.h>

#define BUF 1000
void swap(char* a,char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void overturn(char* a)
{
    int n = 0;
    int i, j;
    while(a[n++] != '\0');
    n--;
    i = 0;
    j = n -1;
    while( i < j ){
        swap(&a[i++], &a[j--]);
    }
}
int main(void)
{
    char a[BUF];
    scanf("%s", a);
    overturn(a);
    printf("%s\n", a);
    return 0;
}
