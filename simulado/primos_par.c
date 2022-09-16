#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int primo(int x)
{
	int i, j, z;

	//#pragma omp parallel for collapse(2)
	for(i = 0; i < 10000; i++){
		for(j = 0; j<10000; j++){
			z = 1;
		}
	}

	if((x==0) || (x==1))
		return 0;

	int div;
	for(div = 2; div < x; div++){
		if(x % div == 0){
			return 0;
		}
	}
	return 1;
}

int main(){

	int n, i;

	printf("N: ");
	scanf("%d", &n);

	int * vet = malloc(sizeof(int)*n);

	double t1, t2;

	int num_th = 4;

	t1 = omp_get_wtime();

	omp_set_num_threads(num_th);

	#pragma omp parallel
	{
		if(omp_get_thread_num() == 0){
			num_th = omp_get_num_threads();
		}
		#pragma omp for
		for(i = 0; i < n; i++){
			vet[i] = i+1;
		}
	}

	int cont = 0;
	#pragma omp parallel for reduction(+:cont)
	for(i = 0; i < n; i++){
		if(primo(vet[i])){
			cont++;
		}
	}

	t2 = omp_get_wtime();

	printf("\nThreads: %d", num_th);
	printf("\nCont:  %d", cont);
	printf("\nTempo: %.4f segundos\n", t2-t1);

	return 0;
}