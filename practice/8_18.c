#include <stdio.h>
#include <stdlib.h>

void solution(int n)
{
    char* month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "Octomber", "November", "December"};
    printf("%s\n", month[n-1]);
    return;
}

int main(void)
{
    int n;
    printf("n=");
    scanf("%d", &n);
    solution(n);
    return 0;
}
