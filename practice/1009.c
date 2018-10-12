#include <stdio.h>
int main(void)
{
    int a, b;
    float x, y;
    char i, j;
    scanf("%d,%d", &a, &b);
    scanf("%f %f", &x, &y);
    scanf(" %c, %c", &i, &j);
    printf("%d,%d\n", a, b);
    printf("%.1f %.1f\n", x, y);
    printf(" %c, %c\n", i, j);
    return 0;
}
