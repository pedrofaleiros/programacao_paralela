#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000000;

int main()
{
	double pi, step;

	step = 1.0 / (double)num_steps;

	double t1, t2;

	int num_th = 1;
	scanf("%d", &num_th);

	pi = 0;
	omp_set_num_threads(num_th);

	t1 = omp_get_wtime();

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		int num = omp_get_num_threads();
		int i;
		double x, sum;

		for (i = id, sum = 0.0; i < num_steps; i += num)
		{
			x = (i + 0.5) * step;
			sum += 4.0 / (1.0 + x * x);
		}

		#pragma omp critical
			pi += step * sum;
	}

	t2 = omp_get_wtime();

	printf("\nTempo: %f", t2 - t1);
	printf("\nPi: %f", pi);

	printf("\n");
	return 0;
}