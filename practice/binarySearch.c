#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* number, int n, int m)
{
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(low <= high){
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
