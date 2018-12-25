#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 100

int main(void)
{
    char end_option[BUF];
    strcpy(end_option, "END");
    char add = '-';
    char minus = '+';
    char stations[BUF];
    char option[BUF];
    int total_tickets = 0;
    int station_count = 0;
    int i = 0;
    int j;
    scanf("%s", stations);
    scanf("%d", &total_tickets);
    while(stations[i++] != '\0'){
        station_count++;
    }
    int** matrix = (int**)malloc(sizeof(int*) * station_count);
    for(i = 0; i < station_count; i++){
        *(matrix + i) = (int*)calloc(station_count, sizeof(int) * station_count);
    }
    for(i = 0; i < station_count-1; i++){
        for(j = i+1; j < station_count; j++){
            matrix[i][j] =total_tickets;
        }
    }

    while(1){
        scanf("%s", option);
        if(strcmp(option, end_option) == 0){
            break;
        }
        int begin, end;
        for(i = 0; i < station_count; i++){
            if(option[1] == stations[i]){
                begin = i;
            }
            if(option[2] == stations[i]){
                end = i;
            }
        }
        if(option[0] == add){//tickets add
            for(i = 0; i <= begin -1; i++){
                for(j = i+1; j <= begin; j++){
                    matrix[i][j]--;
                }
            }
            for(i = end; i < station_count-1; i++){
                for(j = i+1; j < station_count; j++ ){
                    matrix[i][j]--;
                }
            }
            for(i = 0; i < station_count-1; i++){
                for(j = i+1; j < station_count; j++){
                    matrix[i][j]++;
                }
            }
        }else{//tickets minus
            for(i = 0; i <= begin -1; i++){
                for(j = i+1; j <= begin; j++){
                    matrix[i][j]++;
                }
            }
            for(i = end; i < station_count-1; i++){
                for(j = i+1; j < station_count; j++ ){
                    matrix[i][j]++;
                }
            }
            for(i = 0; i < station_count-1; i++){
                for(j = i+1; j < station_count; j++){
                    matrix[i][j]--;
                }
            }
        }
    }
    printf("%d\n", matrix[0][station_count-1]);
    return 0;
}
