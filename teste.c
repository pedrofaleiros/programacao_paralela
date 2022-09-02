#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main() {

	double pi = 0, step, t1, t2;
	int num_steps = 100000000;
	step = 1.0/(double) num_steps;
	int num_threads = 0;

	scanf("%d", &num_threads);

	omp_set_num_threads(num_threads);

	double sum;

	t1 = omp_get_wtime();
	#pragma omp parallel for reduction(+:sum)
	for(int i = 0; i < num_steps; i++){
		sum += 4.0/(1.0+((i+0.5)*step)*((i+0.5)*step));
	}
	t2 = omp_get_wtime();

	pi = sum * step;

	printf("\nTime: %lf", t2-t1);
	printf("\npi: %lf\n", pi);


	return 0;
}