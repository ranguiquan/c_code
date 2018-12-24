#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUF 10

typedef struct p{
    char* name;
    int count;
}candidate;

char* GenerateStr(int seed)
{
    char* str = (char*)calloc(sizeof(char), sizeof(char) * (BUF+1));
    int i;
    srand(seed+time(NULL));
    int length = 4 + rand()%6;
    str[0] = rand()%26 + 'A';
    for(i = 1; i < length; i ++)
    {
		str[i] = rand()%26 + 'a';
    }
    str[i] = '\0';

    return str;
}

candidate* GenerateSample(int c)
{
    int i;
    candidate* sample = (candidate*)malloc(sizeof(candidate) * c);
    for(i = 0; i < c; i ++){
        (sample+ i)->name = GenerateStr(i);
        (sample+ i)->count = 0;
    }
    return sample;
}

char** GenerateVote(candidate* sample, int c, int v)
{
    char** votes = (char**)malloc(sizeof(char*) * v);
    
    int i;
    for(i = 0; i < v; i++){
        *(votes + i) = (char*)malloc(sizeof(char) * BUF);
        strcpy(*(votes+i), (sample + rand()%c)->name);
    }
    return votes;
}

void swap(candidate* a, candidate* b)
{
    candidate tmp = *a;
    *a = *b;
    *b = tmp;
}

void SortCandidates(candidate* sample, int c)
{
    int i, j;
    for(i = 0; i < c-1; i++){
        for(j = i+1; j < c; j++){
            if(strcmp((sample+i)->name, (sample+j)->name) > 0){
                swap(sample+i, sample+j);
            }
        }
    }
}


void CountVote(candidate* sample, int c, char** votes, int v)
{
    SortCandidates(sample, c);
    int left, right, mid;
    int i, j;
    for(i = 0; i < v; i++){
        left = 0, right = c-1;
        while(left <= right){
            mid = (left+right)/2;
            if(strcmp((sample+mid)->name, *(votes+i)) == 0){
                (sample+mid)->count++;
                break;
            }else if(strcmp((sample+mid)->name, *(votes+i)) > 0){
                right = mid-1;
            }else if(strcmp((sample+mid)->name, *(votes+i)) < 0){
                left = mid+1;
            }
        }
    }
}

void SortByCount(candidate* sample, int c)
{
    int i, j;
    for(i = 0; i < c-1; i++){
        for(j = i+1; j < c; j++){
            if((sample+i)->count < (sample+j)->count){
                swap(sample+i, sample+j);
            }
        }
    }
}

int main(void)
{
    int c, v, w;
    int i, j;

    scanf("%d %d %d", &c, &v, &w);

    candidate* sample = GenerateSample(c);
    char** votes = GenerateVote(sample, c, v);
    CountVote(sample, c, votes, v);
    SortByCount(sample, c);
    printf("**********************************\n");
    printf("count\tname\n");
    printf("**********************************\n");
    for(i = 0; i < w; i++){
        printf("%d\t%s\n", (sample+i)->count, (sample+i)->name);
    }
    


    for(i = 0; i < c; i++){
        free((sample+i)->name);
    }
    free(sample);
    for(i = 9; i < v; i++){
        free(*(votes+i));
    }
    free(votes);
    return 0;
}
