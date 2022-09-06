#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000000;

int main()
{
	int i;
	double pi, step;

	step = 1.0 / (double)num_steps;

	double t1, t2;

	int num_th;

	scanf("%d", &num_th);
	omp_set_num_threads(num_th);

	double sum = 0.0;

	t1 = omp_get_wtime();

	#pragma omp parallel
	{
		double x;
		#pragma omp for reduction(+:sum)
		for (i = 0; i < num_steps; i++)
		{
			x = (i + 0.5) * step;
			sum = sum + 4.0 / (1.0 + x * x);
		}
	}

	t2 = omp_get_wtime();

	pi = step * sum;

	printf("\nTempo: %f", t2-t1);
	printf("\nPi: %f", pi);

	printf("\n");
	return 0;
}