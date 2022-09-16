#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void pesa();

int main(){

	omp_set_num_threads(3);

	#pragma omp parallel
	{
		int id = omp_get_thread_num();
		printf("\nMeu ID: %d\n", id);

		#pragma omp sections
		{
			#pragma omp section
			{
				printf("\npares ID: %d -> ", id);
				for(int i = 2; i <= 10; i+=2){
					printf("%d ", i);
				}
				void pesa();
			}		
			
			#pragma omp section
			{
				printf("\nimpares ID: %d -> ", id);
				for(int i = 1; i <= 10; i+=2){
					printf("%d ", i);
				}
				void pesa();
			}		

			#pragma omp section
			{
				printf("\nprimos ID: %d -> ", id);
				printf("2 ");
				printf("3 ");
				printf("5 ");
				printf("7 ");
				void pesa();
			}		
		}
	}

	printf("\n");
	return 0;
}

void pesa(){
	int i, j, x;
	for(i = 0; i < 1000000; i++){
		for(j = 0; j < 1000000; j++){
			x = 0;
		}
	}
}