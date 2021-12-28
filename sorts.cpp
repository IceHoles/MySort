#include <stdlib.h>
#include "sorts.h"

void swap(double *a, double *b)
{
	double temp = *a;
	*a = *b;
	*b = temp;
}

double Bubble(double* arr, int N) 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	return *arr;
}


double Insert(double* arr, int N)
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			swap(&arr[j - 1], &arr[j]);
		}
	}
	return *arr;
}


double Quick(double* arr, int N)
{
	int i = 0;
	int j = N - 1;
	int m = arr[N / 2];

	do 
	{
		while (arr[i] < m) i++;
		while (arr[j] > m) j--;

		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++; 
			j--;
		}
	}
	while (i <= j);
	if (j > 0) Quick(arr, j);
	if (N > i) Quick(&arr[i], N - i);
	return *arr;
}