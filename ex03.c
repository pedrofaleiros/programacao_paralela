#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

static long num_steps = 100000;
double step;

int main (int argc, char * argv[])
{ 
    int i; double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    double t1, t2;
	t1 = omp_get_wtime();

    omp_set_num_threads(atoi(argv[1]));

    #pragma omp parallel for reduction(+:sum)
    for (i=0;i< num_steps; i++){
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }

    t2 = omp_get_wtime();

    pi = step * sum;

    printf("\nTime: %lf", t2-t1);
	printf("\npi: %lf\n", pi);

}