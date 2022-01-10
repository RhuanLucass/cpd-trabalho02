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

void menu_enderecamento(Hash_enderecamento tabela[], int vet[], int tam_vet, int tam){
    int op, pos, num;

    for( int i = 0; i < tam_vet; i++){
        pos = funcao_hashing_enderecamento(vet[i], tam);
        inserir_enderecamento(tabela, pos, vet[i], tam);
    }

    do{
        system("cls");
        printf("\nForam inseridos %d valores aleatorios\n", tam_vet);
        printf("\nENDERECAMENTO ABERTO\n");
        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Mostrar tabela");
        printf("\n2 - Excluir elemento");
        printf("\n3 - Mostrar vetor aleatorio");
        printf("\n0 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        if(op < 0 || op > 3)
            printf("\nOpcao invalida!");
        else{
            switch (op) {
                case 1:
                    mostrar_hash_enderecamento(tabela, tam);
                    getch();
                    break;

                case 2:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    remover_enderecamento(tabela, num, tam);
                    break;

                case 3:
                    printf("\nVetor: \n");
                    for(int i = 0; i < tam_vet; i++)
                        printf("%d ", vet[i]);
                    getch();
            }
        }
    }while(op != 0);
    exit(0);
}

void chamada_enderecamento(Hash_enderecamento tabela[], int vet[], int tam_vet, int tam) {

    // Inicialização da tabela
    inicializacao_enderecamento(tabela, tam);

    menu_enderecamento(tabela, vet, tam_vet, tam);

}