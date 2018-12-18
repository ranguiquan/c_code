#include <stdio.h>
#include <stdlib.h>
//全排列
int r = 4;
char data[4] = {'a', 'b', 'c', 'd'};
int used[4] = {0,0,0,0};
char p[4];
void permute(int pos)
{
    int i = 0;
    if(pos == r)
    {
        for(i = 0; i < r; i++){
            printf("%c ", p[i]);
        }
        printf("\n");
        return;
    }
    for(i = 0; i < r; i++){
        if(!used[i]){
            used[i]++;
            p[pos] = data[i];
            permute(pos+1);
            used[i]--;
        }
    }
}
int main(void)
{
    permute(0);
    return 0;
}
