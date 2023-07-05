#ifndef QUICK_SORT_V1_H_INCLUDED
#define QUICK_SORT_V1_H_INCLUDED
#include "generate_input.h"

int partition_v1(int p, int r, int vetor[]){
    int x, i, j;

    x = vetor[r];
    i = p - 1;

    for(j = p; j < r; j++){
        if(vetor[j] <= x){
            troca(&vetor[++i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[r]);
    return i + 1;
}

void quickSort_v1(int p, int r, int vetor[]){
    int j;

    if(p < r){
        j = partition_v1(p, r, vetor);
        quickSort_v1(p, j - 1, vetor);
        quickSort_v1(j + 1, r, vetor);
    }
}

#endif // QUICK_SORT_V1_H_INCLUDED
