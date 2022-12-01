#include <mpi.h>
#include <stdio.h>

int main()
{
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int sendbuf[7]    = {1, 2, 3, 4, 5, 6, 7};
	int sendcounts[4] = {2, 1, 3, 1};
	int displs[4]     = {5, 4, 1, 0};
	int recvbuf[7];
	int recvcount;

	MPI_Scatterv(&sendbuf, sendcounts, displs, MPI_INT, 
	&recvbuf, 7, MPI_INT, 0, MPI_COMM_WORLD);

	printf("%d: ", rank);
	for(int i = 0; i < sendcounts[rank]; i++){
		printf("%d ", recvbuf[i]);
	}

	MPI_Finalize();
	printf("\n");
	return 0;
}