#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED
#include "generate_input.h"
#include "build_min_heap.h"

void heapsort(int *vetor, int tam){
	int tamHeap = tam - 1;
	int i;
	build_min_heap(vetor, tam);
	for(i =(tam - 1); i > 0 ;i--){
		troca(&vetor[0], &vetor[i]);
		tamHeap--;
		min_heapify(vetor, 0, tamHeap);
	}
}

#endif // HEAP_SORT_H_INCLUDED
