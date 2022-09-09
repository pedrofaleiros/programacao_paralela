#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>

// Mostre quais, quantos e o somatório de todos números primos entre 
// 100 e 1000000000


const long long int MAX = 100000;
const long long int MIN = 100;

int isPrimo(long long int num){
	
	if(num == 1) return 0;
	long long int cont = 0;

	#pragma omp parallel for num_threads(8) reduction(+:cont)
	for(long long int i = 1; i < num; i++){
		if(num % i == 0){
			cont++;
		}
	}
	return cont == 1;
}

int main(){

	double t1, t2;

	long long int soma = 0, cont = 0;
	
	t1 = omp_get_wtime();

	const int NUM_THREADS = 8;

	omp_set_num_threads(NUM_THREADS);

	#pragma omp parallel //reduction(+:soma) reduction(+:cont)
	{
		long long int c = 0, s = 0;
		#pragma omp for schedule(dynamic,1)
		for(long long int i =  MIN; i <= MAX; i++){
			if(isPrimo(i)){
				printf("%lld ", i);
				c++;
				s += i;
			}
		}

		#pragma omp critical
		soma += s;
		cont += c;
	}

	t2 = omp_get_wtime();

	printf("\n Contagem : %lld", cont);
	printf("\n Somatorio: %lld", soma);
	printf("\n Tempo    : %f", t2-t1);

	printf("\n");
	return 0;
}