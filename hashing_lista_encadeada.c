#include <stdio.h>
#include <stdlib.h>
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

void remover(Hash *tabela[], int num, int tam){
    int pos = funcao_hashing(num, tam);
    Hash *aux;

    if(tabela[pos] != NULL){
        if(tabela[pos]->chave == num){
            aux = tabela[pos];
            tabela[pos] = tabela[pos]->prox;
            free(aux);
        }
        else{
            aux = tabela[pos]->prox;
            Hash *ant = tabela[pos];
            while(aux != NULL && aux->chave != num){
                ant = aux;
                aux = aux->prox;
            }
            if(aux != NULL){
                ant->prox = aux->prox;
                free(aux);
            }
            else{
                printf("\nNumero nao encontrado.\n");
                getch();
            }

        }
    }
}

void inicializar_encadeada(Hash *tabela[], int tam){
    for(int i = 0; i < tam; i++)
        tabela[i] = NULL;
}

void menu(Hash *tabela[], int tam){
    int op, num, pos;
    do{
        system("cls");
        printf("\nLISTA ENCADEADA\n");
        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Inserir elemento");
        printf("\n2 - Mostrar tabela hashing");
        printf("\n3 - Excluir elemento");
        printf("\n4 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        if(op < 1 || op > 4)
            printf("\nOpcao invalida!");
        else{
            switch(op) {
                case 1:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    pos = funcao_hashing(num, tam);
                    inserir(tabela, pos, num);
                    break;

                case 2:
                    mostrar_hash(tabela, tam);
                    getch();
                    break;

                case 3:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    remover(tabela, num, tam);
                    break;
            }
        }
    }while(op != 4);
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

int chamada_lista_encadeada(Hash *tabela[], int tam) {

    // Inicialização da tabela
    inicializar_encadeada(tabela, tam);

    menu(tabela, tam);

    //Deslocamento de memoria
    deslocamento_memoria(tabela, tam);

    return 0;
}
