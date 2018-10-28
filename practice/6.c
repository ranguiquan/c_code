#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NUM 100
/*
 * 二分搜索算法
 * 作者：冉桂全
 * 时间：30分钟
 * 待搜索数据生成：宏定义数组大小，产生随机数，用bubble排序。留了数据大小的接口，改成用户输入确定数组大小也很方便。
 * 二分搜索：用最简单的二分法找到target的下标，再向左右搜索确定区间。没有返回值，打印结果。
 * 测试：自己手动测试的，没有问题
 */
void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
int bubble(int* array, int n)
{
    int counter = 0;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            counter++;
            if(array[i] > array[j]){
                swap(&array[i], &array[j]);
            }
        }
    }
    return counter;
}
void search(int* array, int n, int target)
{
    int left = 0;
    int right = n-1;
    int mid = (left + right)/2;
    int begin, end = 1;
    int i;
    while(left <= right){
        if(array[mid] == target){
            begin = mid;
            end = mid;
            break;
        }
        if(array[mid] > target){
            right = mid-1;
            mid = (left+right)/2;
        }
        if(array[mid] < target){
            left = mid+1;
            mid = (left+right)/2;
        }
    }
    if(begin == -1){
        printf("not found\n");
    }else{
        while(begin > 0){
            if(array[begin-1] == target){
                begin--;
            }else break;
        }
        while(end < n-1){
            if(array[end+1] == target){
                end++;
            }else break;
        }
        printf("index: ");
        for(i = begin; i <= end; i++){
            printf("%d ", i);
        }
        printf("\n");
    }
}
int main(void)
{
    srand(time(NULL));
    int i;
    int array[NUM];
    int target;
    printf("之前的数组\n");
    for(i = 0; i < NUM; i++){
        array[i] = rand()/10000000;
        printf("%d ", array[i]);
    }
    printf("\n");
    int counter = bubble(array, NUM);
    printf("之后的数组\n");
    for(i = 0; i < NUM; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("请输入要查找的数字\n");
    scanf("%d", &target);
    search(array,NUM, target);
    return 0;
}
