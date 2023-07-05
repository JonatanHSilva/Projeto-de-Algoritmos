#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

void selectionSort(int* vetor, int tam){
    int i, j, menor, aux;
    for(i = 0; i < (tam - 1); i++){
        menor = i;
        for(j = i+1; j < tam; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

#endif // SELECTION_SORT_H_INCLUDED
