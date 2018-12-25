#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 100

typedef struct expression{
    char name[BUF];
    int number;
}expression;

int main(void)
{
    char option[BUF];
    int i, j;
    expression variations[BUF];
    int this_variation = 0;
    while(1)
    {
        int isAEqual = 0;
        i = 0;
        j = 0;
        while((option[j++] = getchar()) != '\n');
        option[j-1] = '\0';
        j = 0;
        while(option[j] != '\0'){
            printf("%c", option[j++]);
        }
        //printf("%s", option);
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
            strcpy(variations[this_variation].name, option);
            variations[this_variation].name[i-1] = '\0';
            variations[this_variation].number = 0;
            while(option[i] != '\0'){
                variations[this_variation].number += variations[this_variation].number * 10 + option[i]-'0';
            }
            this_variation++;
        }
    }

    for(i = 0; i < 3; i++){
        printf("%s = %d\n", variations[i].name, variations[i].number);
    }
}
