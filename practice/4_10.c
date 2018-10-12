#include <stdio.h>
#include <stdlib.h>
void solution(int a)
{
    int x1, x2, x3, x4, x5;
    x1 = 1e5;
    x2 = 2e5;
    x3 = 4e5;
    x4 = 6e5;
    x5 = 1e6;
    float r1, r2, r3, r4, r5, r6;
    r1 = 0.1;
    r2 = 0.075;
    r3 = 0.05;
    r4 = 0.03;
    r5 = 0.015;
    r6 = 0.01;
    float out = 0;
    if(a <= x1){
        out = r1 * a;
    }else if( a <= x2 ){
        out = r1 * x1 + r2*(a-x1);
    }else if( a <= x3 ){
        out = r1*x1 + r2*(x2-x1) + r3*(a-x1-x2);
    }else if(a <= x4){
        out = r1*x1 + r2*(x2-x1) + r3*(x3-x2-x1) +r4*(a-x1-x2-x3);
    }else if(a <= x5){
        out = r1*x1 + r2*(x2-x1) + r3*(x3-x2-x1) + r4*(x4-x3-x2-x1) + r5*(a-x4-x3-x2-x1);
    }else{
        out = r1*x1 + r2*(x2-x1) + r3*(x3-x2-x1) + r4*(x4-x3-x2-x1) + r5*(x5-x4-x3-x2-x1) + r6*(a-x1-x2-x3-x4-x5);
    }
    printf("%.0f\n",out);
    return;
}
int main(void)
{
    int a;
    scanf("%d", &a);
    solution(a);
    return 0;
}
