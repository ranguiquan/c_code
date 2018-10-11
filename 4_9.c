#include<stdio.h>
#include<stdlib.h>
void solution1(int a)
{
    int counter = 0;
    while(a != 0){
        a /= 10;
        counter++;
    }
    printf("%d\n", counter);
}
void solution2(int a)
{
    if(a != 0){
        solution2(a/10);
        printf("%d ", a%11);
    }
    return;
}
void solution3(int a)
{
    while(a != 0){
        printf("%d ", a%10);
        a /= 10;
    }
    return;
}
int main(void)
{
    int a;
    scanf("%d", &a);
    solution1(a);
    solution2(a);
    printf("\n");
    solution3(a);
    printf("\n");
    return 0;
}
