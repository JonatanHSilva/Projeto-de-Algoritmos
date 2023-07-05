#ifndef HEAP_MINIMUN_H_INCLUDED
#define HEAP_MINIMUN_H_INCLUDED
#include "build_min_heap.h"
#include "print_heap.h"
#include <stdlib.h>

void heap_minimun(int *vetor, int tam){
	int x;
	build_min_heap(vetor, tam);
	printf("Sequencia do Heap\n");
	sleep(2);
	print_heap(vetor, tam);
	printf("\nO menor elemento e %d\n", vetor[0]);
	sleep(3);
}

#endif // HEAP_MINIMUN_H_INCLUDED
