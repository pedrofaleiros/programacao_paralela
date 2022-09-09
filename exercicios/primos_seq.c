#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include <string.h>

// Mostre quais, quantos e o somatório de todos números primos entre 
// 100 e 1000000000

//const int NUM_THREADS = 8;
//const int MAX = 1000000000;
const long long int MAX = 100000;
const long long int MIN = 100;

int isPrimo(long long int num){
	
	if(num == 1) return 0;
	long long int cont = 0;
	for(long long int i = 1; i < num; i++){
		if(num % i == 0){
			cont++;
		}
	}
	return cont == 1;
}

int main(){

	double t1, t2;

	long long int soma = 0, cont = 0, i;

	t1 = omp_get_wtime();

	for(i =  MIN; i <= MAX; i++){
		if(isPrimo(i)){
			printf("%lld ", i);
			cont++;
			soma += i;
		}
	}

	t2 = omp_get_wtime();

	printf("\n Contagem : %lld", cont);
	printf("\n Somatorio: %lld", soma);
	printf("\n Tempo    : %f", t2-t1);

	printf("\n");
	return 0;
}