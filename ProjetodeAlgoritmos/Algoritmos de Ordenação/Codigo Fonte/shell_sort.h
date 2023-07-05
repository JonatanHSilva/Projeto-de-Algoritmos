#ifndef SHELL_SORT_H_INCLUDED
#define SHELL_SORT_H_INCLUDED

void shellSort(int* vetor, int tam){
    int i, j, valor;

    int k = 1;
    while(k < tam){
        k = 3 * k + 1;
    }
    while (k > 0){
        for(i = k; i < tam; i++){
            valor = vetor[i];
            j = i;
            while(j > k - 1 && valor <= vetor[j - k]){
                vetor[j] = vetor[j - k];
                j = j - k;
            }
            vetor[j] = valor;
        }
        k = k / 3;
    }

}

#endif // SHELL_SORT_H_INCLUDED
