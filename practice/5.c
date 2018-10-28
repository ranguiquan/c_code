#include <stdio.h>
#include <stdlib.h>
/*
 * 筛选法算素数
 * 作者：冉桂全
 * 时间：25分钟
 * 测试：10/100/1000/10000
 */
void solution(int n)
{
    int* array = (int*)malloc(sizeof(int) * (n+1));
    int i;
    for(i = 0; i <= n; i++){
        *(array+i) = 1;
    }
    array[0] = 0;
    array[1] = 0;
    int tmp = 0;
    while(tmp <= n/2){
        while(array[tmp] == 0){tmp++;}
        for(i = 2; i < (double)(n+1)/tmp; i++ ){
            array[i*tmp] = 0;
        }
        tmp++;
    }
    for(i = 0; i <= n; i ++){
        if(array[i] == 1){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void)
{
    int i;
    scanf("%d", &i);
    solution(i);
    return 0;
}
