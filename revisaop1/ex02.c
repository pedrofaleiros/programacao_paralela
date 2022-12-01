#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int primo(int x){
	if((x==0) || (x==1)) return 0;

	for(int i = 2; i < x; i++)
		if(x%i == 0)
			return 0;
	return 1;
}

int main(){

	omp_set_num_threads(3);

	#pragma omp parallel
	{

		int id = omp_get_thread_num();
		printf("\n Meu ID é: %d ", id);

		#pragma omp sections
		{
			#pragma omp section
			{
				printf("\n Pares -> %d\n", omp_get_thread_num());
				for(int i = 2; i <= 10; i+=2){
					printf("%d ", i);
					for(int j = 0; j < 10000; j++) j+=0;

				}
			}

			#pragma omp section
			{
				printf("\n Impares -> %d\n", omp_get_thread_num());
				for(int i = 1; i <= 10; i+=2){
					printf("%d ", i);
					for(int j = 0; j < 10000; j++) j+=0;
				}
			}

			#pragma omp section
			{
				printf("\n Primos -> %d\n", omp_get_thread_num());
				for(int i = 1; i <= 10; i++){
					if(primo(i)){
						printf("%d ", i);
					}
					for(int j = 0; j < 10000; j++) j+=0;

				}
			}
		}
	}


	printf("\n");
	return 0;
}