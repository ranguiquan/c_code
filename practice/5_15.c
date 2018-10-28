#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 5_15
 * 作者：冉桂全
 * 时间：4分钟
 * 没有输入
 */
double f(double x){return 2*x*x*x - 4*x*x + 3*x - 6;}
void solution(double left, double right)
{
    double mid = (left+right)/2;
    while(right-left > 1e-6){
        if(f(left) * f(mid) < 0){
            right = mid;
            mid = (left+right)/2;
        }else{
            left = mid;
            mid = (left+right)/2;
        }
    }
    printf("%lf", (left+right)/2);
}
int main(void){
    solution(-10, 10);
    return 0;
}
