#include <stdio.h>
#include <stdlib.h>
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

void inserir_enderecamento( Hash_enderecamento tabela[], int pos, int n, int tam){
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
    }
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

void menu_enderecamento(Hash_enderecamento tabela[], int tam){
    int op, pos;
    int num, i;
    do{
        system("cls");
        printf("\nENDERECAMENTO ABERTO\n");
        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Inserir elemento");
        printf("\n2 - Mostrar tabela hash_enderecamentoing");
        printf("\n3 - Excluir elemento");
        printf("\n4 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        if(op < 1 || op > 4)
            printf("\nOpcao invalida!");
        else{
            switch (op) {
                case 1:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    pos = funcao_hashing_enderecamento(num, tam);
                    inserir_enderecamento(tabela, pos, num, tam);
                    break;

                case 2:
                    mostrar_hash_enderecamento(tabela, tam);
                    getch();
                    break;

                case 3:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    remover_enderecamento(tabela, num, tam);
                    break;
            }
        }
    }while(op != 4);
}

void chamada_enderecamento(Hash_enderecamento tabela[], int tam) {

    // Inicialização da tabela
    inicializacao_enderecamento(tabela, tam);

    menu_enderecamento(tabela, tam);

}