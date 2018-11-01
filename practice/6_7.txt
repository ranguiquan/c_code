#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void put(int* table, int n);
int main(void)
{
    int n, i, center, j;
    int x, y;
    printf("输入一个奇数\n");
    scanf("%d", &n);
    int** table = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++){
        *(table+i) = (int*)malloc(sizeof(int) * n);
        memset(*(table+i), 0, sizeof(int)*n);
    }
    x = 0;
    y = (n-1)/2;
    table[x][y] = 1;
    for(i = 2; i <= n*n; i++){
        while(table[(x-1+n)%n][(y+1)%n] != 0 ){
            x = (int)(x+1)%n;
        }
        x = (int)(x-1+n)%n;
        y = (int)(y+1)%n;
        table[x][y] = i;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}
