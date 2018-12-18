#include <stdio.h>
#define BUF 10000
char space[BUF];
char* loc = space;

void* new(int n)
{
    if(loc-space + n <= BUF){
        loc += n;
        return loc-n;
    }else{
        return 0;
    }
}

void free(char *p){
    if(p >= space && p < space+BUF){
        loc = p;
    }
}
