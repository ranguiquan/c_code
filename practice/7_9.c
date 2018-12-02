#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define BUF 1000
void count(char* a);

int main(void)
{
    char a[BUF];
    int i = 0;
    while((a[i++] = getchar()) != '\n');
    count(a);
    return 0;
}

void count(char* a)
{
    int alpha = 0, num = 0, space = 0, other = 0;
    int n = 0;
    while(a[n] != '\n'){
        if(isalpha(a[n])){
            alpha++;
        }else if(isdigit(a[n])){
            num++;
        }else if(isspace(a[n])){
            space++;
        }else{
            other++;
        }
        n++;
    }
    printf("alpha:%d num:%d space:%d other:%d\n", alpha, num, space, other);
    return;
}
