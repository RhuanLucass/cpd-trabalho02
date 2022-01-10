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

void menu(Hash *tabela[], int vet[], int tam_vet, int tam){
    int op, num, pos;

    for( int i = 0; i < tam_vet; i++){
        pos = funcao_hashing(vet[i], tam);
        inserir(tabela, pos, vet[i]);
    }

    do{
        system("cls");
        printf("\nForam inseridos %d valores aleatorios\n", tam_vet);
        printf("\nLISTA ENCADEADA\n");
        printf("\nMENU DE OPCOES\n");
        printf("\n1 - Mostrar tabela hashing");
        printf("\n2 - Excluir elemento");
        printf("\n3 - Mostrar vetor aleatorio");
        printf("\n0 - Sair");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);

        if(op < 0 || op > 3)
            printf("\nOpcao invalida!");
        else{
            switch(op) {
                case 1:
                    mostrar_hash(tabela, tam);
                    getch();
                    break;

                case 2:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    remover(tabela, num, tam);
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

    menu(tabela, vet, tam_vet, tam);

    //Deslocamento de memoria
    deslocamento_memoria(tabela, tam);

    return 0;
}
