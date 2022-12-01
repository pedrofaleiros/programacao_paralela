#include <mpi.h>
#include <stdio.h>

int main()
{
	MPI_Init(NULL, NULL);

	int id, size;

	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	printf("meu id: %d\n", id);

	MPI_Finalize();
	return 0;
}