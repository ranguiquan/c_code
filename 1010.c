#include <stdio.h>
int main(void)
{
    int n;
    float c;
    
    scanf("%d", &n);
    c = (float)(n - 32) * 5 / 9;
    printf("%.2f", c);
    return 0;
}
