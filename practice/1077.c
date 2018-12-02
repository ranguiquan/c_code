#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define BUF 100
int replace(char a[], char b[], char c[]);
void insert(char *s1, char *s2, int n);

int main(void)
{
    char a[BUF], b[BUF], c[BUF];
    int i = 0;
    while((a[i++] = getchar()) != '\n');
    a[i-1] = '\0';
    scanf("%s", b);
    scanf("%s", c);
    printf("%d\n", replace(a, b, c));
    printf("%s", a);
    return 0;
}

int replace(char a[], char b[], char c[])
{
    int i, j, k;
    i = 0, j = 0;
    int count = 0;
    while(a[i] != '\0'){
        j = 0;
        while(b[j] != '\0'){
            if(a[i+j] != b[j]) break;
            j++;
        }
        if(b[j] == '\0'){
            count++;
            k = i;
            while(a[k+j] != '\0'){
                a[k] = a[k + j];
                k++;
            }
            a[k] = a[k+j];
            insert(a, c, i);
        }
        i++;
    }
    return count;
}

void insert(char *s1, char *s2, int n)
{
	int len1 = 0, len2 = 0, j = 0, len3, k = 0;
	char s4[30];
	char *s3 = s4;
	if (s1 == NULL)
		return;
	if (s2 == NULL)
		return;
	len1 = strlen(s1);
	len2 = strlen(s2);
	if(n>len1)
		return;
	for (int i = 0; i<n; i++){ 
		j++; 
	}
	for (int i = 0; i<len1; i++){ 
		s4[k++] = s1[i];
	}
	for (int i = 0; i<len2; i++){
		s1[j++] = s2[i];
    }
	for(int i=n;i<len1;i++){
		s1[j++]=s4[i];
    }
	s1[j] = '\0';
}

