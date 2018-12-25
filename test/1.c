#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    int* array = (int*)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", array+i);
    }
    qsort((void*)array, n,sizeof(int), compare);

    int maxnumber = *array, maxcount = 1;
    int thiscount = 1;
    for(i = 1; i < n; i++){
        if(*(array+i) == *(array+i-1)){
            thiscount++;
        }else{
            thiscount = 1;
        }
        if(thiscount > maxcount){
            maxcount = thiscount;
            maxnumber = *(array+i);
        }
    }

    printf("%d\n", maxnumber);
    return 0;
}
