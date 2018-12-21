#include <stdio.h>
#include <stdlib.h>

void move(int** table, int n, int m, int x, int y, int** used, int ans, int* ptrToMax);
//table 棋盘
//n 行数
//m 列数
//x 行坐标
//y 列坐标
int check(int n, int m, int x, int y, int** used);


int check(int n, int m, int x, int y, int** used)
{
    if(x>= 0 && y >= 0 && x < n && y < m && used[x][y] == 0){
        return 1;
    }else{
        return 0;
    }
}

void move(int** table, int n, int m, int x, int y, int** used, int ans, int* ptrToMax)
{
    printf("line24\n");
    printf("x = %d\t y = %d\n", x, y);
    int i;
    int directions[3][2] = {{0,-1}, {0,1}, {1,0}};
    ans += table[x][y];
    if(x == n-1 && y == m-1){
        if(ans > *ptrToMax) *ptrToMax = ans;
    }else{
        for(i = 0; i < 3; i++){
            if(check(n, m, x+directions[i][0], y+directions[i][1], used) == 1){
                used[x+directions[i][0]][y+directions[i][1]]++;
                move(table, n, m, x+directions[i][0], y+directions[i][1], used, ans, ptrToMax);
                used[x+directions[i][0]][y+directions[i][1]]--;
            }
        }
    }
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    int** table = (int**) malloc(sizeof(int*) * n);
    int** used = (int**)malloc(sizeof(int*) * n);
    int i, j;
    int max = 0;
    for(i = 0; i < n; i ++){
        *(table + i) = (int*)malloc(sizeof(int) * m);
    }
    for(i = 0; i < n; i++){
        *(used + i) = (int*)calloc(sizeof(int), sizeof(int) * m);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", *(table+i) + j);
        }
    }
    used[0][0]++;
    move(table, n, m, 0, 0, used, 0, &max);
    printf("%d", max);
    for(i = 0; i < n; i++){
        free(*(table+i));
        free(*(used+i));
    }
    free(table);
    free(used);
    return 0;
}
