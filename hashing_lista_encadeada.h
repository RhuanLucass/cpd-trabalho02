//
// Created by rhuan on 07/01/2022.
//

#ifndef TRABALHO2_HASHING_LISTA_ENCADEADA_H
#define TRABALHO2_HASHING_LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct hash Hash;

int funcao_hashing(int num, int tam);

void mostrar_hash(Hash *tabela[], int tam);

void inserir(Hash *tabela[], int pos, int n);

void remover(Hash *tabela[], int num, int tam);

void inicializar(Hash *tabela[], int tam);

void menu(Hash *tabela[], int tam);

void deslocamento_memoria(Hash *tabela[], int tam);

int chamada_lista_encadeada(Hash *tabela[], int tam);


#endif //TRABALHO2_HASHING_LISTA_ENCADEADA_H
