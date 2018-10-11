#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    double a, b, c, d, x1, x2, x3, tmp1, tmp2, tmp3, tmp4, y1, y2, y3, tmp5;
    int i, j, k;
    double e = 0.0000001;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    tmp1 = -100.01;
    tmp2 = -99.01;
    while(tmp1 <= 100)
    {
        y1 = a * pow(tmp1, 3) + b * pow(tmp1, 2) + c * tmp1 + d;
        y2 = a * pow(tmp2, 3) + b * pow(tmp2, 2) + c * tmp2 + d;
        //printf("x1 = %lf y1 = %lf x2 = %lf y2 = %lf\n",tmp1, y1,tmp2, y2);

        if(y1 * y2 < 0)
        {
            //printf("y1 = %lf y2 = %lf\n", y1, y2);
            tmp3 = tmp1;
            tmp4 = tmp2;
            while((tmp4 - tmp3) > e)
            {   
                
                tmp5 = (tmp4 + tmp3)/2.0;
                y1 =  a * pow(tmp3, 3) + b * pow(tmp3, 2) + c * tmp3 + d;
                y2 =  a * pow(tmp4, 3) + b * pow(tmp4, 2) + c * tmp4 + d;
                y3 = a * pow(tmp5, 3) + b * pow(tmp5, 2) + c * tmp5 + d;
                if(y1 * y3 < 0)
                {
                    tmp4 = tmp5;
                }else
                {
                    tmp3 = tmp5;
                }
            }
            printf("%.2lf\n ", (tmp3 + tmp4)/2.0);
        }

        tmp1 += 1.0;
        tmp2 += 1.0;
    }
    return 0;
}
