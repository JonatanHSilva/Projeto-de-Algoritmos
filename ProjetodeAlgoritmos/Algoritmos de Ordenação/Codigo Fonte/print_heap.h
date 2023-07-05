#ifndef PRINT_HEAP_H_INCLUDED
#define PRINT_HEAP_H_INCLUDED

void print_heap(int *vetor, int tam){
	int x;
	printf("Imprimindo o Heap\n");
	for(x = tam - 1; x >= 0; x--){
		printf(" %d ",vetor[x]);
	}
	printf("\n");
}

#endif // PRINT_HEAP_H_INCLUDED
