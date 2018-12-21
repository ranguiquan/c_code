#include <stdio.h>
#include <stdlib.h>
int factorial(int a);
int inverse_number(int* arrangement, int n);
void det_module(int** table, int* ans, int* used, int n, int* arrangement, int* index);
int det(int** table, int n);

int factorial(int a)
{
    int ans = 1;
    for(; a > 0; a--){
        ans *= a;
    }
    return ans;
}

int inverse_number(int* arrangement, int n)
{
    int ans = 0;
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arrangement[i] > arrangement[j]) ans++;
        }
    }
    return ans;
}

void det_module(int** table, int* ans, int* used, int n, int* arrangement, int* index)
{
    int i, j;
    if(*index == n-1){
        for(i = 0; i < n; i++){
            if(used[i] == 0){
                arrangement[*index] = i;
                if(inverse_number(arrangement, n)%2 == 0){
                    int item = 1;
                    for(j = 0; j < n; j++){
                        item *= table[j][arrangement[j]];
                    }
                    *ans += item;
                }else{
                    int item = -1;
                    for(j = 0; j < n; j++){
                        item *= table[j][arrangement[j]];
                    }
                    *ans += item;
                }
            }
        }
    }else{
        for(i = 0; i < n; i++){
            if(used[i] == 0){
                used[i]++;
                arrangement[*index] = i;
                (*index)++;
                det_module(table, ans, used, n, arrangement, index);
                used[i]--;
                (*index)--;
            }
        }
    }
}

int det(int** table, int n)
{
    int* arrangement = (int*)malloc(sizeof(int) * n);
    int* used = (int*)calloc(sizeof(int), sizeof(int) * n);
    int index = 0;
    int ans = 0;
    det_module(table, &ans, used, n, arrangement, &index);
    free(arrangement);
    free(used);
    return ans;
}
int main(void)
{
    int n, i, j, k;
    scanf("%d", &n);
    int** table = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++){
        *(table +i) = (int*)malloc(sizeof(int) * n);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", *(table + i) + j);
        }
    }
    int ans = det(table, n);
    printf("det = %d\n", ans);
    for(i = 0; i < n; i++){
        free(*(table+i));
    }
    free(table);
}
/*int main(void){
    int test[5] = {2,1,4,3,6};
    printf("%d", inverse_number(test, 5));
}*/

