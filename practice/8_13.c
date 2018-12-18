#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(double a, double b)
{
    double tmp;
    tmp = a;
    a = b;
    b = tmp;
}

double inte_sin(double x1, double x2)
{
    int negative = 0;
    double ans = 0;
    if(x1 > x2){
        swap(x1, x2);
        negative = 1;
    }
    double x = x1;
    double foot = 1e-6;
    while(x < x2){
        x += foot;
        ans += foot * sin(x);
    }
    if(negative) ans = -ans;
    return ans;
}
double inte_cos(double x1, double x2)
{
    int negative = 0;
    double ans = 0;
    if(x1 > x2){
        swap(x1, x2);
        negative = 1;
    }
    double x = x1;
    double foot = 1e-6;
    while(x < x2){
        x += foot;
        ans += foot * cos(x);
    }
    if(negative) ans = -ans;
    return ans;
}
double inte_exp(double x1, double x2)
{
    int negative = 0;
    double ans = 0;
    if(x1 > x2){
        swap(x1, x2);
        negative = 1;
    }
    double x = x1;
    double foot = 1e-6;
    while(x < x2){
        x += foot;
        ans += foot * exp(x);
    }
    if(negative) ans = -ans;
    return ans;
}

int main(void)
{
    printf("%lf\n", inte_sin(0,1));
    printf("%lf\n", inte_cos(0,1));
    printf("%lf\n", inte_exp(0,1));
    return 0;
}
