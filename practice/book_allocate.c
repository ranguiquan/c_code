#include <stdio.h>
#include <stdlib.h>

void allocate(int** matrix, int n, int m);
void allocate_keyModule(int** matrix, int n, int m, int thisman, int* bookUsed, int* scheme_num);
void show(int** matrix, int n, int m, int* scheme_num);



void allocate(int** matrix, int n, int m)
{
    int* bookUsed = (int*)calloc(sizeof(int),sizeof(int) * m);
    int scheme_num = 0;
    allocate_keyModule(matrix, n, m, 0, bookUsed, &scheme_num);
}


void allocate_keyModule(int** matrix, int n, int m, int thisman, int* bookUsed, int* scheme_num)
{
    int i;
    for(i = 0; i < m; i++){
        if(matrix[thisman][i] == 1 && bookUsed[i] == 0){
            bookUsed[i]++;
            matrix[thisman][i] = 2;
            if(thisman == n-1){
                (*scheme_num)++;
                show(matrix, n, m, scheme_num);
                matrix[thisman][i] = 1;
                bookUsed[i]--;
                return;
            }else{
                allocate_keyModule(matrix, n, m, thisman+1, bookUsed, scheme_num);
                bookUsed[i]--;
                matrix[thisman][i] = 1;
            }
        }
    }
}

void show(int** matrix, int n, int m, int* scheme_num)
{
    int i,j;
    printf("NO.%d scheme\n", *scheme_num);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(matrix[i][j] == 2){
                printf("book%d is given to person%d\n", j, i);
            }
        }
    }
}

int main(void)
{
    int i, j;
    int m, n;//n:man m:book
    scanf("%d %d", &m, &n);
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++){
        *(matrix + i) = (int*)malloc(sizeof(int) * m);
    }//row:n,man column:m,book
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", *(matrix+i) + j);
        }
    }
    allocate(matrix, n, m);
}
