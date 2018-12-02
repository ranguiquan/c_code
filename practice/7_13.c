#include <stdio.h>
#include <stdlib.h>

double getAnswer(int, double);

int main(void)
{
    int n;
    double x;
    printf("n = ");
    scanf("%d", &n);
    printf("x = ");
    scanf("%lf", &x);
    printf("%lf", getAnswer(n,x));
    return 0;
}

double getAnswer(int n, double x)
{
    if(n == 0){
        return 1.0;
    }else if(n == 1){
        return x;
    }else{
        return (double)((2*n - 1)*x - getAnswer(n-1, x) - (n-1)*getAnswer(n-2, x))/n;
    }
}
