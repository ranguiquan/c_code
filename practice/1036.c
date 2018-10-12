#include <stdio.h>
#include <stdlib.h>
int abs(int x)
{
    if(x > 0)
        
    {
        return x;
    }else{
        return -x;
    }
}
int main(void)
{
    int a, b;
    int i, j, k;
    
    scanf("%d %d", &a, &b);
    for(j = 0; j < a; j++)
    {
        for(i = 0; i < b; i++)
        {
            printf("%c", abs(i - j) + 'A');
        }
        printf("\n");
    }
    return 0;
}
