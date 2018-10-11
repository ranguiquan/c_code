#include<stdio.h>
#include<stdlib.h>
void solution(int a)
{
    if(a >= 90){
                printf("A\n");
                    
    }else if(a >= 80){
                printf("B\n");
                    
    }else if(a >= 70){
                printf("C\n");
                    
    }else if(a >= 60){
                printf("D\n");
                    
    }else{
                printf("E\n");
                    
    }
        return;

}
int main(void)
{
        int grade;
            scanf("%d", &grade);
                solution(grade);
                    return 0;

}
