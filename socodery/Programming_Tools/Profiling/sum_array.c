#include <stdio.h>
#include <stdlib.h>
#define N 1000

void create_arr(int arr[][N]);
void find_sum_row_wise(int arr[][N]);
void find_sum_col_wise(int arr[][N]);

int main()
{
    int arr[N][N];
	create_arr(arr);
    find_sum_row_wise(arr);
    find_sum_col_wise(arr);
}
void create_arr(int arr[][N])
{
    int i,j;
	for (i=0; i < N ; i++)
	{
	   for (j=0; j < N; j++)
	   {
		  arr[i][j]=rand();
	   }
	}
}
void find_sum_row_wise(int arr[][N])
{
    int sum=0;
    int i,j;
	for (i=0; i < N ; i++)
	{
	   for (j=0; j < N; j++)
	   {
		  sum += arr[i][j];
	   }
	}
}

void find_sum_col_wise(int arr[][N])
{
    int sum=0;
    int i,j;
	for (i=0; i < N ; i++)
	{
	   for (j=0; j < N; j++)
	   {
		  sum += arr[j][i];
	   }
	}
}
