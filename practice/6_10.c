#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF 81
int main(void)
{
    char data[3][BUF];
    int i, j, k;
    int capital, lower, num, space, other;
    for(i = 0; i < 3; i++){
        gets(data[i]);
        j = 0;
        capital = lower = num = space = other = 0;
        while(data[i][j] != '\0'){
            if(data[i][j] >= 'A' && data[i][j] <= 'Z'){
                capital++;
            }else if(data[i][j] >= 'a' && data[i][j] <= 'z'){
                lower++;
            }else if(data[i][j] >= '0' && data[i][j] <= '9'){
                num++;
            }else if(data[i][j] == ' '){
                space++;
            }else{
                other++;
            }
            j++;
        }
        printf("line %d:capital %d, lower %d, num %d, space %d, other %d\n", i+1, capital, lower, num, space, other);
    }

}
