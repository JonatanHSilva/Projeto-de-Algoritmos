#ifndef INSERTION_SORT_BBT_H_INCLUDED
#define INSERTION_SORT_BBT_H_INCLUDED

void insertionSort(int* vetor, int tam){
    int i, j, chave;
    for (i = 1; i < tam; i++){
        chave = vetor[i];
        j = i - 1;
        while(j >=  0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

#endif // INSERTION_SORT_BBT_H_INCLUDED
