#include <stdio.h>
#include <stdlib.h>
/*
 * 5_17
 * 作者：冉桂全
 * 时间：30分钟
 * 没有输入
 */ 
void solution(void)
{
    int information[3][3] = 
    {{-1,1,1},
        {1,1,1},
        {-1,1,-1}};
    char conversion1[3] = {'A','B','C'};
    char conversion2[3] = {'X','Y','Z'};
    int sum[3] = {0,0,0};
    int i,j,k;
    for(i = 0; i < 3; i++){
        sum[0] += information[0][i];
        sum[1] += information[1][i];
        sum[2] += information[2][i];
    }
    
        for(i = 0; i < 3; i++){
            printf("sum[%d] = %d\n", i, sum[i]);
        }
        printf("\n");
    while(sum[0]!=-1 || sum[1]!=-1 || sum[2]!=-1){
        for(i = 0; i < 3; i++){
            if(sum[i] == -1){
                for(j = 0; j < 3; j++){
                    if(information[i][j] == 1){
                        for(k = 0; k < 3; k++){
                            information[k][j] = -1;
                        }
                        information[i][j] = 1;
                    }
                }
            }
        }
        for(i = 0; i < 3; i++){
            sum[i] = 0;
        }
        for(i = 0; i < 3; i++){
            sum[0] += information[0][i];
            sum[1] += information[1][i];
            sum[2] += information[2][i];
        }

        for(i = 0; i < 3; i++){
            printf("sum[%d] = %d\n", i, sum[i]);
        }
        printf("\n");
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(information[i][j] == 1){
                printf("%c:%c\n", conversion1[i],conversion2[j]);
            }
        }
    }
}
int main(void)
{
    solution();
    return 0;
}
