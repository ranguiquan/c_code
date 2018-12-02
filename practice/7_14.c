#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void aver_stu(int t[][5]);               
void aver_course(int t[][5]);            
void high(int t[][5]);                   
void vari(int t[][5]);                   
int main()
{
    int stu[10][5];
    int i, j;
    for (i=0; i<10; i++)
        for (j=0; j<5; j++)
            scanf("%d", &stu[i][j]);    
    aver_stu(stu);                      
    aver_course(stu);                   
    high(stu);                          
    vari(stu);                          
    return 0;
}
void aver_stu(int t[][5])
{
    int i, j;
    float k, ave;
    for (i=0; i<10; i++){
        for (j=0, k=0.0; j<5; j++)
            k+=t[i][j];
        ave=k/5;
        printf("No.%d student average is %f\n", i+1, ave);
    }
}
void aver_course(int t[][5])
{
    int i, j;
    float k, ave;
    for (j=0; j<5; j++){
        for (i=0, k=0.0; i<10; i++)
            k+=t[i][j];
        ave=k/10;
        printf("No.%d course average is %f\n", j+1, ave);
    }
}
void high(int t[][5])
{
    int i, j, h, stu, cour;
    for (i=0, h=0, stu=0, cour=0; i<10; i++){
        for (j=0; j<5; j++)
            if (t[i][j]>h){
                h=t[i][j];
                stu=i+1;
                cour=j+1;
            }
    }
    printf("The highest score is %d, from No.%d student & No.%d course\n", h, stu, cour);
}
void vari(int t[][5])
{
    int i, j, k, m;
    float temp[10], var, x1, x2;
    for (i=0, m=0; i<10; i++, m++){
        for (j=0, k=0; j<5; j++)
            k+=t[i][j];
        temp[m]=k/5;
    }
    for (i=m=x1=x2=0; i<10; i++){
        x1+=pow(temp[i], 2);
        x2+=temp[i];
    }
    var=x1/10-pow(x2/10, 2);
    printf("The variance is %f\n", var);
}
