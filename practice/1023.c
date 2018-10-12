#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    int counter = 0;
    scanf("%d", &n);
    for(i = 1; i < n; i++)
    {
        if(i%2 == 1 &&
                i%3 == 2 &&
                i%5 == 4 &&
                i%6 == 5 &&
                i%7 == 0)
        {
            printf("%d\n", i);
            counter ++;
        }
    }
    if(counter == 0)
    {
        printf("No answer\n");
    }
    return 0;
}
