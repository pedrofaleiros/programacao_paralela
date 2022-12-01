#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size, id;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	int root = 1;

	int cont = 3;

	int * variavel = malloc(sizeof(int)*cont);
	for(int i = 0; i < cont; i++){
		variavel[i] = -1;
	}


	if(id == root){
		for(int i = 0; i < cont; i++){
			variavel[i] = i+1;
		}
		printf("I am process %d and I broadcast\n", id);
	}

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Bcast(variavel, 5, MPI_INT, root, MPI_COMM_WORLD);

	if(id != root){
		printf("I am process %d and I received value ", id);
		for(int i = 0; i < cont; i++){
			printf("%d", variavel[i]);
		}

		printf(" via broadcast\n");

	}
	MPI_Finalize();
	return 0;
}