#include <stdio.h>
#include <stdlib.h>

void solution(void)
{
    int information[3][3] = 
    {{-1,1,1},
        {1,1,1},
        {-1,1,-1}};
    int sum[3] = {0,0,0};
    int i;
    for(i = 0; i < 3; i++){
        sum[1] += information[0][i];
        sum[2] += information[1][i];
        sum[3] += information[2][i];
    }
    while(sum1!=-1 || sum2!=-1 || sum3!=-1){
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
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
        {

        }}
}
