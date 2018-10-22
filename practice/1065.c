#include <stdio.h>
#include <stdlib.h>
void solution(int* a)
{
    int i,  m, flag, n, tmp;
    int out[20];
    for(i = 0; i < 20; i++){
        out[i] = 0;
    }
    n = 0;
    while(*(a + n) != 0){
        m = 2;
        flag = 0;
        while(m < *(a + n)){
            tmp =*(a+n);
            for(i = 0; i < m; i++){
                if(--tmp%m == 0){
                    tmp -= tmp/m;
                }else{
                    break;
                }
            }
            if(tmp%m == 0){
                flag = 1;
                out[n] = m;
            }
            m++;
        }
        n++;
    }
    for(i = 0; i < n; i++){
        if(out[i] == 0){
            printf("no solution\n");
        }else{
            printf("%d\n", out[i]);
        }
    }
}
int main(void)
{
    int n[21];
    int i = 0;
    scanf("%d", n);
    while(*(n+i) != 0){
        i++;
        scanf("%d", n+i);
    }
    solution(n);
    return 0;
    
}
