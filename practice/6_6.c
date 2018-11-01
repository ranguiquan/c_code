#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main(void)
{
    int array[SIZE+2];
    int i, tmp1, tmp2, j;
    for(i = 0; i <SIZE+2; i++){
        array[i] = 0;
    }
    array[1] = 1;
    for(i = 0; i < SIZE; i++){
        for(j = 1; j <SIZE+1; j++){
            if(array[j] != 0){
                printf("%d ", array[j]);
            }else break;
        }
        printf("\n");
        tmp2 = 0;
        for(j = 1; j < SIZE+1; j++){
            tmp1 = tmp2;
            tmp2 = array[j];
            array[j] = tmp1+tmp2;
        }
    }
    return 0;
}
