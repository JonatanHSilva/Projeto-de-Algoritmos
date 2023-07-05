#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

void merge(int p, int q, int r, int vetor[]){
    int i, j, k, *w;

    w = malloc((r - p) * sizeof(int));
    if(w == NULL){
        printf("Não foi possivel alocar\n");
        system("pause");
    }
    i = p;
    j = q;
    k = 0;

    while(i < q && j < r){
        if(vetor[i] <= vetor[j]){
            w[k++] = vetor[i++];
        }
        else{
            w[k++] = vetor[j++];
        }
    }

    while(i < q){
        w[k++] = vetor[i++];
    }

    while(j < r){
        w[k++] = vetor[j++];
    }

    for(i = p; i < r; i++){
        vetor[i] = w[i - p];
    }

    free(w);
}

void mergeSort(int p, int r, int vetor[]){
    int q;

    if(p < r - 1){
        q = (p + r) / 2;
        mergeSort(p, q, vetor);
        mergeSort(q, r, vetor);
        merge(p, q, r, vetor);
    }
}

#endif // MERGE_SORT_H_INCLUDED
