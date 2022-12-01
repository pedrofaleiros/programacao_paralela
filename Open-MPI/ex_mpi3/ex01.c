/*
1)
    a)Leia um valoor x do usuário no rank 0;
    b)Dissemine seu conteúdo para todos os processos;
    c)Em cada processo calcule y = id_processos * x recebido do rank 0;
        c.1) sincronize os processos;
    d)Sumarize os valores calculados em todos os processos,no processo 0;
*/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	MPI_Init(NULL, NULL);

	int size, id;
	int variavel;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	int x;

	if(id == 0){
		scanf("%d", &x);
	}

	int * recvbuf = malloc(sizeof(int)*size);
	int y;

	MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);

	y = id * x;

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Gather(&y, 1, MPI_INT, recvbuf, 1,
	MPI_INT, 0, MPI_COMM_WORLD);

	if(id == 0){
		printf("\n: ");
		for(int i = 0; i < size; i++){
			printf("%d ", recvbuf[i]);
		}
		printf("\n");
	}

	MPI_Finalize();
	return 0;
}