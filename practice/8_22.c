#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE	10
#define	STRING_LEN	20

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
void sort_intarr()
{
	int arr[TEST_SIZE], i;
	srand(1);
	printf("sort_intarr before:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%d%c",arr[i] = rand(), i == TEST_SIZE - 1?'\n':' ');
	qsort(arr, TEST_SIZE, sizeof(int), compare_int);
	printf("sort_intarr after:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%d%c", arr[i], i == TEST_SIZE - 1 ? '\n' : ' ');
}
int compare_float(const void *a, const void *b)
{
    return *(float*)a - *(float*)b;
}

void sort_floatarr()
{
	float arr[TEST_SIZE];
	int i;

	srand(2);
	printf("sort_floatarr before:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%f%c", arr[i] = rand() / 100.0, i == TEST_SIZE - 1 ? '\n' : ' ');
	qsort(arr, TEST_SIZE, sizeof(float), compare_float);
	printf("sort_floatarr after:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%f%c", arr[i], i == TEST_SIZE - 1 ? '\n' : ' ');

}
char rand_char()
{
	char	arr[2] = { 'A', 'a' };

	return arr[rand() % 2] + rand() % 26;
}

int compare_char(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}
void sort_chararr()
{
	char arr[TEST_SIZE]; 
	int	i;

	srand(3);
	printf("sort_chararr before:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%c%c", arr[i] = rand_char(), i == TEST_SIZE - 1 ? '\n' : ' ');
    qsort(arr, TEST_SIZE, sizeof(char), compare_char);
	printf("sort_chararr after:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%c%c", arr[i], i == TEST_SIZE - 1 ? '\n' : ' ');

}

int compare_string(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}
void sort_stringarr()
{
	char	stringarr[TEST_SIZE][STRING_LEN];
	int i, j;

	srand(4);
	printf("sort_stringarr before:\n");
	for (i = 0; i < TEST_SIZE; i++)
	{
		int rand_len = 3 + rand() % (STRING_LEN - 2);
		for (j = 0; j < rand_len - 1; j++)
			stringarr[i][j] = rand_char();
		stringarr[i][rand_len - 1] = '\0';
		printf("%s\n", stringarr[i]);
		qsort((void *)stringarr[i], rand_len-1 , sizeof(char), compare_char);
	}
	qsort((void*)stringarr, TEST_SIZE, sizeof(stringarr[0]), compare_string);

	printf("sort_stringarr after:\n");
	for (i = 0; i < TEST_SIZE; i++)
		printf("%s\n", stringarr[i]);


}
int main(void)
{
	void sort_intarr();
	void sort_floatarr();
	void sort_chararr();
	void sort_stringarr();

	sort_intarr();
	sort_floatarr();
	sort_chararr();
	sort_stringarr();
	return 0;
}
