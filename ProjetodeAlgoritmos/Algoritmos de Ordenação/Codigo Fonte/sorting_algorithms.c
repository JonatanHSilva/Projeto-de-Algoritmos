#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "insertion_sort.h"
#include "generate_input.h"
#include "merge_sort.h"
#include "quick_sort_v1.h"
#include "quick_sort_v2.h"
#include "quick_sort_v3.h"
#include "quick_sort_v4.h"
#include "heap_sort.h"
#include "heap_minimum.h"
#include "heap_extract_min.h"
#include "heap_increase_key.h"
#include "max_heap_insert.h"

int main(){

	int menu, opcao, opcaoTam, tam, instancia, select, selalgoritmo;
	int i, x, entCres = 0, entDecr = 0, entAlea = 0;
	int saiCres = 0, saiDecr = 0, saiAlea = 0;
	double tempoExec;
	int* vetor;
	FILE* arq;
	char* algoritmo;
	char instanciaC[7];
	char* nomeArq;

    do{
        printf("\t------------------------------\n");
        printf("\t|                            |\n");
        printf("\t|     Sorting Algorithms     |\n");
        printf("\t|                            |\n");
        printf("\t------------------------------\n\n");

        printf("Aperte 1 para gerar instancias\n");
        printf("Aperte 2 para prosseguir mesmo sem gerar as instancias\n");
        printf("Aperte 0 para sair da aplicacao\n");
        scanf("%d", &select);

        if(select == 1){
            printf("Aguarde... Gerando instancias crescentes...\n");
            system("mkdir \"Arquivo de entrada\\Crescente");
            for(i = 0; i < 6; i++){
                instancia = pow(10, i + 1);
                itoa(instancia, instanciaC, 10);
                vetor = (int*) malloc(instancia * sizeof(int));
                nomeArq = (char*) malloc(50 * sizeof(char));
                numeros_crescente(vetor, instancia);
                strcpy(nomeArq, "Arquivo de entrada/Crescente/entradacrescente");
                strcat(nomeArq, instanciaC);
                strcat(nomeArq, ".txt");
                sleep(2);
                /*printf("%s", nomeArq);
                system("pause");*/
                arq = fopen(nomeArq, "w");
                fprintf(arq, "%s\n", instanciaC);
                for(x = 0; x < instancia; x++){
                    fprintf(arq, "%d\n", vetor[x]);
                }
                free(vetor);
                fclose(arq);
                free(nomeArq);
            }
            printf("Instancias geradas com sucesso!!!\n");
            printf("Aguarde... Gerando instancias decrescentes...\n");
            system("mkdir \"Arquivo de entrada\\Decrescente");
            for(i = 0; i < 6; i++){
                instancia = pow(10, i + 1);
                itoa(instancia, instanciaC, 10);
                vetor = (int*) malloc(instancia * sizeof(int));
                nomeArq = (char*) malloc(50 * sizeof(char));
                numeros_decrescente(vetor, instancia);
                strcpy(nomeArq, "Arquivo de entrada/Decrescente/entradadecrescente");
                strcat(nomeArq, instanciaC);
                strcat(nomeArq, ".txt");
                sleep(2);
                arq = fopen(nomeArq, "w");
                fprintf(arq, "%s\n", instanciaC);
                for(x = 0; x < instancia; x++){
                    fprintf(arq, "%d\n", vetor[x]);
                }
                free(vetor);
                fclose(arq);
                free(nomeArq);
            }
            printf("Instancias geradas com sucesso!!!\n");
            printf("Aguarde... Gerando instancias aleatorias...\n");
            system("mkdir \"Arquivo de entrada\\Aleatorio");
            for(i = 0; i < 6; i++){
                instancia = pow(10, i + 1);
                itoa(instancia, instanciaC, 10);
                vetor = (int*) malloc(instancia * sizeof(int));
                nomeArq = (char*) malloc(50 * sizeof(char));
                numeros_decrescente(vetor, instancia);
                strcpy(nomeArq, "Arquivo de entrada/Aleatorio/entradaaleatorio");
                strcat(nomeArq, instanciaC);
                strcat(nomeArq, ".txt");
                sleep(2);
                arq = fopen(nomeArq, "w");
                fprintf(arq, "%s\n", instanciaC);
                for(x = 0; x < instancia; x++){
                    fprintf(arq, "%d\n", vetor[x]);
                }
                free(vetor);
                fclose(arq);
                free(nomeArq);
            }
            printf("Instancias geradas com sucesso!!!\n");
            select = 2;
        }
        else if(select == 0){
            exit(0);
        }
    }while(select != 2);

	do{
        system("cls");
        printf("\t------------------------------\n");
        printf("\t|                            |\n");
        printf("\t|     Sorting Algorithms     |\n");
        printf("\t|                            |\n");
        printf("\t------------------------------\n\n");

        printf("Selecione o algoritmo que deseja utilizar:\n");
        printf("1 - Insertion Sort\n");
        printf("2 - Merge Sort\n");
        printf("3 - Quick Sort - versao 1\n");
        printf("4 - Quick Sort - versao 2\n");
        printf("5 - Quick Sort - versao 3\n");
        printf("6 - Quick Sort - versao 4\n");
        printf("7 - Heap Sort\n");
        printf("0 - Sair da aplicacao\n");
        scanf("%d", &selalgoritmo);

        if(selalgoritmo < 8 && selalgoritmo > 0){
            switch(selalgoritmo){
                case 1:
                    algoritmo = (char*) malloc(15 * sizeof(char));
                    strcpy(algoritmo, "Insertion Sort");
                    break;
                case 2:
                    algoritmo = (char*) malloc(11 * sizeof(char));
                    strcpy(algoritmo, "Merge Sort");
                    break;
                case 3:
                    algoritmo = (char*) malloc(15 * sizeof(char));
                    strcpy(algoritmo, "Quick Sort v.1");
                    break;
                case 4:
                    algoritmo = (char*) malloc(15 * sizeof(char));
                    strcpy(algoritmo, "Quick Sort v.2");
                    break;
                case 5:
                    algoritmo = (char*) malloc(15 * sizeof(char));
                    strcpy(algoritmo, "Quick Sort v.3");
                    break;
                case 6:
                    algoritmo = (char*) malloc(15 * sizeof(char));
                    strcpy(algoritmo, "Quick Sort v.4");
                    break;
                case 7:
                    algoritmo = (char*) malloc(10 * sizeof(char));
                    strcpy(algoritmo, "Heap Sort");
                    break;
                default:
                    printf("Opcao invalida, tente novamente...");
                    break;
            }

            do{
                system("cls");
                if(selalgoritmo == 1){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|  Algoritmo Insertion Sort  |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 2){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|    Algoritmo Merge Sort    |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 3){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|  Algoritmo Quick Sort v.1  |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 4){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|  Algoritmo Quick Sort v.2  |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 5){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|  Algoritmo Quick Sort v.3  |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 6){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|  Algoritmo Quick Sort v.4  |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }else if(selalgoritmo == 7){
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|    Algoritmo Heap Sort     |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");
                }

                printf("Escolha uma das opcoes abaixo:\n");
                printf("1 - %s nas instancias crescentes\n", algoritmo);
                printf("2 - %s nas instancias decrescentes\n", algoritmo);
                printf("3 - %s nas instancias randomicas\n", algoritmo);
                if(selalgoritmo == 7){
                    printf("4 - Gerar HEAP_MINIMUM\n");
                    printf("5 - Extrair HEAP_EXTRACT_MIN\n");
                    printf("6 - Inserir o elemento 1000 em uma posicao no HEAP_INCREASE_KEY\n");
                    printf("7 - Inserir o elemento 1000 no MAX_HEAP_INSERT\n");
                }
                printf("0 - Voltar ao menu principal\n");
                scanf("%d", &menu);
                if(selalgoritmo == 7){
                    if(menu > 7 || menu < 0){
                        printf("Opcao invalida, tente novamente...\n");
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(menu > 3 || menu < 0){
                        printf("Opcao invalida, tente novamente...\n");
                    }
                }

                if(menu == 0){
                    break;
                }

            }while(menu > 3 || menu < 0);

            free(algoritmo);

            do{
                switch(menu){
                    case 0:
                        break;
                    case 1:
                        if(saiCres == 0){
                            if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Crescente")){
                                system("mkdir \"Tempo de execucao\\Insertion Sort\\Crescente");
                                system("mkdir \"Arquivo de saida\\Merge Sort\\Crescente");
                                system("mkdir \"Tempo de execucao\\Merge Sort\\Crescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.1\\Crescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.1\\Crescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.2\\Crescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.2\\Crescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.3\\Crescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.3\\Crescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.4\\Crescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.4\\Crescente");
                                system("mkdir \"Arquivo de saida\\Heap Sort\\Crescente");
                                system("mkdir \"Tempo de execucao\\Heap Sort\\Crescente");
                            }
                            saiCres = 1;
                        }

                        do{
                            printf("\nEscolha o tamanho da instancia:\n");
                            printf("1 - 10\n");
                            printf("2 - 100\n");
                            printf("3 - 1.000\n");
                            printf("4 - 10.000\n");
                            printf("5 - 100.000\n");
                            printf("6 - 1.000.000\n");
                            scanf("%d", &opcaoTam);

                              switch(opcaoTam){
                                    case 1:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente10.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);

                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);


                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente10.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente10.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente10.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente10.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente10.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente10.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente10.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);

                                        }
                                        break;
                                    case 2:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente100.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente100.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente100.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente100.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente100.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente100.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente100.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente100.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 3:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente1000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente1000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente1000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente1000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente1000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente1000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente1000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente1000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 4:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente10000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente10000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente10000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente10000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente10000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente10000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente10000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente10000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 5:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente100000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente100000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente100000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente100000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente100000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente100000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente100000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente100000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }

                                        break;
                                    case 6:
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente1000000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Crescente/tempocrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Crescente/saidacrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Crescente/saidacrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Crescente/saidacrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Crescente/saidacrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Crescente/saidacrescente1000000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Crescente/saidacrescente1000000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                        menu = 0;
                        break;
                    case 2:
                        if(saiCres == 0){
                            if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Decrescente")){
                                system("mkdir \"Tempo de execucao\\Insertion Sort\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Merge Sort\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Merge Sort\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.1\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.1\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.2\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.2\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.3\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.3\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.4\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.4\\Decrescente");
                                system("mkdir \"Arquivo de saida\\Heap Sort\\Decrescente");
                                system("mkdir \"Tempo de execucao\\Heap Sort\\Decrescente");
                            }
                            saiCres = 1;
                        }

                        do{
                            printf("\nEscolha o tamanho da instancia:\n");
                            printf("1 - 10\n");
                            printf("2 - 100\n");
                            printf("3 - 1.000\n");
                            printf("4 - 10.000\n");
                            printf("5 - 100.000\n");
                            printf("6 - 1.000.000\n");
                            scanf("%d", &opcaoTam);

                              switch(opcaoTam){
                                    case 1:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente10.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente10.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente10.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente10.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente10.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente10.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente10.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente10.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente10.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 2:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente100.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente100.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente100.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente100.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente100.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente100.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente100.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente100.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente100.txt", "w");
                                            }


                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 3:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente1000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente1000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente1000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente1000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente1000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente1000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente1000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente1000.txt", "w");
                                            }


                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 4:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente10000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente10000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente10000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente10000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente10000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente10000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente10000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente10000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 5:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente100000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente100000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente100000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente100000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente100000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente100000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente100000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente100000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 6:
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente1000000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Decrescente/saidadecrescente1000000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                        menu = 0;
                        break;
                    case 3:
                        if(saiCres == 0){
                            if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Aleatorio")){
                                system("mkdir \"Tempo de execucao\\Insertion Sort\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Merge Sort\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Merge Sort\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.1\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.1\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.2\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.2\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.3\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.3\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Quick Sort v.4\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Quick Sort v.4\\Aleatorio");
                                system("mkdir \"Arquivo de saida\\Heap Sort\\Aleatorio");
                                system("mkdir \"Tempo de execucao\\Heap Sort\\Aleatorio");
                            }
                            saiCres = 1;
                        }

                        do{
                            printf("\nEscolha o tamanho da instancia:\n");
                            printf("1 - 10\n");
                            printf("2 - 100\n");
                            printf("3 - 1.000\n");
                            printf("4 - 10.000\n");
                            printf("5 - 100.000\n");
                            printf("6 - 1.000.000\n");
                            scanf("%d", &opcaoTam);

                              switch(opcaoTam){
                                    case 1:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio10.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio10.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 2:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio100.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio100.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 3:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio1000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 4:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio10000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 5:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio100000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    case 6:
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio1000000.txt", "r");
                                        if(arq == NULL){
                                            printf("Instancia nao existente, favor gerar instancia...\n");
                                            sleep(5);
                                        }
                                        else{
                                            fscanf(arq, "%d", &tam);
                                            vetor = (int*) malloc(tam * sizeof(int));
                                            for(x = 0; x < tam; x++){
                                                fscanf(arq, "%d", &vetor[x]);
                                            }
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                insertionSort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Tempo de execucao/Merge Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                mergeSort(0, tam, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Tempo de execucao/Quick Sort v.1/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v1(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Tempo de execucao/Quick Sort v.2/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v2(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Tempo de execucao/Quick Sort v.3/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v3(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Tempo de execucao/Quick Sort v.4/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                quickSort_v4(0, tam - 1, vetor);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }else{
                                                arq = fopen("Tempo de execucao/Heap Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                clock_t inicio = clock();
                                                heapsort(vetor, tam);
                                                clock_t fim = clock();
                                                tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                            }

                                            printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                            sleep(2);
                                            fprintf(arq, "%f", tempoExec);
                                            fclose(arq);

                                            if(selalgoritmo == 1){
                                                arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else if(selalgoritmo == 2){
                                                arq = fopen("Arquivo de saida/Merge Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else if(selalgoritmo == 3){
                                                arq = fopen("Arquivo de saida/Quick Sort v.1/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else if(selalgoritmo == 4){
                                                arq = fopen("Arquivo de saida/Quick Sort v.2/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else if(selalgoritmo == 5){
                                                arq = fopen("Arquivo de saida/Quick Sort v.3/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else if(selalgoritmo == 6){
                                                arq = fopen("Arquivo de saida/Quick Sort v.4/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }else{
                                                arq = fopen("Arquivo de saida/Heap Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                            }

                                            fprintf(arq, "%d\n", tam);
                                            for(x = 0; x < tam; x++){
                                                fprintf(arq, "%d\n", vetor[x]);
                                            }
                                            free(vetor);
                                            fclose(arq);
                                        }
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                        menu = 0;
                        break;
                    case 4:
                        if(selalgoritmo == 7){
                            do{
                                printf("1 - HEAP_MINIMUM em vetor crescente\n");
                                printf("2 - HEAP_MINIMUM em vetor decrescente\n");
                                printf("3 - HEAP_MINIMUM em vetor randomico\n");
                                scanf("%d", &opcao);

                                if(opcao == 1){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_crescente(vetor, 10);
                                            heap_minimun(vetor, 10);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_crescente(vetor, 100);
                                            heap_minimun(vetor, 100);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_crescente(vetor, 1000);
                                            heap_minimun(vetor, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_crescente(vetor, 10000);
                                            heap_minimun(vetor, 10000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_crescente(vetor, 100000);
                                            heap_minimun(vetor, 100000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_crescente(vetor, 1000000);
                                            heap_minimun(vetor, 1000000);
                                            break;
                                    }
                                    break;
                                }else if(opcao == 2){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_decrescente(vetor, 10);
                                            heap_minimun(vetor, 10);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_decrescente(vetor, 100);
                                            heap_minimun(vetor, 100);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000);
                                            heap_minimun(vetor, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_decrescente(vetor, 10000);
                                            heap_minimun(vetor, 10000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_decrescente(vetor, 100000);
                                            heap_minimun(vetor, 100000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000000);
                                            heap_minimun(vetor, 1000000);
                                            break;
                                    }
                                    break;
                                }else if(opcao == 3){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_aleatorios(vetor, 10);
                                            heap_minimun(vetor, 10);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_aleatorios(vetor, 100);
                                            heap_minimun(vetor, 100);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000);
                                            heap_minimun(vetor, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_aleatorios(vetor, 10000);
                                            heap_minimun(vetor, 10000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_aleatorios(vetor, 100000);
                                            heap_minimun(vetor, 100000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000000);
                                            heap_minimun(vetor, 1000000);
                                            break;
                                    }
                                    break;
                                }
                            }while(opcao < 1 || opcao > 3);
                            free(vetor);
                        }
                        break;
                    case 5:
                        if(selalgoritmo == 7){
                            int valor;

                            do{
                                printf("1 - HEAP_EXTRACT_MINIMUM em vetor crescente\n");
                                printf("2 - HEAP_EXTRACT_MINIMUM em vetor decrescente\n");
                                printf("3 - HEAP_EXTRACT_MINIMUM em vetor randomico\n");
                                scanf("%d", &opcao);

                                if(opcao == 1){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_crescente(vetor, 10);
                                            valor = heap_extract_min(vetor, 10);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_crescente(vetor, 100);
                                            valor = heap_extract_min(vetor, 100);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_crescente(vetor, 1000);
                                            valor = heap_extract_min(vetor, 1000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_crescente(vetor, 10000);
                                            valor = heap_extract_min(vetor, 10000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_crescente(vetor, 100000);
                                            valor = heap_extract_min(vetor, 100000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_crescente(vetor, 1000000);
                                            valor = heap_extract_min(vetor, 1000000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                    }
                                }else if(opcao == 2){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_decrescente(vetor, 10);
                                            valor = heap_extract_min(vetor, 10);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_decrescente(vetor, 100);
                                            valor = heap_extract_min(vetor, 100);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000);
                                            valor = heap_extract_min(vetor, 1000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_decrescente(vetor, 10000);
                                            valor = heap_extract_min(vetor, 10000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_decrescente(vetor, 100000);
                                            valor = heap_extract_min(vetor, 100000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000000);
                                            valor = heap_extract_min(vetor, 1000000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                    }
                                }else if(opcao == 3){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_aleatorios(vetor, 10);
                                            valor = heap_extract_min(vetor, 10);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_aleatorios(vetor, 100);
                                            valor = heap_extract_min(vetor, 100);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000);
                                            valor = heap_extract_min(vetor, 1000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_aleatorios(vetor, 10000);
                                            valor = heap_extract_min(vetor, 10000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_aleatorios(vetor, 100000);
                                            valor = heap_extract_min(vetor, 100000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000000);
                                            valor = heap_extract_min(vetor, 1000000);
                                            printf("O menor valor extraido foi %d\n", valor);
                                            sleep(2);
                                            break;
                                    }
                                }
                            }while(opcao > 3 || opcao < 1);
                            free(vetor);
                        }
                        break;
                    case 6:
                        if(selalgoritmo == 7){
                            int posicao;

                            do{
                                printf("\n1 - HEAP_INCREASE_KEY em vetor crescente\n");
                                printf("2 - HEAP_INCREASE_KEY em vetor decrescente\n");
                                printf("3 - HEAP_INCREASE_KEY em vetor randomico\n");
                                scanf("%d", &opcao);

                                if(opcao == 1){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_crescente(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10);
                                            heap_increase_key(vetor, 10, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_crescente(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 100){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 100);
                                            heap_increase_key(vetor, 100, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_crescente(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000);
                                            heap_increase_key(vetor, 1000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_crescente(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10000);
                                            heap_increase_key(vetor, 10000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_crescente(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 100000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 100000);
                                            heap_increase_key(vetor, 100000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_crescente(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000000);
                                            heap_increase_key(vetor, 1000000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                    }
                                }else if(opcao == 2){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_decrescente(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10);
                                            heap_increase_key(vetor, 10, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_decrescente(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 100){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 100);
                                            heap_increase_key(vetor, 100, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000);
                                            heap_increase_key(vetor, 1000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_decrescente(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10000);
                                            heap_increase_key(vetor, 10000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_decrescente(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 100000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1|| posicao > 100000);
                                            heap_increase_key(vetor, 100000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_decrescente(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000000);
                                            heap_increase_key(vetor, 1000000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                    }
                                }else if(opcao == 3){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (10 * sizeof(int));
                                            numeros_aleatorios(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10);
                                            heap_increase_key(vetor, 10, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (100 * sizeof(int));
                                            numeros_aleatorios(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 100){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 100);
                                            heap_increase_key(vetor, 100, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000);
                                            heap_increase_key(vetor, 1000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10000 * sizeof(int));
                                            numeros_aleatorios(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 10000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 10000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 10000);
                                            heap_increase_key(vetor, 10000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100000 * sizeof(int));
                                            numeros_aleatorios(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 100000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 0 || posicao > 100000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 0 || posicao > 100000);
                                            heap_increase_key(vetor, 100000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000000 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            do{
                                                printf("Digite em qual posicao de 1 a 1000000 que voce deseja adicionar o elemento 1000\n");
                                                scanf("%d", &posicao);
                                                if(posicao < 1 || posicao > 1000000){
                                                    printf("Posicao invalida, tente novamente\n");
                                                }
                                            }while(posicao < 1 || posicao > 1000000);
                                            heap_increase_key(vetor, 1000000, posicao - 1, 1000);
                                            sleep(2);
                                            break;
                                    }
                                }
                            }while(opcao > 3 || opcao < 1);
                            free(vetor);
                        }
                        break;
                    case 7:
                        if(selalgoritmo == 7){
                            int valor;

                            do{
                                printf("\n1 - MAX_HEAP_INSERT em vetor crescente\n");
                                printf("2 - MAX_HEAP_INSERT em vetor decrescente\n");
                                printf("3 - MAX_HEAP_INSERT em vetor randomico\n");
                                scanf("%d", &opcao);

                                if(opcao == 1){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (11 * sizeof(int));
                                            numeros_crescente(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            max_heap_insert(vetor, 10, 1000);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (101 * sizeof(int));
                                            numeros_crescente(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            max_heap_insert(vetor, 100, 1000);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1001 * sizeof(int));
                                            numeros_crescente(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            max_heap_insert(vetor, 1000, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10001 * sizeof(int));
                                            numeros_crescente(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            max_heap_insert(vetor, 10000, 1000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100001 * sizeof(int));
                                            numeros_crescente(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            max_heap_insert(vetor, 100000, 1000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000001 * sizeof(int));
                                            numeros_crescente(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            max_heap_insert(vetor, 1000000, 1000);
                                            break;
                                    }
                                }else if(opcao == 2){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (11 * sizeof(int));
                                            numeros_decrescente(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            max_heap_insert(vetor, 10, 1000);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (101 * sizeof(int));
                                            numeros_decrescente(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            max_heap_insert(vetor, 100, 1000);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1001 * sizeof(int));
                                            numeros_decrescente(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            max_heap_insert(vetor, 1000, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10001 * sizeof(int));
                                            numeros_decrescente(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            max_heap_insert(vetor, 10000, 1000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100001 * sizeof(int));
                                            numeros_decrescente(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            max_heap_insert(vetor, 100000, 1000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000001 * sizeof(int));
                                            numeros_decrescente(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            max_heap_insert(vetor, 1000000, 1000);
                                            break;
                                    }
                                }else if(opcao == 3){
                                    do{
                                        printf("\nEscolha o tamanho da instancia:\n");
                                        printf("1 - 10\n");
                                        printf("2 - 100\n");
                                        printf("3 - 1.000\n");
                                        printf("4 - 10.000\n");
                                        printf("5 - 100.000\n");
                                        printf("6 - 1.000.000\n");
                                        scanf("%d", &opcaoTam);
                                    }while(opcaoTam > 6 || opcaoTam < 1);
                                    switch(opcaoTam){
                                        case 1:
                                            vetor = (int*) malloc (11 * sizeof(int));
                                            numeros_aleatorios(vetor, 10);
                                            build_min_heap(vetor, 10);
                                            max_heap_insert(vetor, 10, 1000);
                                            break;
                                        case 2:
                                            vetor = (int*) malloc (101 * sizeof(int));
                                            numeros_aleatorios(vetor, 100);
                                            build_min_heap(vetor, 100);
                                            max_heap_insert(vetor, 100, 1000);
                                            break;
                                        case 3:
                                            vetor = (int*) malloc (1001 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000);
                                            build_min_heap(vetor, 1000);
                                            max_heap_insert(vetor, 1000, 1000);
                                            break;
                                        case 4:
                                            vetor = (int*) malloc (10001 * sizeof(int));
                                            numeros_aleatorios(vetor, 10000);
                                            build_min_heap(vetor, 10000);
                                            max_heap_insert(vetor, 10000, 1000);
                                            break;
                                        case 5:
                                            vetor = (int*) malloc (100001 * sizeof(int));
                                            numeros_aleatorios(vetor, 100000);
                                            build_min_heap(vetor, 100000);
                                            max_heap_insert(vetor, 100000, 1000);
                                            break;
                                        case 6:
                                            vetor = (int*) malloc (1000001 * sizeof(int));
                                            numeros_aleatorios(vetor, 1000000);
                                            build_min_heap(vetor, 1000000);
                                            max_heap_insert(vetor, 1000000, 1000);
                                            break;
                                    }
                                }
                            }while(opcao > 3 || opcao < 1);
                            free(vetor);
                        }
                        break;
                }
            }while(menu != 0);
        }
    }while(selalgoritmo != 0);
	return 0;
}
