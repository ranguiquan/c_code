#include<stdio.h>
#include<stdlib.h>

void solution1(void)
{
    char a[3] = {'A', 'B', 'C'};
    char b[3] = {'X', 'Y', 'Z'};
    int used[3] = {0,0,0};
    int i, j, k, n;
    for(i = 0; i < 3; i++){
        used[i]++;
        for(j = 0; j < 3; j++){
            if(used[j] == 0){
                used[j]++;
                for(k = 0; k < 3; k++){
                    if(used[k] == 0
                            && a[i] != 'A'
                            && a[i] != 'C'
                            && a[k] != 'C'){
                            printf("%c->%c\n", b[0], a[i]);
                            printf("%c->%c\n", b[1], a[j]);
                            printf("%c->%c\n", b[2], a[k]);
                    }
                }
                used[j]--;
            }
            
        }
        used[i]--;
    }
}


char a[3] = {'A', 'B', 'C'};
char b[3] = {'X', 'Y', 'Z'};
int used[3] = {0,0,0};
int ans[3];
void solution2(int n)
{
    int i;
    if(n == 3){
        if(a[ans[0]] != 'A'
                && a[ans[0]] != 'C'
                && a[ans[2]] != 'C'){
            printf("%c->%c\n", b[0], a[ans[0]]);
            printf("%c->%c\n", b[1], a[ans[1]]);
            printf("%c->%c\n", b[2], a[ans[2]]);
        }
        return;
    }else{
        for(i = 0; i < 3; i++){
            if(used[i] == 0){
                used[i]++;
                ans[n] = i;
                solution2(n+1);
                used[i]--;
            }
        }
    }
}
