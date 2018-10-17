#include <stdio.h>
#include <stdlib.h>
float ab(float a)
{
    if(a>0) return a;
    else return -a;
}
float tool(float x, float a)
{
    return 1.0/2.0 * (x + a/x);
}
float solution(float a)
{
    float x1 = a;
    float x2 = tool(x1, a);
    while(ab(x1-x2) >= 1e-5){
        x1 = x2;
        x2 = tool(x1, a);
    }
    return (x1 + x2)/2;
}
int main(void)
{
    float a;
    scanf("%f", &a);
    printf("%f", solution(a));
    return 0;
}
