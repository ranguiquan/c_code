/*程序说明：清橙a1103
 * 作者：冉桂全*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x, i, j, k, m;
    int n = 1;
    scanf("%d", &x);
    for(i = 0; i < x; i++){
        n = n*2;
    }
    int* a = (int*)malloc(sizeof(int) * n*n);
    int tmp[n];
    for(i = 0; i < n*n; i++){
        *(a + i) = 0;
    }
    for(i = 0; i < n-1; i++){
        printf("<%d>", i+1);
        for(m = 0; m < n; m++){
            tmp[m] = 0;
        }
        for(j = 0; j < n; j++){
            for(k = j+1; k < n; k++){
                if(a[j*n + k] == 1 || (tmp[j] == 1 || tmp[k] == 1)){
                    continue;
                }else{
                    tmp[j] = 1;
                    tmp[k] = 1;
                    a[j*n + k] = 1;
                    printf("%d-%d ", j+1, k+1);
                }
            }
        }
        printf("\n");
    }
}
