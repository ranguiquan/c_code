#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int man_num, woman_num;
    int i, j;
    scanf("%d", &man_num);
    getchar();
    char* man_name = (char*)malloc(sizeof(char) * man_num);
    for(i = 0; i < man_num; i++){
        scanf("%c", man_name+i);
    }
    scanf("%d", &woman_num);
    getchar();
    char* woman_name = (char*)malloc(sizeof(char) * woman_num);
    for(i = 0; i < woman_num; i++){
        scanf("%c", woman_name+i);
    }

    int** matrix = (int**)malloc(sizeof(int*) * )
    return 0;
}
