#include <stdio.h>
int main(void)
{
    char a;
    scanf("%c", &a);
    if(a <= 'Z' && a >= 'A')
    {
        printf("%c\n", a + 'a' - 'A');
    }else
    {
        printf("%c\n", a + 'A' - 'a');
    }
    return 0;
}
