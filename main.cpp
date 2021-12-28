#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"

int main()
{
	int size[3] = { 10000, 50000, 100000 };
	int N = 1;
	double t1, t2, runtime;
	srand(time(0));


	for (int i = 0; i < 3; i++)
	{
		int N = size[i];
		double* arr = (double*)malloc(N * sizeof(double));

		//random generated array
		for (int j = 0; j < N; j++)
		{
			arr[j] = (rand() % 10000);
		}
		
		//Worst case for bubble and insert
		//for (int j = N; j > 0; j--)
		//{
		//	arr[N - j] = j;
		//}

		t1 = clock();
		Bubble(arr, N);
		t2 = clock();
		runtime = (t2 - t1) / CLOCKS_PER_SEC;

		printf("Bubble sort time for% d elements : % lf sec\n", N, runtime);

		for (int j = 0; j < 20; j++)
		{
			printf("%.1lf ", arr[j]);
		}

		for (int j = 0; j < N; j++)
		{
			arr[j] = (rand() % 10000);
		}

		t1 = clock();
		Insert(arr, N);
		t2 = clock();
		runtime = (t2 - t1) / CLOCKS_PER_SEC;

		printf("\nInsertion sort time for %d elements: %lf sec\n", N, runtime);

		for (int j = 0; j < 20; j++)
		{
			printf("%.1lf ", arr[j]);
		}

		for (int j = 0; j < N; j++)
		{
			arr[j] = (rand() % 10000);
		}

		t1 = clock();
		Quick(arr, N);
		t2 = clock();
		runtime = (t2 - t1) / CLOCKS_PER_SEC;

		printf("\nQuick sort time for %d elements: %lf sec\n", N, runtime);

		for (int j = 0; j < 20; j++)
		{
			printf("%.1lf ", arr[j]);
		}

		printf("\n \n");
		free(arr);
	}
}