#include <stdio.h>
#include <stdlib.h>
//全排列

void permute(int pos, int n, int* data, int* used, int* p)//pos:position 当前排的第几个元素
{
    int i = 0;
    if(pos == n)
    {
        for(i = 0; i < n; i++){
            printf("%d ", p[i]);
        }
        printf("\n");
        return;
    }
    //递归边界
    for(i = 0; i < n; i++){//遍历当前可用元素
        if(!used[i]){
            used[i]++;//标记为已用
            p[pos] = data[i];
            permute(pos+1, n, data, used, p);
            used[i]--;//退出递归后标记为未用
        }
    }
}
int main(void)
{
    int n, i;
    scanf("%d", &n);
    int* data = (int*)malloc(sizeof(int) * n);
    int* used = (int*)calloc(sizeof(int), sizeof(int) * n);
    int* p = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", data+i);
    }
    permute(0, n, data, used, p);
    return 0;
}
