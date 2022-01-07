#include <stdio.h>
#include <stdlib.h>
#include "hashing_lista_encadeada.h"
#include "hashing_enderecamento_aberto.h"
    const int tam = 8;
int main() {
    int opcao;
    Hash *tabela[tam];
    Hash_enderecamento tabela_enderacamento[tam];

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
                    chamada_enderecamento(tabela_enderacamento, tam);
                    break;

                case 2:
                    chamada_lista_encadeada(tabela, tam);
                    break;
            }
        }
    }while(opcao != 0);






    return 0;
}