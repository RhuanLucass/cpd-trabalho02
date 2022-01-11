#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "hashing_enderecamento_aberto.h"

int funcao_hashing_enderecamento(int num, int tam){
    return num % tam;
}

void mostrar_hash_enderecamento( Hash_enderecamento tabela[], int tam){
    for(int i = 0; i < tam; i++)
        if(tabela[i].livre == 'O')
            printf("\nEntrada %d: %d", i, tabela[i].chave);
}

int inserir_enderecamento( Hash_enderecamento tabela[], int pos, int n, int tam){
    int i = 0;
    while( i < tam && tabela[(pos + i) % tam].livre!= 'L' && tabela[(pos + i) % tam].livre != 'R')
        i++;

    if(i < tam){
        tabela[(pos + i) % tam].chave = n;
        tabela[(pos + i) % tam].livre = 'O';
    }
    else {
        printf("\nTabela cheia\n");
        getch();
        return 0;
    }
    return 1;
}

int buscar_enderecamento( Hash_enderecamento tabela[], int n, int tam){
    int i = 0;
    int pos = funcao_hashing_enderecamento(n, tam);

    while(i < tam && tabela[(pos + i) % tam].livre != 'L' && tabela[(pos + i) % tam].chave != n)
        i++;

    if(tabela[(pos + i) % tam].chave == n && tabela [(pos + i) % tam].livre != 'R')
        return (pos + i) % tam;
    else
        return tam; // Não encontrado
}

void remover_enderecamento( Hash_enderecamento tabela[], int n, int tam){
    int posicao = buscar_enderecamento(tabela, n, tam);

    if(posicao < tam)
        tabela[posicao].livre = 'R';
    else{
        printf("\nElemento nao esta presente.\n");
        getch();
    }

}

void inicializacao_enderecamento(Hash_enderecamento tabela[], int tam){
    for(int i = 0; i < tam; i++)
        tabela[i].livre = 'L';
}



void chamada_enderecamento(Hash_enderecamento tabela[], int vet[], int tam_vet, int tam) {
    int pos, valor;
    // Inicialização da tabela
    inicializacao_enderecamento(tabela, tam);

    //Imprimindo o vetor aleatorio
    /*printf("\nVetor: \n");
    for(int i = 0; i < tam_vet; i++)
        printf("%d ", vet[i]);*/

    //Inserindo todos os elementos do vetor na tabela
    clock_t begin = clock(); //Tempo inicial
    for( int i = 0; i < tam_vet; i++){
        pos = funcao_hashing_enderecamento(vet[i], tam);
        inserir_enderecamento(tabela, pos, vet[i], tam);
    }
    clock_t end = clock(); //Tempo final
    double time_insercao_enderecamento = (double) (end - begin) / CLOCKS_PER_SEC;  //Calcula o tempo de execução

    printf("\n\nForam inseridos %d valores aleatorios\n", tam_vet);

    //Buscando todos os valores na tabela
    printf("\nForam buscados todos os valores na tabela\n");
    clock_t inicio = clock(); //Tempo inicial
    for(int i = 0; i < tam_vet; i++){
        valor = buscar_enderecamento(tabela, vet[i], tam);
    }
    clock_t fim = clock(); //Tempo final
    double time_busca_enderecamento = (double) (fim - inicio) / CLOCKS_PER_SEC;  //Calcula o tempo de execução

    //Realizando a busca novamente para que os valores buscados sejam impressos sem contar a impressao no tempo total de busca
    /*for(int i = 0; i < tam_vet; i++){
        valor = buscar_enderecamento(tabela, vet[i], tam);
        printf("%d ", valor);
    }*/

    printf("\n\nTempo total para:\n");
    printf("INSERIR: %lf\n", time_insercao_enderecamento);
    printf("BUSCAR: %lf\n", time_busca_enderecamento);

    getch();

}