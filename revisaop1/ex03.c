#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main(int argv, char * argc[]){

	int n = atoi(argc[1]);

	omp_set_num_threads(n);

	#pragma omp parallel
	{
		#pragma omp single
		{
			printf("\n Iniciando o mundo paralelo -> %d",
			omp_get_thread_num());
		}

		printf("\n Eu sou a threads %d", 
		omp_get_thread_num());

		#pragma omp barrier

		#pragma omp master
		{
			printf("\nFIM");
		}
	}

	printf("\n");
	return 0;
}