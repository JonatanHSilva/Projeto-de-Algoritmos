#ifndef QUICK_SORT_V2_H_INCLUDED
#define QUICK_SORT_V2_H_INCLUDED
#include "generate_input.h"

void partition_v2(int p, int r, int vetor[], int* i, int* j){
    int l, x, w;

    *i = p;
    *j = r;
    l = (*i + *j)/2;
    x = vetor[l];
    do{
        while(vetor[*i] < x){
            (*i)++;
        }
        while(vetor[*j] > x){
            (*j)--;
        }
        if(*i <= *j){
            w = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = w;
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}

void quickSort_v2(int p, int r, int vetor[]){
    int i, j;

    partition_v2(p, r, vetor, &i, &j);
    if(p < j){
        quickSort_v2(p, j, vetor);
    }
    if(i < r){
        quickSort_v2(i, r, vetor);
    }
}

#endif // QUICK_SORT_V2_H_INCLUDED
