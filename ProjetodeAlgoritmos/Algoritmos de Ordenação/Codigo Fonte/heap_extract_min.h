#ifndef HEAP_EXTRACT_MIN_H_INCLUDED
#define HEAP_EXTRACT_MIN_H_INCLUDED
#include "build_min_heap.h"
#include "print_heap.h"
#include "min_heapify.h"

int heap_extract_min(int *vetor, int tam){
	if(tam <= 0){
		return tam;
	}
	if(tam == 1){
		tam--;
		return vetor[0];
	}
	int x;
	build_min_heap(vetor, tam);
	printf("\n O vetor completo\n");
	print_heap(vetor, tam);
	x = vetor[0];
	vetor[0] = vetor[tam - 1];
	tam--;
	min_heapify(vetor, 0, tam);
	printf("\n Vetor com o menor valor extraido\n");
	print_heap(vetor, tam);
	return x;
}

#endif // HEAP_EXTRACT_MIN_H_INCLUDED
