/*
2)
Este teste é para você praticar o recurso fundamental do MPI: 
enviar uma mensagem. A aplicação que você deve desenvolver é composta por 
2 processos MPI, o primeiro envia uma mensagem e o segundo a recebe. 
A mensagem a enviar é apenas um inteiro com o valor 12345. 
O destinatário deve imprimir o valor recebido. Você é livre para escolher 
o valor da tag que deseja.Saída:
I am process 0, I send value 12345
I am process 1, I received value 12345
*/

#include <mpi.h>
#include <stdio.h>

int main()
{
	MPI_Init(NULL, NULL);

	int size, id;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);

	int variavel = 1;
	MPI_Status status;

	if(id == 0){
		variavel = 12345;
		MPI_Send(&variavel, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}else if(id == 1){
		printf("Processo %d, variavel = %d\n",id, variavel);

		MPI_Recv(&variavel, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

		printf("Processo %d, variavel = %d\n",id, variavel);
		printf("%d %d\n", status.MPI_SOURCE, status.MPI_TAG);
	}

	MPI_Finalize();
	return 0;
}