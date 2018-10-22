#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int k, n, i, j;
    char characters[26];
    scanf("%d", &k);
    scanf("%d", &n);
    char* out = (char*)malloc(sizeof(char) * n * 2000);
    i = 0;
    for(i = 0; i < 26; i++){
        *(characters + ((i+'A'+k)%26)) = 'A' + i;
    }
    int reader;
    int tmp = 0;
    getchar();
    for(i = 0; i < n; i++){
        while((reader = getchar()) != '\n'){
            if(reader == '0') reader = 1;
            else reader = 0;
            tmp += reader * round(pow(2, 4));
            for(j = 4; j > 0; j--){
                reader = getchar();
                if(reader== '0') reader= 1;
                else reader= 0;
                tmp += reader * round(pow(2, j-1));
            }
            if(0<=tmp && 26>=tmp){
                out[strlen(out)] = *(characters + tmp);
                out[strlen(out)+1] = '\0';
            }else{
                out[strlen(out)] = ' ';
                out[strlen(out) + 1] = '\0';
            }
            tmp = 0;
        }
        out[strlen(out)] = '\n';
        out[strlen(out) + 1] = '\0';
    }
    printf("%s", out);
    return 0;
    
}

