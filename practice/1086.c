#include <stdio.h>
#include <stdlib.h>

void move(int** table, int n, int m, int x, int y, int ans, int* ptrToMax);
//table 棋盘
//n 行数
//m 列数
//x 行坐标
//y 列坐标
int check(int** table, int n, int m, int x, int y, int old_x, int old_y);


int check(int** table, int n, int m, int x, int y, int old_x, int old_y) 
{
    if(x>= 0 && y >= 0 && x < n && y < m && table[x][y] < table[old_x][old_y]){
        return 1;
    }else{
        return 0;
    }
}

void move(int** table, int n, int m, int x, int y, int ans, int* ptrToMax)
{
    int i;
    int directions[4][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}};
    int flag = 1;//取1时表示已经走不通了
    ans++;
    for(i = 0; i < 4; i++){
        if(check(table, n, m, x+directions[i][0], y+directions[i][1], x, y)){
            flag = 0;
            move(table, n, m, x+directions[i][0], y+directions[i][1], ans, ptrToMax);
        }
    }
    if(flag){
        if(ans > *ptrToMax) *ptrToMax = ans;
    }
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int** table = (int**) malloc(sizeof(int*) * n);
    int i, j;
    int max = 1;
    for(i = 0; i < n; i ++){
        *(table + i) = (int*)malloc(sizeof(int) * m);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", *(table+i) + j);
        }
    }
    for(i= 0; i < n; i++){
        for(j = 0; j < n; j++){
            move(table, n, m, i, j, 0, &max);
        }
    }
    printf("%d\n", max);
    for(i = 0; i < n; i++){
        free(*(table+i));
    }
    free(table);
    return 0;
}
