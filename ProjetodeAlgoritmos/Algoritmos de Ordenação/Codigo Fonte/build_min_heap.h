#ifndef BUILD_MIN_HEAP_H_INCLUDED
#define BUILD_MIN_HEAP_H_INCLUDED
#include "min_heapify.h"

void build_min_heap(int *vetor, int tam){
	int tamHeap = tam - 1;
	int i;
	for(i = (tam - 1) / 2; i >= 0; i--){
		min_heapify(vetor, i, tamHeap);
	}
}

#endif // BUILD_MIN_HEAP_H_INCLUDED
