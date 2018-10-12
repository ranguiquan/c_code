#include <stdio.h>
int main(void)
{
    int a;
    scanf("%d", &a);
    if(a >= 90)
    {
        printf("4.0");
    }else if(a >= 86)
    {
        printf("3.7");
    }else if(a >= 83)
    {
        printf("3.3");
    }else if(a >= 80)
    {
        printf("3.0");
    }else if(a >= 76)
    {
        printf("2.7");
    }else if(a >= 73)
    {
        printf("2.3");
    }else if(a >= 70)
    {
        printf("2.0");
    }else if(a >= 66)
    {
        printf("1.7");
    }else if(a >= 63)
    {
        printf("1.3");
    }else if(a >= 60)
    {
        printf("1.0");
    }else
    {
        printf("0");
    }
    return 0;
}
