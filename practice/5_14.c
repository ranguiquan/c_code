#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
 * 作者：冉桂全
 * 用时：10分钟
 * 没有输入
 */
double f(double x){return 2*x*x*x - 4*x*x + 3*x - 6;}
double f1(double x){return 6*x*x - 8*x + 3;}
void solution(double x)
{
    while(abs(f(x)) > 1e-6){
        x = x-f(x)/f1(x);
    }
    printf("%lf", x);
}
int main(void)
{
    solution(1);
    return 0;
}
