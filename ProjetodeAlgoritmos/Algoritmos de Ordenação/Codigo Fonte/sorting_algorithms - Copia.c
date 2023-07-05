#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "insertion_sort.h"
#include "generate_input.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "shell_sort.h"

int main(){

	int menu, opcao, opcaoTam, tam, select;
	int i, x, entCres = 0, entDecr = 0, entAlea = 0;
	int saiCres = 0, saiDecr = 0, saiAlea = 0;
	double tempoExec;
	int* vetor;
	FILE* arq;
	char* algoritmo;

	do{
        system("cls");
        printf("\t------------------------------\n");
        printf("\t|                            |\n");
        printf("\t|     Sorting Algorithms     |\n");
        printf("\t|                            |\n");
        printf("\t------------------------------\n\n");

        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Gerar instancias\n");
        printf("2 - Utilizar as instancias geradas\n");
        printf("0 - Sair da aplicacao\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                do{
                    system("cls");
                    printf("\t------------------------------\n");
                    printf("\t|                            |\n");
                    printf("\t|     Sorting Algorithms     |\n");
                    printf("\t|                            |\n");
                    printf("\t------------------------------\n\n");

                    printf("Escolha as seguintes opcoes abaixo:\n");
                    printf("1 - Para gerar em ordem Crescente\n");
                    printf("2 - Para gerar em ordem Decrescente\n");
                    printf("3 - Para gerar em ordem Randomica\n");
                    printf("0 - Voltar ao menu principal\n");
                    scanf("%d", &menu);

                    switch(menu){
                        case 0:
                            menu = 0;
                            system("cls");
                            break;
                        case 1:
                            if(entCres == 0){
                                system("mkdir \"Arquivo de entrada\\Crescente");
                                entCres = 1;
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
                                        vetor = (int*) malloc(10 * sizeof(int));
                                        numeros_crescente(vetor, 10);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente10.txt", "w");
                                        fprintf(arq, "10\n");
                                        for(x = 0; x < 10; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 2:
                                        vetor = (int*) malloc(100 * sizeof(int));
                                        numeros_crescente(vetor, 100);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente100.txt", "w");
                                        fprintf(arq, "100\n");
                                        for(x = 0; x < 100; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 3:
                                        vetor = (int*) malloc(1000 * sizeof(int));
                                        numeros_crescente(vetor, 1000);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente1000.txt", "w");
                                        fprintf(arq, "1000\n");
                                        for(x = 0; x < 1000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 4:
                                        vetor = (int*) malloc(10000 * sizeof(int));
                                        numeros_crescente(vetor, 10000);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente10000.txt", "w");
                                        fprintf(arq, "10000\n");
                                        for(x = 0; x < 10000; x++){
                                           fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 5:
                                        vetor = (int*) malloc(100000 * sizeof(int));
                                        numeros_crescente(vetor, 100000);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente100000.txt", "w");
                                        fprintf(arq, "100000\n");
                                        for(x = 0; x < 100000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 6:
                                        vetor = (int*) malloc(1000000 * sizeof(int));
                                        numeros_crescente(vetor, 1000000);
                                        printf("\nInstancia gerada com sucesso!!!\n");
                                        sleep(2);
                                        arq = fopen("Arquivo de entrada/Crescente/entradacrescente1000000.txt", "w");
                                        fprintf(arq, "1000000\n");
                                        for(x = 0; x < 1000000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                            menu = 0;
                            break;
                        case 2:
                            if(entDecr == 0){
                                system("mkdir \"Arquivo de entrada\\Decrescente");
                                entDecr = 1;
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
                                        vetor = (int*) malloc(10 * sizeof(int));
                                        numeros_decrescente(vetor, 10);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente10.txt", "w");
                                        fprintf(arq, "10\n");
                                        for(x = 0; x < 10; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 2:
                                        vetor = (int*) malloc(100 * sizeof(int));
                                        numeros_decrescente(vetor, 100);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente100.txt", "w");
                                        fprintf(arq, "100\n");
                                        for(x = 0; x < 100; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 3:
                                        vetor = (int*) malloc(1000 * sizeof(int));
                                        numeros_decrescente(vetor, 1000);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente1000.txt", "w");
                                        fprintf(arq, "1000\n");
                                        for(x = 0; x < 1000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 4:
                                        vetor = (int*) malloc(10000 * sizeof(int));
                                        numeros_decrescente(vetor, 10000);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente10000.txt", "w");
                                        fprintf(arq, "10000\n");
                                        for(x = 0; x < 10000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 5:
                                        vetor = (int*) malloc(100000 * sizeof(int));
                                        numeros_decrescente(vetor, 100000);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente100000.txt", "w");
                                        fprintf(arq, "100000\n");
                                        for(x = 0; x < 100000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 6:
                                        vetor = (int*) malloc(1000000 * sizeof(int));
                                        numeros_decrescente(vetor, 1000000);
                                        arq = fopen("Arquivo de entrada/Decrescente/entradadecrescente1000000.txt", "w");
                                        fprintf(arq, "1000000\n");
                                        for(x = 0; x < 1000000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                            menu = 0;
                            break;
                        case 3:
                            if(entAlea == 0){
                                system("mkdir \"Arquivo de entrada\\Aleatorio");
                                entAlea = 1;
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
                                        vetor = (int*) malloc(10 * sizeof(int));
                                        numeros_aleatorios(vetor, 10);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio10.txt", "w");
                                        fprintf(arq, "10\n");
                                        for(x = 0; x < 10; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 2:
                                        vetor = (int*) malloc(100 * sizeof(int));
                                        numeros_aleatorios(vetor, 100);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio100.txt", "w");
                                        fprintf(arq, "100\n");
                                        for(x = 0; x < 100; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 3:
                                        vetor = (int*) malloc(1000 * sizeof(int));
                                        numeros_aleatorios(vetor, 1000);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio1000.txt", "w");
                                        fprintf(arq, "1000\n");
                                        for(x = 0; x < 1000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 4:
                                        vetor = (int*) malloc(10000 * sizeof(int));
                                        numeros_aleatorios(vetor, 10000);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio10000.txt", "w");
                                        fprintf(arq, "10000\n");
                                        for(x = 0; x < 10000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 5:
                                        vetor = (int*) malloc(100000 * sizeof(int));
                                        numeros_aleatorios(vetor, 100000);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio100000.txt", "w");
                                        fprintf(arq, "100000\n");
                                        for(x = 0; x < 100000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    case 6:
                                        vetor = (int*) malloc(1000000 * sizeof(int));
                                        numeros_aleatorios(vetor, 1000000);
                                        arq = fopen("Arquivo de entrada/Aleatorio/entradaaleatorio1000000.txt", "w");
                                        fprintf(arq, "1000000\n");
                                        for(x = 0; x < 1000000; x++){
                                            fprintf(arq, "%d\n", vetor[x]);
                                        }
                                        free(vetor);
                                        fclose(arq);
                                        break;
                                    default:
                                        printf("Opcao invalida, tente novamente\n");
                                        break;
                                }
                            }while(opcaoTam > 6 || opcaoTam < 1);
                            menu = 0;
                            break;
                        default:
                            printf("Opcao invalida, tente novamente!!!\n");
                            break;
                    }
                }while(menu != 0);
                break;
            case 2:
                do{
                    do{
                        system("cls");
                        printf("\t------------------------------\n");
                        printf("\t|                            |\n");
                        printf("\t|     Sorting Algorithms     |\n");
                        printf("\t|                            |\n");
                        printf("\t------------------------------\n\n");

                        printf("Selecione o algoritmo que deseja utilizar:\n");
                        printf("1 - Insertion Sort\n");
                        printf("2 - Bubble Sort\n");
                        printf("3 - Selection Sort\n");
                        printf("4 - Shell Sort\n");
                        printf("0 - Voltar ao menu principal\n");
                        scanf("%d", &select);

                        switch(select){
                            case 0:
                                menu = 0;
                                break;
                            case 1:
                                algoritmo = (char*) malloc(15 * sizeof(char));
                                strcpy(algoritmo, "Insertion Sort");
                                break;
                            case 2:
                                algoritmo = (char*) malloc(11 * sizeof(char));
                                strcpy(algoritmo, "Bubble Sort");
                                break;
                            case 3:
                                algoritmo = (char*) malloc(15 * sizeof(char));
                                strcpy(algoritmo, "Selection Sort");
                                break;
                            case 4:
                                algoritmo = (char*) malloc(11 * sizeof(char));
                                strcpy(algoritmo, "Shell Sort");
                                break;
                            default:
                                printf("Opcao invalida, tente novamente...");
                                break;
                        }
                    }while(select > 4 || select < 0);

                    do{
                        system("cls");
                        if(select == 1){
                            printf("\t------------------------------\n");
                            printf("\t|                            |\n");
                            printf("\t|  Algoritmo Insertion Sort  |\n");
                            printf("\t|                            |\n");
                            printf("\t------------------------------\n\n");
                        }else if(select == 2){
                            printf("\t------------------------------\n");
                            printf("\t|                            |\n");
                            printf("\t|   Algoritmo Bubble Sort    |\n");
                            printf("\t|                            |\n");
                            printf("\t------------------------------\n\n");
                        }else if(select == 3){
                            printf("\t------------------------------\n");
                            printf("\t|                            |\n");
                            printf("\t|  Algoritmo Selection Sort  |\n");
                            printf("\t|                            |\n");
                            printf("\t------------------------------\n\n");
                        }else{
                            printf("\t------------------------------\n");
                            printf("\t|                            |\n");
                            printf("\t|    Algoritmo Shell Sort    |\n");
                            printf("\t|                            |\n");
                            printf("\t------------------------------\n\n");
                        }

                        //if(menu != 0){
                            printf("Escolha uma das opcoes abaixo:\n");
                            printf("1 - %s nas instancias crescentes\n", algoritmo);
                            printf("2 - %s nas instancias decrescentes\n", algoritmo);
                            printf("3 - %s nas instancias randomicas\n", algoritmo);
                            printf("0 - Voltar ao menu principal\n");
                            scanf("%d", &menu);
                        //}

                        if(menu > 3 || menu < 0){
                            printf("Opcao invalida, tente novamente...\n");
                        }
                    }while(menu > 3 || menu <  0);

                    free(algoritmo);

                    switch(menu){
                        case 0:
                            break;
                        case 1:
                            if(saiCres == 0){
                                if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Crescente")){
                                    system("mkdir \"Tempo de execucao\\Insertion Sort\\Crescente");
                                    system("mkdir \"Arquivo de saida\\Bubble Sort\\Crescente");
                                    system("mkdir \"Tempo de execucao\\Bubble Sort\\Crescente");
                                    system("mkdir \"Arquivo de saida\\Selection Sort\\Crescente");
                                    system("mkdir \"Tempo de execucao\\Selection Sort\\Crescente");
                                    system("mkdir \"Arquivo de saida\\Shell Sort\\Crescente");
                                    system("mkdir \"Tempo de execucao\\Shell Sort\\Crescente");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente10.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente10.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente10.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente10.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente100.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente100.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente100.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente100.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente1000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente1000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente1000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente1000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente10000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente10000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente10000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente10000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente100000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente100000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente100000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente100000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Crescente/tempocrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Crescente/tempocrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Crescente/tempocrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Crescente/tempocrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Crescente/saidacrescente1000000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Crescente/saidacrescente1000000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Crescente/saidacrescente1000000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Crescente/saidacrescente1000000.txt", "w");
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
                            if(saiDecr == 0){
                                if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Decrescente")){
                                    system("mkdir \"Tempo de execucao\\Insertion Sort\\Decrescente");
                                    system("mkdir \"Arquivo de saida\\Bubble Sort\\Decrescente");
                                    system("mkdir \"Tempo de execucao\\Bubble Sort\\Decrescente");
                                    system("mkdir \"Arquivo de saida\\Selection Sort\\Decrescente");
                                    system("mkdir \"Tempo de execucao\\Selection Sort\\Decrescente");
                                    system("mkdir \"Arquivo de saida\\Shell Sort\\Decrescente");
                                    system("mkdir \"Tempo de execucao\\Shell Sort\\Decrescente");
                                }
                                saiDecr = 1;
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente10.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente10.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente10.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente10.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente10.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente100.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente100.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente100.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente100.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente100.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente1000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente1000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente1000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente1000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente10000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente10000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente10000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente10000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente100000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente100000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente100000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente100000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Decrescente/tempodecrescente1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Decrescente/saidadecrescente1000000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Decrescente/saidadecrescente1000000.txt", "w");
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
                            if(saiAlea == 0){
                                if(!system("mkdir \"Arquivo de saida\\Insertion Sort\\Aleatorio")){
                                    system("mkdir \"Tempo de execucao\\Insertion Sort\\Aleatorio");
                                    system("mkdir \"Arquivo de saida\\Bubble Sort\\Aleatorio");
                                    system("mkdir \"Tempo de execucao\\Bubble Sort\\Aleatorio");
                                    system("mkdir \"Arquivo de saida\\Selection Sort\\Aleatorio");
                                    system("mkdir \"Tempo de execucao\\Selection Sort\\Aleatorio");
                                    system("mkdir \"Arquivo de saida\\Shell Sort\\Aleatorio");
                                    system("mkdir \"Tempo de execucao\\Shell Sort\\Aleatorio");
                                }
                                saiAlea = 1;
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio10.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio10.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio10.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio100.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio100.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio100.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio1000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio1000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio1000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio10000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio10000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio10000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio100000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio100000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio100000.txt", "w");
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

                                                if(select == 1){
                                                    arq = fopen("Tempo de execucao/Insertion Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    insertionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 2){
                                                    arq = fopen("Tempo de execucao/Bubble Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    bubbleSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else if(select == 3){
                                                    arq = fopen("Tempo de execucao/Selection Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    selectionSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }else{
                                                    arq = fopen("Tempo de execucao/Shell Sort/Aleatorio/tempoaleatorio1000000.txt", "w");
                                                    clock_t inicio = clock();
                                                    shellSort(vetor, tam);
                                                    clock_t fim = clock();
                                                    tempoExec = (float)(fim - inicio)/CLOCKS_PER_SEC;
                                                }

                                                printf("O tempo gasto para efetuar a operacao foi %.2f segundos aproximadamente", tempoExec);
                                                sleep(2);
                                                fprintf(arq, "%f", tempoExec);
                                                fclose(arq);

                                                if(select == 1){
                                                    arq = fopen("Arquivo de saida/Insertion Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                                }else if(select == 2){
                                                    arq = fopen("Arquivo de saida/Bubble Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                                }else if(select == 3){
                                                    arq = fopen("Arquivo de saida/Selection Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
                                                }else{
                                                    arq = fopen("Arquivo de saida/Shell Sort/Aleatorio/saidaaleatorio1000000.txt", "w");
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
                    }
                }while(menu != 0);
                break;
            default:
                break;
        }
    }while(opcao != 0);

	return 0;
}
