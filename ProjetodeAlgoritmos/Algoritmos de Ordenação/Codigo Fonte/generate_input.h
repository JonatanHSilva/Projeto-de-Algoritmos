#ifndef GENERATE_INPUT_H_INCLUDED
#define GENERATE_INPUT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void troca(int* primeiro, int* segundo){
    int temporario;

    temporario = *primeiro;
    *primeiro = *segundo;
    *segundo = temporario;
}

void numeros_crescente(int* vetor, int tam){
	int x, y = 1;
	for(x = 0; x < tam; x++){
        vetor[x] = y;
        printf("\rO valor atual e: %d", y);
        y++;
    }
    printf("\n");
}

void numeros_decrescente(int* vetor, int tam){
	int x, y = tam;
	for(x = 0; x < tam; x++){
        vetor[x] = y;
        y--;
        printf("\rO valor atual e: %d", vetor[x]);
    }
    printf("\nInstancia gerada com sucesso!!!\n");
    sleep(2);
}

void numeros_aleatorios(int* vetor, int tam){
	int x, vetorTemp, indiceTemp;
	srand(time(NULL));
	numeros_crescente(vetor, tam);
	for(x = 0; x < tam; x++){
        vetorTemp = vetor[x];
        if(tam > 32767){
            indiceTemp = (rand() * rand()) % tam;
        }
        else{
            indiceTemp = rand() % tam;
        }


        vetor[x] = vetor[indiceTemp];
        printf("\rO valor atual e: %d", vetor[x]);
        vetor[indiceTemp] = vetorTemp;
	}
	printf("\nInstancia gerada com sucesso!!!\n");
    sleep(2);
}


#endif // GENERATE_INPUT_H_INCLUDED
