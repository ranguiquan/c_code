#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 100

int compare(const void* a, const void* b)
{
    return strcmp(*(char**)a, *(char**)b);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    char** arrays = (char**)malloc(sizeof(char*) * n);
    int i,j;
    for(i = 0; i < n; i++){
        *(arrays + i) = (char*)malloc(sizeof(char) * BUF);
    }
    for(i = 0; i < n; i++){
        scanf("%s", *(arrays + i));
    }
    qsort((void*)arrays, n, sizeof(char*), compare);
    for(i = 0; i < n; i++){
        printf("%s\n", *(arrays + i));
    }
}
