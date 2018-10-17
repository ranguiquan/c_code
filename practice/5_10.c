#include <stdio.h>
#include <stdlib.h>

void solution1(int n)
{
    int i = 0;
    float tmp, ans;
    ans = 0;
    float a[2] = {2,3};
    float b[2] = {1,2};
    while(i < n){
        if(i == 0) ans += 2;
        else if(i == 1) ans += a[1]/b[1];
        else{
            tmp = a[1];
            a[1] = a[1] + a[0];
            a[0] = tmp;
            tmp = b[1];
            b[1] = b[1] + b[0];
            b[0] = tmp;
            ans += a[1]/b[1];
        }
        i++;
    }
    printf("%f", ans);
}
int main(void)
{
    solution1(20);
    return 0;
}
