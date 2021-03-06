#include <stdio.h>
#include <stdlib.h>
int counter = 0;

void display(int array[], int maxlen)  
{  
    int i;  
  
    for(i = 0; i < maxlen; i++)  
    {  
        printf("%-3d", array[i]);  
    }  
    printf("\n");  
  
    return ;  
}  
  
/******************************** 
 *函数名：swap 
 *作用：交换两个数的值 
 *参数：交换的两个数 
 *返回值：无 
 ********************************/  
void swap(int *a, int *b)    
{  
    int temp;  
  
    temp = *a;  
    *a = *b;  
    *b = temp;  
  
    return ;  
}  
  
/************************************ 
 *函数名：quicksort 
 *作用：快速排序算法 
 *参数： 
 *返回值：无 
 ************************************/  
void quickSort(int array[], int maxlen, int begin, int end)  
{  
    int i, j;  
  
    if(begin < end)  
    {  
        i = begin + 1;  // 将array[begin]作为基准数，因此从array[begin+1]开始与基准数比较！  
        j = end;        // array[end]是数组的最后一位  
            
        while(i < j)  
        {  
            if(array[i] > array[begin])  // 如果比较的数组元素大于基准数，则交换位置。  
            {  
                swap(&array[i], &array[j]);  // 交换两个数  
                j--;  
            }  
            else  
            {  
                i++;  // 将数组向后移一位，继续与基准数比较。  
            }  
        }  
  
        /* 跳出while循环后，i = j。 
         * 此时数组被分割成两个部分  -->  array[begin+1] ~ array[i-1] < array[begin] 
         *                           -->  array[i+1] ~ array[end] > array[begin] 
         * 这个时候将数组array分成两个部分，再将array[i]与array[begin]进行比较，决定array[i]的位置。 
         * 最后将array[i]与array[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！ 
         */  
  
        if(array[i] >= array[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！  
        {  
            i--;  
        }  
  
        swap(&array[begin], &array[i]);  // 交换array[i]与array[begin]  
        quickSort(array, maxlen, begin, i);  
        quickSort(array, maxlen, j, end);  
    }  
} 
int binarySearch(int* number, int n, int m)
{
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(low <= high){
        counter++;
        mid = (low + high)/2;
        if(*(number + mid)  ==m){
            return mid;
        }else if(*(number + mid) > m){
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    return -1;
}


int main(void)
{
    int n, x, i;
    scanf("%d %d", &n, &x);
    int* a = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    quickSort(a, n, 0, n-1);
    printf("%d\n", binarySearch(a, n, x));
    printf("%d\n", counter);
    return 0;
}
