#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashing_lista_encadeada.h"
#include "hashing_enderecamento_aberto.h"

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize (int vet[], int n ) {
    srand ( time(NULL) );
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&vet[i], &vet[j]);
    }
}

void preencher_vetor(int vet[], int tam_vet){

    for(int i = 0; i < tam_vet; i++){
        vet[i] = i;
    }
    randomize(vet, tam_vet);
}

int main() {
    int tam_enderecamento = 200000;
    int tam_encadeada = 10000;
    int tam_vet = 100000;
    int opcao;
    int vet[tam_vet];

    Hash *tabela[tam_encadeada];
    Hash_enderecamento tabela_enderacamento[tam_enderecamento];


    preencher_vetor(vet, tam_vet);

    do{
        system("cls");
        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Enderecamento aberto");
        printf("\n2 - Lista encadeada");
        printf("\n0 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);

        if(opcao < 0 || opcao > 2)
            printf("\nOpcao invalida!\n");
        else {
            switch (opcao) {
                case 1:
                    chamada_enderecamento(tabela_enderacamento, vet, tam_vet, tam_enderecamento);
                    break;

                case 2:
                    chamada_lista_encadeada(tabela, vet, tam_vet, tam_encadeada);
                    break;
            }
        }
    }while(opcao != 0);

    return 0;
}