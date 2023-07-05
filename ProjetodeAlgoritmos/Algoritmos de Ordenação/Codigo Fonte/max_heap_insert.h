#ifndef MAX_HEAP_INSERT_H_INCLUDED
#define MAX_HEAP_INSERT_H_INCLUDED
#include "build_min_heap.h"
#include "print_heap.h"
#include "heap_increase_key.h"

void max_heap_insert(int *vetor, int tam, int chave){
	build_min_heap(vetor, tam);
	tam++;
	vetor[tam - 1] = -1;
	printf("Vetor antes da Insercao\n");
	print_heap(vetor, tam);
	heap_increase_key(vetor, tam - 1, tam - 1, chave);
}

#endif // MAX_HEAP_INSERT_H_INCLUDED
