#include<stdio.h>
#include<stdlib.h>
void solution1(long long a)
{
    int counter = 0;
    while(a != 0){
        a /= 10;
        counter++;
    }
    printf("%d\n", counter);
}
void solution2(long long a)
{
    if(a != 0){
        solution2(a/10);
        printf("%lld ", a%10);
    }
    return;
}
void solution3(long long a)
{
    while(a != 0){
        printf("%lld", a%10);
        a /= 10;
    }
    return;
}
int main(void)
{
    long long a;
    scanf("%lld", &a);
    solution1(a);
    solution2(a);
    printf("\n");
    solution3(a);
    printf("\n");
    return 0;
}
