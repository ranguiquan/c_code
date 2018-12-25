#include <stdio.h>
#include <stdlib.h>
#define BUF 100

typedef struct expression{
    char name[BUF];
    int number;
}expression;

int main(void)
{
    char option[BUF];
    expression variations[BUF];
    int this_variation = 0;
    while(1)
    {
        int isAEqual = 0;
        int i = 0
        scanf("%s", option);
        if(strcmp(option, "END") == 0){
            break;
        }
        while(option[i++] != '\0'){
            if(option[i-1] == '='){
                isAEqual = 1;
                break;
            }
        }
        if(isAEqual){
            strcpy(variations[this_variation++].name, option);
            variations[this_variation]
        }

    }
}
