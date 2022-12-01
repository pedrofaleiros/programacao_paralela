#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

/* 
Construa um programa similar que receba N valores 
do usuário e distribua de forma igualitária entre 
os ranks todos os N valores. A quantidade de threads 
também deve ser dinâmica conforme a quantidade de 
processos informado no -np.
 */

int main(int argc, char * argv[])
{
    int size, rank;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int N, i;

	if(argc > 1){
		N = atoi(argv[1]);
	}else{
		N = 10;
	}

	int * sendbuf = malloc(sizeof(int)*N);
	for(i = 0; i < N; i++){
		sendbuf[i] = i+1;
	}

	int * sendcounts = malloc(sizeof(int)*size);
	for(i = 0; i < size; i++){
		sendcounts[i] = 0;
	}
	for(i = 0; i < N; i++){
		int aux = i % size;
		sendcounts[aux]++;
	}

	int * displs = malloc(sizeof(int)*size);
	for(i = 0; i < size; i++){
		displs[i] = 0;
	}

	for(i = 1; i < size; i++){
		displs[i] = displs[i-1] + sendcounts[i-1];
	}

	int recvbuf[N];
	int recvcount;

	recvcount = sendcounts[rank];

	MPI_Scatterv(sendbuf, sendcounts, displs,
	MPI_INT, &recvbuf, recvcount, MPI_INT, 0,
	MPI_COMM_WORLD 
	);

	printf("[%d]: ", rank);
	for(i = 0; i < recvcount; i++){
		printf("%d ", recvbuf[i]);
	}

	printf("\n");

	MPI_Finalize();
	return 0;
}

	/* if(rank == 0){

		if(rank == 0){
			printf("\nsendcounts: ");
			for(i = 0; i < size; i++){
				printf("%d ", sendcounts[i]);
			}

			printf("\ndispls: ");
			for(i = 0; i < size; i++){
				printf("%d ", displs[i]);
			}

			printf("\n");
		}
	} */