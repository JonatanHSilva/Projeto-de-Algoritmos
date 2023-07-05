#ifndef MIN_HEAPIFY_H_INCLUDED
#define MIN_HEAPIFY_H_INCLUDED
#include "generate_input.h"

int pai(int i){
	if(i % 2 == 0) {
		return i/2 - 1;
	}else{
		return i/2;
	}
}

int esquerda(int i){
	if(i == 0){
		return 1;
	}else{
		return 2 * i;
	}
}

int direita(int i){
	if(i == 0){
		return 2;
	}else{
		return 2 * i + 1;
	}
}

void min_heapify(int *vetor, int i, int tamHeap){
	int menor;
	int e = esquerda(i);
	int d = direita(i);

	if(e <= tamHeap && vetor[e] < vetor[i]){
		menor = e;
	}else{
		menor = i;
	}

	if(d <= tamHeap && vetor[d] < vetor[menor]){
		menor = d;
	}

	if(menor != i){
		troca(&vetor[i], &vetor[menor]);
		min_heapify(vetor, menor, tamHeap);
	}
}

#endif // MIN_HEAPIFY_H_INCLUDED
