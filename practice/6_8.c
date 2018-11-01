#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int main(void)
{
    int n, i, j, k, row, col;
    printf("输入n\n");
    scanf("%d", &n);
    int** table = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++){
        *(table+i) = (int*)malloc(sizeof(int) * n);
        memset(*(table+i), 0, sizeof(int) * n);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", *(table+i)+j);
        }
    }
    for(i = 0; i < n; i++){
        row = i;//定行
        col = 0;
        for(j = 0; j < n; j++){
            if(table[i][j] > table[row][col]){
                col = j;
            }
        }
        k = 1;
        for(j = 0; j < n; j++){//在一列上看
            if(table[j][col] < table[row][col]){
                k = 0;
                break;
            }
        }
        if(k == 1){
            printf("[%d,%d]\n", row, col);
        }
    }
    return 0;
}
