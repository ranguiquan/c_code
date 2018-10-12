/*程序描述：清橙a1101
 * 作者：冉桂全*/
#include <stdio.h>
int abs(int a)
{
    if(a < 0){
        return -a;
    }else{
        return a;
    }
}
int main(void)
{
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++){
        printf("(%d,%d)", a, i+1);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("(%d,%d)", i+1, b);
    }
    printf("\n");
    
    if(a < b){
        for(int i = 0; i < n - abs(a - b); i++){
            printf("(%d,%d)", i+1, i+1+b-a);
        }
        printf("\n");
    }else{
        for(int i = 0; i < n - abs(a - b); i++){
            printf("(%d,%d)", i+1+a-b, i+1);
        }
        printf("\n");
    }
    
    if(a+b < n+1){
        for(int i = 0; i < n - abs(n+1 - a - b); i++){
            printf("(%d,%d)",i+1, a+b - i - 1 );
        }
        printf("\n");
    }else{
        for(int i = 0; i < n - abs(n+1 - a - b); i++){
            printf("(%d,%d)",a+b - i - 1, i+1 );
        }
        printf("\n");

    }
    return 0;
}
