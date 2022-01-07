#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const int tam = 8;

typedef struct hash{
    int chave;
    char livre; // L = livre, O = ocupado, R = removido
}Hash;

int funcao_hashing(int num){
    return num % tam;
}

void mostrar_hash(Hash tabela[]){
    for(int i = 0; i < tam; i++)
        if(tabela[i].livre == 'O')
            printf("\nEntrada %d: %d", i, tabela[i].chave);
}

void inserir(Hash tabela[], int pos, int n){
    int i = 0;
    while( i < tam && tabela[(pos + i) % tam].livre!= 'L' && tabela[(pos + i) % tam].livre != 'R')
        i++;

    if(i < tam){
        tabela[(pos + i) % tam].chave = n;
        tabela[(pos + i) % tam].livre = 'O';
    }
    else
        printf("\nTabela cheia\n");
}

int buscar(Hash tabela[], int n){
    int i = 0;
    int pos = funcao_hashing(n);

    while(i < tam && tabela[(pos + i) % tam].livre != 'L' && tabela[(pos + i) % tam].chave != n)
        i++;

    if(tabela[(pos + i) % tam].chave == n && tabela [(pos + i) % tam].livre != 'R')
        return (pos + i) % tam;
    else
        return tam; // Não encontrado
}

void remover(Hash tabela[], int n){
    int posicao = buscar(tabela, n);

    if(posicao < tam)
        tabela[posicao].livre = 'R';
    else
        printf("\nElemento nao esta presente.\n");
}

int main() {
    Hash tabela[tam];
    int op, pos;
    int num, i;

    // Inicialização da tabela
    for(int i = 0; i < tam; i++)
        tabela[i].livre = 'L';

    do{
        system("cls");
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
            switch (op) {
                case 1:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    pos = funcao_hashing(num);
                    inserir(tabela, pos, num);
                    break;

                case 2:
                    mostrar_hash(tabela);
                    break;

                case 3:
                    printf("\nDigite um numero: ");
                    scanf("%d", &num);
                    remover(tabela, num);
                    break;
            }
        }
        getch();
    }while(op != 4);

    return 0;
}
