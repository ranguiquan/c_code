#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int get(int a, int n)
{
    return a/(int)(pow(10,n-1))%10;
}
void solution()
{
    int i;
    for(i = 100; i < 1000; i++)
    {
        if(i == (int)(pow(get(i, 1), 3) + pow(get(i, 2), 3) + pow(get(i, 3), 3))){
            printf("%d\n", i);
        }
    }
}

int main(void)
{
    solution();
    return 0;
}
