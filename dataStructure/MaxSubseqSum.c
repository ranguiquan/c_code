//最大子列和的在线处理算法
#include <stdio.h>
#include <stdlib.h>
int maxSubseqSum(int a[], int n)
{
    int i;
    int thisSum, maxSum = 0;
    for(i = 0; i < n; i++)
    {
        thisSum += a[i];
        if(thisSum > maxSum)
        {
            maxSum = thisSum;//当前和大于最大和，更新最大和
        }else if(thisSum < 0)
        {
            thisSum = 0;//当前和小于0，不能使之后的和变的更大，舍弃
        }
    }
    return maxSum;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int i;
    int* a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    printf("%d\n", maxSubseqSum(a, n));
    return 0;
}
