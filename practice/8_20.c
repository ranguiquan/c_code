#include <stdio.h>
#include <stdlib.h>
#define DISH_COUNT 10

typedef struct dish{
    char* name;
    float price;
    int count;
}dish;

void display(dish* a, int n)
{
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d:\t%s\t%.2f元\n", i+1, (a+i)->name, (a+i)->price);
    }
}

void solution(void)
{
    char* dishes[DISH_COUNT] = {"鱼香肉丝", "红烧豆腐", "土豆牛肉", "西芹百合", "松仁玉米", "香菇油菜", "醋溜土豆丝", "米饭", "馒头", "豆浆"};
    float prices[DISH_COUNT] = {8, 7, 9, 7, 8, 6, 5, 0.5, 0.5, 2};
    dish* a = (dish*)malloc(sizeof(dish) * DISH_COUNT);
    int i, choice;
    float sum = 0;
    for(i = 0; i < DISH_COUNT; i++){
        (a+i)->name = dishes[i];
        (a+i)->price = prices[i];
        (a+i)->count = 0;
    }
    display(a, DISH_COUNT);
    printf("输入你想要的菜的序号，0结束选菜......\n");
    printf("> ");
    while(scanf("%d", &choice) && choice != 0){
        if(choice > 0 && choice < DISH_COUNT+1){
            (a+choice-1)->count++;
        }else{
            printf("输入有误，请重新输入\n");
        }
        printf("> ");
    }
    printf("******************************\n");
    printf("明细:\n");
    for(i = 0; i < DISH_COUNT; i++){
        if((a+i)->count > 0){
            sum += (a+i)->price * (a+i)->count;
            printf("%s: %d份 %.2f元\n", (a+i)->name, (a+i)->count, (a+i)->count * (a+i)->price);
        }
    }
    printf("共计: %f\n", sum);
    printf("******************************\n");
    free(a);
    return;
}

int main(void)
{
    while(1){
        solution();
    }
    return 0;
}
