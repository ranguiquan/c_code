#include <stdio.h>
#include <stdlib.h>
#define BUF 1000
int main(void)
{
    char str[BUF];
    char str_cp[BUF];
    int i = 0, j = 0;
    int n;
    while((str[i++] = getchar()) != '\n');
    str[--i] = '\0';
    n = i;
    for(i = 0; i < n; i++){
        while(str[i] == ' ' && str[i+1] == ' '){
            i++;
        }
        str_cp[j++] = str[i];
    }
    str_cp[j] = '\0';
    printf("%s\n", str_cp);
    return 0;
}
