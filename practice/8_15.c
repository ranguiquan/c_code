#include <stdio.h>
#include <stdlib.h>
#define STUNUM 4
#define COUSNUM 5

typedef struct student{
    char name[20];
    int number;
    float scores[COUSNUM];
}student;

float solution1(student* a);
void solution2(student* a);
void solution3(student* a);
float average(float a[]);

int main(void)
{
    student a[STUNUM];
    int i, j;
    for(i = 0; i < STUNUM; i++){
        printf("student %d\n", i+1);
        printf("name:");
        scanf("%s", a[i].name);
        printf("number:");
        scanf("%d", &a[i].number);
        printf("scores:");
        for(j = 0; j < COUSNUM; j++){
            scanf("%f", &a[i].scores[j]);
        }
    }
    printf("course1 average:%f", solution1(a));
    solution2(a);
    solution3(a);
    return 0;
}

float average(float a[])
{
    float sum = 0;
    int i;
    for(i = 0; i < COUSNUM; i++){
        sum += a[i];
    }
    return sum/COUSNUM;
}

float solution1(student* a)
{
    float sum = 0;
    int i;
    for(i = 0; i < STUNUM; i++){
        sum += a[i].scores[0];
    }
    return sum;
}

void solution2(student* a)
{
    int i, j, count;
    for(i = 0; i < STUNUM; i++){
        count = 0;
        for(j = 0; j < COUSNUM; j++){
            if(a[i].scores[j] < 60) count++;
        }
        if(count >= 2){
            printf("number:%d\n", a[i].number);
            for(j = 0; j < COUSNUM; j++){
                printf("course%d:%f\n", j, a[i].scores[j]);
            }
            printf("average:%f\n", average(a[i].scores));
        }
    }
}

void solution3(student* a)
{
    int i, j;
    int key;
    for(i = 0; i < STUNUM; i++){
        key = 1;
        for(j = 0; j < COUSNUM; j++){
            if(a[i].scores[j] <= 85){
                key = 0;
                break;
            }   
        }
        if(key && average(a[i].scores) > 90){
            printf("%s ", a[i].name);
        }
    }
    printf("\n");
}
