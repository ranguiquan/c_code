#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
void solution(char* a)
{
    int i;
    int character = 0, space = 0, nums = 0, others = 0;
    for(i = 0; a[i] != '\n'; i++){
        if((a[i] >='a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')){
            character++;
        }else if(a[i] >= '0' && a[i] <= '9'){
            nums++;
        }else if(a[i] == ' '){
            space++;
        }else others++;
    }
    printf("characters=%d\nspaces=%d\nnumbers=%d\nothers=%d\n", character, space, nums, others);
}
int main(void)
{
    char a[MAX];
    int i = 0;
    while((a[i] = getchar()) != '\n'){
        i++;
    }
    solution(a);
    return 0;
}
