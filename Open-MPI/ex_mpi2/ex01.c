/*
1)
Faça um programa em MPI que gere a seguinte saída:
"Hello World!" from MPI process 0. We are 4 MPI processes.
"Hello World!" from MPI process 1. We are 4 MPI processes.
"Hello World!" from MPI process 2. We are 4 MPI processes.
"Hello World!" from MPI process 3. We are 4 MPI processes.
*/

#include <mpi.h>
#include <stdio.h>

int main()
{
	MPI_Init(NULL, NULL);

	int size, id;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	printf("\"Hello World!\" from MPI process %d. We are %d MPI processes.\n", id, size);

	MPI_Finalize();
	return 0;
}