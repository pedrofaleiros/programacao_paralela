/*
4)
Um coletivo clássico: a redução. Este exercício consiste em escrever 
uma aplicação onde cada processo declara uma variável contendo um 
valor igual ao seu MPI rank vezes 100. Em seguida, todos os processos 
participam de uma operação coletiva calculando a soma de todas essas 
variáveis ​​e armazenando a soma em uma variável mantida no MPI processo 0, 
que o imprime.
Saída:
Value held by MPI process 0: 0.
Value held by MPI process 1: 100.
Value held by MPI process 3: 300.
Value held by MPI process 4: 400.
Value held by MPI process 2: 200.
Total sum reduced at MPI process 0: 1000.
*/

#include <mpi.h>
#include <stdio.h>

int main()
{
	MPI_Init(NULL, NULL);

	int size, id;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	int variavel = 100;
	int soma_total = 0;
	int root = 0;

	variavel = 100 * id;

	printf("Value held by MPI process %d: %d.\n", id, variavel);

	MPI_Reduce(&variavel, &soma_total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	if(id == root){
		printf("Total sum reduced at MPI process %d: %d.\n", root, soma_total);
	}

	MPI_Finalize();
	return 0;
}