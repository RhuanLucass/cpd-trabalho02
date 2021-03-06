//
// Created by rhuan on 07/01/2022.
//

#ifndef TRABALHO2_HASHING_ENDERECAMENTO_ABERTO_H
#define TRABALHO2_HASHING_ENDERECAMENTO_ABERTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct hash_enderecamento{
    int chave;
    char livre; // L = livre, O = ocupado, R = removido
}Hash_enderecamento;

int funcao_hashing_enderecamento(int num, int tam);

void mostrar_hash_enderecamento( Hash_enderecamento tabela[], int tam);

int inserir_enderecamento( Hash_enderecamento tabela[], int pos, int n, int tam);

int inserir_quadratica(Hash_enderecamento tabela[], int n, int tam);

int buscar_enderecamento( Hash_enderecamento tabela[], int n, int tam);

int buscar_end_quadratica( Hash_enderecamento tabela[], int n, int tam);

void inicializacao_enderecamento(Hash_enderecamento tabela[], int tam);

void chamada_enderecamento(Hash_enderecamento tabela[], int vet[],int tam_vet, int tam);

void chamada_end_quadratica(Hash_enderecamento tabela[], int vet[], int tam_vet, int tam);


#endif //TRABALHO2_HASHING_ENDERECAMENTO_ABERTO_H
