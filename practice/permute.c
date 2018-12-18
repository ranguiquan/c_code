#include <stdio.h>
#include <stdlib.h>
//全排列
int r = 4;
char data[4] = {'a', 'b', 'c', 'd'};//带排元素
int used[4] = {0,0,0,0};//标记元素是否被使用
char p[4];//排列结果
void permute(int pos)//pos:position 当前排的第几个元素
{
    int i = 0;
    if(pos == r)
    {
        for(i = 0; i < r; i++){
            printf("%c ", p[i]);
        }
        printf("\n");
        return;
    }
    //递归边界
    for(i = 0; i < r; i++){//遍历当前可用元素
        if(!used[i]){
            used[i]++;//标记为已用
            p[pos] = data[i];
            permute(pos+1);
            used[i]--;//退出递归后标记为未用
        }
    }
}
int main(void)
{
    permute(0);
    return 0;
}
