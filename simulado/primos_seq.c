#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int primo(int x)
{
	int i, j, z;

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

	t1 = omp_get_wtime();

	for(i = 0; i < n; i++){
		vet[i] = i+1;
	}

	int cont = 0;
	for(i = 0; i < n; i++){
		if(primo(vet[i])){
			cont++;
		}
	}

	t2 = omp_get_wtime();

	printf("\nCont:  %d", cont);
	printf("\nTempo: %.4f segundos\n", t2-t1);

	return 0;
}