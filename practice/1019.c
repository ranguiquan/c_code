#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int a[8][8] = {{-1,-1,-1,-1,-1,1,-1,1},
        {-1,1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,1,-1},
        {1,-1,1,1,1,1,1,1},
        {1,1,1,1,1,-1,1,-1},
        {1,1,1,1,1,-1,1,-1},
        {1,1,-1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,1,-1,1}};
    int n;
    scanf("%d", &n);
    int count, i, j, out, outcount;
    count = 0;
    outcount = 0;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(a[j][i] == 1)
            {
                count++;
            }
        }
        if(count == n)
        {
            out = i;
            outcount++;
        }

        count = 0;
    }
    if(outcount == 1)
    {
        switch(out)
        {
            case 0:
                printf("A\n");
                break;
            case 1:
                printf("B\n");
                break;
            case 2:
                printf("C\n");
                break;
            case 3:
                printf("D\n");
                break;
            case 4:
                printf("E\n");
                break;
            case 5:
                printf("F\n");
                break;
            case 6:
                printf("G\n");
                break;
            case 7:
                printf("H\n");
                break;
        }
    }else
    {
        printf("DONTKNOW");
    }
    return 0;
}
