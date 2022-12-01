#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int primo(int x){
	int i, j, z;

	for(i = 0; i < 10000; i++){
		for(j = 0; j < 10000; j++){
			z = 1;
		}

	}
	if((x==0) || (x==1)){
		return 0;
	}

	int div;
	for(div = 2; div < x; div++){
		if(x%div == 0){
			return 0;
		}
	}
	return 1;
}

int main(int argv, char * argc[]){

	int n = atoi(argc[1]);

	int vet[n];

	double t1, t2;

	omp_set_num_threads(8);

	t1 = omp_get_wtime();

	for(int i = 0; i < n; i++){
		vet[i] = i+1;
	}

	int contagem = 0;
	#pragma omp parallel for schedule(dynamic, 4)
	for(int i = 0; i < n; i++){
		if(primo(i)){
			contagem++;
		}
	}

	t2 = omp_get_wtime();

	printf("\n%f\n", t2-t1);

	return 0;
}