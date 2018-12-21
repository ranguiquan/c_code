#include <stdio.h>
#include <stdlib.h>

typedef struct date{
    int year;
    int month;
    int day;
} date;

int daysOfMonth[2][12] = {{31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31}};

int isLeap(int year)
{
    if(year%400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return 1;
    }else{
        return 0;
    }
}

int main(void)
{
    date a;
    int ans = 0;
    int i;
    printf("year=");
    scanf("%d", &a.year);
    printf("month=");
    scanf("%d", &a.month);
    printf("day=");
    scanf("%d", &a.day);
    if(isLeap(a.year)){
        for(i = 0; i < a.month-1; i++){
            ans += daysOfMonth[0][i];
        }
        ans += a.day;
    }else{
        for(i = 0; i < a.month-1; i++){
            ans += daysOfMonth[1][i];
        }
        ans += a.day;
    }
    printf("ans=%d", ans);
    return 0;
}
