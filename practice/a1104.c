/*程序描述：清橙a1104
 * 作者：冉桂全*/

#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1000
int main(void)
{
    int g1, g2, g3, g5, g10, g20, i1, i2, i3, i5, i10, i20, j;
    int total;
    int count = 0;
    int key = 1;
    int a[6] = {0};
    int tt[BUF_SIZE];
    for(j = 0; j < BUF_SIZE; j++)
    {
        tt[j] = -1;
    }
    scanf("%d", &g1);
    scanf("%d", &g2);
    scanf("%d", &g3);
    scanf("%d", &g5);
    scanf("%d", &g10);
    scanf("%d", &g20);
    for(i1 = 0; i1 <= g1; i1++)
    {
        for(i2 = 0; i2 <= g2; i2++)
        {
            for(i3 = 0; i3 <= g3; i3++)
            {
                for(i5 = 0; i5 <=g5; i5++)
                {
                    for(i10 = 0; i10 <= g10; i10++)
                    {
                        for(i20 = 0; i20 <= g20; i20++)
                        {
                            total = i1*1 + i2*2 + i3*3 + i5*5 + i10*10 + i20*20;
                            key = 1;
                            for(j = 0; tt[j] > -1 && j < BUF_SIZE; j++)
                            {
                                if(total == tt[j])
                                {
                                    key = 0;
                                    break;
                                }
                            }
                            if(key == 1)
                            {
                                tt[j] = total;
                            }
                        }
                    }
                }
            }
        }
    }
    for(j = 0; tt[j] != -1 && j < BUF_SIZE; j++)
    {
        count++;
    }
    printf("Total=%d", count-1);
    return 0;
}
