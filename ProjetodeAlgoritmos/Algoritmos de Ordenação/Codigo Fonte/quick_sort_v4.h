#ifndef QUICK_SORT_V4_H_INCLUDED
#define QUICK_SORT_V4_H_INCLUDED
#include <stdlib.h>
#include "generate_input.h"

int partition_v4(int p, int r, int vetor[]){
    int k, i, j, x, aleatorio;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = d * (r - p + 1);
    aleatorio = p + k;

    troca(&vetor[aleatorio], &vetor[r]);

    x = vetor[r];
    i = (p - 1);

	for (j = p; j <= r - 1; j++) {
		if (vetor[j] <= x) {
			troca(&vetor[++i], &vetor[j]);
		}
	}

	troca(&vetor[i + 1], &vetor[r]);
	return (i + 1);
}

void quickSort_v4(int p, int r, int vetor[]){
    int j;
    if(p < r){
        j = partition_v4(p, r, vetor);
        quickSort_v4(p, j - 1, vetor);
        quickSort_v4(j + 1, r, vetor);
    }
}

#endif // QUICK_SORT_V4_H_INCLUDED
