#ifndef HEAP_INCREASE_KEY_H_INCLUDED
#define HEAP_INCREASE_KEY_H_INCLUDED
#include "build_min_heap.h"
#include "print_heap.h"
#include "min_heapify.h"
#include "generate_input.h"

void heap_increase_key(int *vetor, int tam, int i, int chave){
	build_min_heap(vetor, tam);
	printf("\nO vetor antes do Increase Key\n");
	print_heap(vetor, tam);
    vetor[i] = chave;
    while(i > 0 && vetor[pai(i)] < vetor[i]){
        troca(&vetor[i], &vetor[pai(i)]);
        i = pai(i);
    }
	min_heapify(vetor, i, tam);
	printf("\nDepois de executar o Increase Key\n");
	print_heap(vetor, tam);
}

#endif // HEAP_INCREASE_KEY_H_INCLUDED
