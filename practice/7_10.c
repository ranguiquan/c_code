#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define BUF 1000

void theLongest(char*);

int main(void)
{
    char a[BUF];
    int i = 1;
    a[0] = ' ';
    while((a[i++] = getchar()) != '\n');
    theLongest(a);
    return 0;
}

void theLongest(char* a)
{
    int i, j;
    int max = 0;
    int mark;
    i = 0, j = 0;
    while(a[i] != '\n'){
        if(a[i] == ' '){
            j = i;
            while(!isspace(a[++j]));
            if(j-i-1 > max){
                max = j-i-1;
                mark = i;
            }
        }
        i++;
    }
    for(i = mark+1; i <= mark+max; i++){
        printf("%c", a[i]);
    }
    printf("\n");
}
