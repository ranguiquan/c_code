#include <stdio.h>
#include <stdlib.h>
int tool(int m, int n, int option)//option == 0, return min; option == 1, return max
{
    if(option){
        if(m > n) return m;
        else return n;
    }else{
        if(m > n) return n;
        else return m;
    }
}
int solution1(int m, int n)
{
    int out = 1;
    int i;
    for(i = 2; i < tool(m, n, 0)/2 + 1; i++){
        if(m%i == 0 && n%i == 0){
            out = i;
        }
    }
    return out;
}
int solution2(int m, int n)
{
    int out = m*n;
    int i;
    for(i = m*n-1; i >= tool(m, n, 1); i--){
        if(i%m == 0 && i%n == 0){
            out = i;
        }
    }
    return out;
}
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n%d\n", solution1(m, n), solution2(m, n));
    return 0;
}
