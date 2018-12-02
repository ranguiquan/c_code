#include <stdlib.h>
#include <stdio.h>

int howManyDaysHavePast(int year, int month, int day);
int isleap(int year);

int main(void)
{
    int year, month, day;
    printf("year:");
    scanf("%d", &year);
    printf("month:");
    scanf("%d", &month);
    printf("day:");
    scanf("%d", &day);
    printf("%d days have past\n", howManyDaysHavePast(year, month, day));
    return 0;
}

int howManyDaysHavePast(int year, int month, int day)
{
    int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int ans = 0;
    int i;
    if(isleap(year)){
        for(i = 1; i < month; i++){
            ans += days[1][i];
        }
        ans += day;
    }else{
        for(i = 1; i < month; i++){
            ans += days[0][i];
        }
        ans += day;
    }
    return ans;
}

int isleap(int year)
{
    if(year%400 == 0 
            || (year%4 == 0 && year%100 != 0)){
        return 1;
    }else{
        return 0;
    }
}
