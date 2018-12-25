#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int coins[3] = {1,2,5};
    int money;
    int i, j, k;
    int count = 0;
    scanf("%d", &money);
    count += money/coins[2];
    money = money%coins[2];
    count += money/coins[1];
    money = money%coins[1];
    count += money;
    printf("%d\n", count);
    return 0;
}
