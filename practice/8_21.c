#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define BUF 20
int cmp_int(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int cmp_string(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b);
}

int main(int argc, char* argv[])
{
    switch(*(argv[1]+1)){
        case 'd':{
            int tmp[argc-2];
            int i, j;
            for(i = 0; i < argc-2; i++){
                j = 0;
                tmp[i] = 0;
                while(isdigit(*(argv[i+2] + j))){
                    tmp[i] = 10*tmp[i] + *(argv[i+2] + j) - '0';
                    j++;
                }
            }
            qsort((void*)tmp, argc-2, sizeof(int), cmp_int);
            for(i = 0; i < argc-2; i++){
                printf("%d ", tmp[i]);
            }
            printf("\n");
            break;
        }
        case 's':{
            char tmp_string[argc-2][BUF];
            int i;
            for(i = 0; i < argc-2; i++){
                strcpy(tmp_string[i], argv[i+2]);
            }
            qsort((void*)tmp_string, argc-2, sizeof(tmp_string[0]), cmp_string);
            for(i = 0; i < argc-2; i++){
                printf("%s\n", tmp_string[i]);
            }
            break;
        }
    }
}
