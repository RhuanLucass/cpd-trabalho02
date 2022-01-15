#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "hashing_lista_encadeada.h"

struct hash{
    int chave;
    struct hash *prox; // L = livre, O = ocupado, R = removido
};

int funcao_hashing(int num, int tam){
    return num % tam;
}

void mostrar_hash(Hash *tabela[], int tam){
    Hash *aux;
    for(int i = 0; i < tam; i++){
        aux = tabela[i];
        while(aux != NULL){
            printf("\nEntrada %d: %d", i, aux->chave);
            aux = aux->prox;
        }
    }

}

void inserir(Hash *tabela[], int pos, int n){
    Hash *novo;
    novo = (Hash *) malloc(sizeof(Hash));
    novo->chave = n;
    novo->prox = tabela[pos];
    tabela[pos] = novo;
}

int busca(Hash *tabela[], int num, int tam) {
    int pos = funcao_hashing(num, tam);
    Hash *aux;
    aux = tabela[pos];

    while(aux != NULL){
        if(aux->chave == num)
            return aux->chave;
        aux = aux->prox;
    }
    return -1;
}

void inicializar_encadeada(Hash *tabela[], int tam){
    for(int i = 0; i < tam; i++)
        tabela[i] = NULL;
}

void deslocamento_memoria(Hash *tabela[], int tam){
    for(int i = 0; i < tam; i++){
        Hash *aux;
        while(tabela[i] != NULL){
            aux = tabela[i];
            tabela[i] = tabela[i]->prox;
            free(aux);
        }
        tabela[i] = NULL;
    }
}

int chamada_lista_encadeada(Hash *tabela[], int vet[], int tam_vet, int tam) {

    // Inicialização da tabela
    inicializar_encadeada(tabela, tam);

    int pos;

    //Imprimir vetor aleatorio
    /*printf("\nVetor: \n");
    for(int i = 0; i < tam_vet; i++)
        printf("%d ", vet[i]);*/

    //Inserindo todos os elementos do vetor na tabela
    clock_t begin = clock(); //Tempo inicial

    for( int i = 0; i < tam_vet; i++){
        pos = funcao_hashing(vet[i], tam);
        inserir(tabela, pos, vet[i]);
    }

    clock_t end = clock(); //Tempo final
    double time_insercao_encadeada = (double) (end - begin) / CLOCKS_PER_SEC;  //Calcula o tempo de execução


    printf("\n\nForam inseridos %d valores aleatorios\n", tam_vet);
    //mostrar_hash(tabela, tam);


    //Buscando todos os valores na tabela
    printf("\nForam buscados todos os valores na tabela\n");


    printf("\n\n");
    clock_t inicio = clock(); //Tempo inicial

    for(int i = 0; i < tam_vet; i++)
        busca(tabela, vet[i], tam);

    clock_t fim = clock(); //Tempo final
    double time_busca_encadeada = (double) (fim - inicio) / CLOCKS_PER_SEC;  //Calcula o tempo de execução

    //Realizando a busca novamente para que os valores buscados sejam impressos sem contar a impressao no tempo total de busca
    /*for(int i = 0; i < tam_vet; i++){
        int res = busca(tabela, vet[i], tam);
        printf("%d ", res);
    }*/

    //Deslocamento de memoria
    deslocamento_memoria(tabela, tam);

    printf("\n\nTempo total para:\n");
    printf("INSERIR: %lf\n", time_insercao_encadeada);
    printf("BUSCAR: %lf\n", time_busca_encadeada);

    getch();

    return 0;
}