#include "alloc.h"
#include <stdio.h>

int main(){
	//Ponteiros que apontam para o endere‡o do bloco 
	void *endBlock1;
	void *endBlock2;
	void *endBlock3;

        unsigned totalMemory = 0;

        //O comando coreleft retorna a memoria total disponivel
	unsigned initialTotalMemory = coreleft();

	printf("\n---------------------------\n");
	printf("Total memory available: %u bytes \n", initialTotalMemory);

        //O comando malloc aloca um determinado espaco na memoria
	endBlock1 = malloc(initialTotalMemory*0.25);
	totalMemory = coreleft();
	printf("Total memory available: %u bytes \n", totalMemory);

	endBlock2 = malloc(initialTotalMemory*0.25);
	totalMemory = coreleft();
	printf("Total memory available: %u bytes \n", totalMemory);

        //O comando free libera o endereco de memoria que estava alocado
	free(endBlock1);

	endBlock3 = malloc(initialTotalMemory*0.60);

	if(endBlock3 == NULL){
		printf("No memory available ! \n");
        }else{
		printf("Block3 are allocated ! \n");
	}

	endBlock1 = malloc(initialTotalMemory*0.25);

	free(endBlock2);

	endBlock3 = malloc(initialTotalMemory*0.60);

	if(endBlock3 == NULL){
		printf("No memory available ! \n");
	}else{
		printf("Block3 are allocated ! \n");
	}

	return 0;
}