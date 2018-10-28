#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM 100
/*冒泡排序6_3
 * 作者：冉桂全
 * 时间：20分钟
 * 没有输入
 * 排序对象：指定长度的随机数，改变NUM和种子来调试
 */
void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int bubble(int* array)
{
    int counter = 0;
    int i, j;
    for(i = 0; i < NUM-1; i++){
        for(j = i+1; j < NUM; j++){
            counter++;
            if(array[i] > array[j]){
                swap(&array[i], &array[j]);
            }
        }
    }
    return counter;
}
int main(void)
{
    srand(time(NULL));
    int i;
    int array[NUM];
    printf("之前的数组\n");
    for(i = 0; i < NUM; i++){
        array[i] = rand()/10000000;
        printf("%d ", array[i]);
    }
    printf("\n");
    int counter = bubble(array);
    printf("之后的数组\n");
    for(i = 0; i < NUM; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("共进行了%d次比较\n", counter);
    return 0;
}
