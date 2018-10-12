#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num(int a, int n)//a,数字 n,第n位
{
    return (a/pow(10, n-1) - floor((a/pow(10, n)))*10);
}

/*int main(void)
{
    int a = 1234;
    int i;
    for(i = 1; i <= 4; i++){
        printf("%d\n", num(a, i));
    }
}*/
int main(void)
{   FILE* fp = fopen("/home/ran/Documents/c_code/out.txt", "w");
    int n, i, j, x, y, z, k, flag;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    int* b = (int*)malloc(sizeof(int) * n);
    int* c = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %d %d", a+i, b+i, c+i);
    }
    int max;
    for(i = 0; i < n; i++)
    {
        flag = 0;
        max = 0;
        x = 0;
        y = 0;
        z = 0;
        for(j = 1; j <= 8; j++ )
        {
            if(num(*(a+i), j) > max)
            {
                max = num(*(a+i), j);
            }
            if(num(*(b+i), j) > max)
            {
                max = num(*(b+i), j);
            }
            if(num(*(c+i), j) > max)
            {
                max = num(*(c+i), j);
            }
        }
        for(j = max+1; j <= 16; j++)//一种进制
        {
            x = 0;
            y = 0;
            z = 0;
            for(k = 1; k <= 8; k++)//一个位
            {
                x += num(*(a+i), k) * pow(j, k-1);
                y += num(*(b+i), k) * pow(j, k-1);
                z += num(*(c+i), k) * pow(j, k-1);
            }
            if(x*y == z)
            {
                fprintf(fp, "%d\n", j);//test
                printf("%d\n", j);
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {   
            fprintf(fp, "0\n");//test
            printf("0\n");
        }
    }
    return 0;
}
