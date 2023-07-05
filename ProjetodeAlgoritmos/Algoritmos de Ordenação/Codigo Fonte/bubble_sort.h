#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED
#include "generate_input.h"

void bubbleSort(int* vetor, int tam){
    int i, j;

    for(i = 0; i < (tam - 1); i++){
        for(j = 0; j < (tam - i - 1); j++){
            if(vetor[j] > vetor[j + 1]){
                troca(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

#endif // BUBBLE_SORT_H_INCLUDED
