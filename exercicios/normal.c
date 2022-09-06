#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000000;

int main()
{
	int i;
	double x, pi, sum = 0.0, step;

	step = 1.0 / (double)num_steps;

	double t1, t2;

	t1 = omp_get_wtime();

	for (i = 0; i < num_steps; i++)
	{

		x = (i + 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	pi = step * sum;

	t2 = omp_get_wtime();

	printf("\nTempo: %f", t2-t1);
	printf("\nPi: %f", pi);

	printf("\n");
	return 0;
}