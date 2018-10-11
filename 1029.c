#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int room[8] = {120, 40, 85, 50, 100, 140, 70, 100};
    int classes[4];
    int choose[4] = {-1, -1, -1, -1};
    int mark[8] = {0,0,0,0,0,0,0,0};
    int a, b, c, d, i;
    int counter = 0;
    for(i = 0; i < 4; i++)
    {
        scanf("%d", &classes[i]);
    }
    for(a = 0; a < 8; a++)
    {
        if(room[a] >= classes[0])
        {
            choose[0] = a;
            mark[a] = 1;
        }
        for(b = 0; b < 8; b++)
        {
            if(room[b] >= classes[1] && mark[b] == 0)
            {
                choose[1] = b;
                mark[b] = 1;
            }
            for(c = 0; c < 8; c++)
            {
                if(room[c] >= classes[2] && mark[c] == 0)
                {
                    choose[2] = c;
                    mark[c] = 1;
                }
                for(d = 0; d < 8; d++)
                {
                    if(room[d] >= classes[3] && mark[d] == 0)
                    {
                        choose[3] = d;
                        mark[d] = 1;
                    }

                    int key = 1;
                    for(i = 0; i < 4; i++)
                    {
                        if(choose[i] == -1)
                        {
                            key = 0;
                            break;
                        }
                    }
                    if(key)
                    {
                        counter++;
                        for(i = 0; i < 4; i++)
                        {
                            printf("%d ", choose[i] + 1);
                        }
                        printf("\n");
                    }

                    if(choose[3] == d)
                    {
                        choose[3] = -1;
                        mark[d] = 0;
                    }
                }
                if(choose[2] == c)
                {
                    choose[2] = -1;
                    mark[c] = 0;
                }
            }
            if(choose[1] == b)
            {
                choose[1] = -1;
                mark[b] = 0;
            }
        }
        if(choose[0] == a)
        {
            choose[0] = -1;
            mark[a] = 0;
        }   
    }
    if(counter == 0)
    {
        printf("-1");
    }
    return 0;
}
