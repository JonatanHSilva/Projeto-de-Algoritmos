#ifndef QUICK_SORT_V3_H_INCLUDED
#define QUICK_SORT_V3_H_INCLUDED
#include "generate_input.h"

int partition_v3(int p, int r, int vetor[]){
    int x, m, i, j, mediana;

    m = (p + r) / 2;
    mediana = 0;

    if(vetor[p] < vetor[m]){
        if(vetor[m] < vetor[r]){
            mediana = m;
        }
        else{
            if(vetor[p] < vetor[r]){
                mediana = r;
            }
            else{
                mediana = p;
            }
        }
        //troca(&vetor[m], &vetor[p]);
    }
    else{
        if(vetor[r] < vetor[m]){
            mediana = m;
        }
        else{
            if(vetor[r] < vetor[p]){
                mediana = r;
            }
            else{
                mediana = p;
            }
        }
    }

    troca(&vetor[r], &vetor[m]);

    x = vetor[r];
    i = p - 1;

    for(j = p; j <= r - 1; j++){
        if(vetor[j] <= x){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }

    troca(&vetor[i + 1], &vetor[r]);
    return i + 1;
}

void quickSort_v3(int p, int r, int vetor[]){
    int j;

    if(p < r){
        j = partition_v3(p, r, vetor);
        quickSort_v3(p, j - 1, vetor);
        quickSort_v3(j + 1, r, vetor);
    }
}

#endif // QUICK_SORT_V3_H_INCLUDED
