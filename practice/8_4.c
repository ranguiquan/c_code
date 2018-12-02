#include <stdio.h>
#include <stdlib.h>

void solution(int a[], int n, int m);

int main(void)
{
    int n, m;
    printf("n=");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    int i;
    printf("array:");
    for(i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    printf("m=");
    scanf("%d", &m);
    solution(a, n, m);
    for(i = 0; i < n; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
    return 0;
}

void solution(int a[], int n, int m)
{
    int* tmp = (int *)malloc(sizeof(int) * (n-m));
    int i;
    for(i = 0; i < n-m; i++){
        *(tmp+i) = *(a+i);
    }
    for(i = 0; i < m; i++){
        a[i] = a[n-m+i];
    }
    for(i = m; i < n; i++){
        a[i] = tmp[i-m];
    }
    return;
}
