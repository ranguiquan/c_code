#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sequence = 0;

int compare(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b);
}
void show(int* ans, int woman_num, char* woman_name, char** out)
{
    int i;
    for(i = 0; i < woman_num; i++){
        out[sequence][i] = woman_name[ans[i]];
    }
    out[sequence][i+1] = '\0';
    sequence++;
}

void match(int thisman, int** matrix, int man_num, int woman_num, int* woman_matched, char* man_name, char* woman_name, int* ans, char** out)
{
    int i, j;
    if(thisman == man_num-1){
        for(i = 0; i < woman_num; i++){
            if(matrix[thisman][i] == 1 && woman_matched[i] == 0){
                ans[thisman] = i;
                show(ans, woman_num, woman_name, out);
                return;
            }
        }
    }else{
        for(i = 0; i < woman_num; i++){
            if(matrix[thisman][i] == 1 && woman_matched[i] == 0){
                woman_matched[i] = 1;
                ans[thisman] = i;
                match(thisman+1, matrix, man_num, woman_num, woman_matched, man_name, woman_name, ans, out);
                woman_matched[i] = 0;
            }
        }
    }
}

int main(void)
{
    int man_num, woman_num;
    int i, j;
char** out = (char**)malloc(sizeof(char*) * 20);
for(int i = 0; i < 20; i ++){
    *(out+i) = (char*)malloc(sizeof(char) * 20);
}
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
    getchar();
    int** matrix = (int**)malloc(sizeof(int*) * man_num);
    for(i = 0; i < man_num; i++){
        *(matrix+i) = (int*)malloc(sizeof(int) * woman_num);
    }
    for(i = 0; i < man_num; i++){
        for(j = 0; j < woman_num; j++){
            scanf("%lc", &matrix[i][j]);
            matrix[i][j]-='0';
        }
        getchar();
    }
    int woman_matched[woman_num];
    for(j = 0; j < woman_num; j++){
        woman_matched[j] = 0;
    }
    int* ans = (int*)malloc(sizeof(int) * man_num);
    match(0,matrix, man_num, woman_num, woman_matched, man_name, woman_name, ans, out);
    qsort((void*)out, sequence, sizeof(char*), compare);
    for(i = 0; i < sequence; i++){
        printf("%s\n", *(out+i));
    }
    return 0;
}
