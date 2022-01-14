#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//AVL
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b);

int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	return(node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	
	x->right = y;
	y->left = T2;

	
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	
	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	
	y->left = x;
	x->right = T2;

	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	
	return y;
}

int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int key)
{
	
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	
	node->height = 1 + max(height(node->left),
						height(node->right));

	
	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}	
	return node;
}

//ABB
typedef struct arvore
{
    int num;
    struct arvore *esq, *dir;
}arvore;

arvore * inserir(arvore* aux, int num)
{
    if(aux == NULL)
    {
        aux = malloc(sizeof(arvore));
        aux->num = num;
        aux->esq = NULL;
        aux->dir = NULL;
    }
    else if(num < aux->num)
    {
        aux->esq = inserir(aux->esq, num);
    }
    else
    {
        aux->dir = inserir(aux->dir, num);
    }
    return aux;
}

int consultar(arvore * aux, int num, int achou)
{
    if(aux != NULL && achou == 0)
    {
        if(aux->num == num)
        {
            achou = 1;
        }
        else if(num < aux->num)
        {
            achou = consultar(aux->esq, num, achou);
        }
        else
        {
            achou = consultar(aux->dir, num, achou);
        }
    }
    return achou;
}

struct arvore * remover(arvore * aux, int num)
{
    arvore *p, *p2;
    if(aux->num == num)
    {
        if(aux->esq == aux->dir)
        {
            free(aux);
            return NULL;
        }
        else if (aux->esq == NULL)
        {
            p = aux->dir;
            free(aux);
            return p;
        }
        else if(aux->dir == NULL)
        {
            p = aux->esq;
            free(aux);
            return p;
        }
        else
        {
            p2 = aux->dir;
            p = aux->dir;
            while (p->esq != NULL)
            {
                p = p->esq;
            }
            p->esq = aux->esq;
            free(aux);
            return p2;
        }

    }
    else if(aux->num < num)
    {
        aux->dir = remover(aux->dir, num);    
    }
    else
    {
        aux->esq = remover(aux->esq, num);
    }
    return aux;
}

void preencherVetor(int vet[], int tam_vet)
{
    for (int i = 0; i < tam_vet; i++)
    {
        vet[i] = rand() % 10000;
    }
}

int main() { 
    arvore *raiz = NULL;
    struct Node *root = NULL;
    int n=10000, vet[10000];
    arvore *aux;
    double time_spent;
    int op, op2, op3, achou, numero;
    printf("Escolha um algoritmo! Digite 1 para AVL, 2 para ABB ou caso nao queira nenhum, digite 0 para sair\n");
    scanf("%d", &op);
    if(op < 0 || op > 2)
    {
        printf("Opcao invalida!\n");
    }
    else
    {
        if(op == 1)
        {
        for(int i=0; i<n; i++)
        {
            preencherVetor(vet, n);
            printf("%d ", vet[i]);
        }
        printf("Menu de opcoes: \n");
        printf("\n1-Inserir na arvore\n");
        printf("\n2-Consultar um no da arvore\n");
        printf("\n3-Excluir um no da arvore\n");
        printf("\n4-Sair\n\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &op2);
        clock_t begin = clock();
        if(op2 < 1 || op2 > 4)
        {
            printf("Opcao invalida!\n");
        }
        else
        {
            

            switch(op2)
            {
            case 1:

            printf("Digite o numero a ser inserido na arvore\n");
            scanf("%d", &numero);
            raiz = inserir(raiz, numero);
            printf("\nNumero inserido na arvore!\n", numero);
            break;
            
            case 2:
        
            if(raiz == NULL)
            {
                printf("A arvore esta vazia!\n");
            }
            else
            {
                printf("Digite o elemento a ser consultado: \n");
                scanf("%d", &numero);
                achou = 0;
                achou = consultar(raiz, numero, achou);
                if(achou == 0)
                {
                    printf("Numero nao encontrado na arvore\n");
                }
                else
                {
                    printf("Numero encontrado na árvore!\n");
                }
            }
            
            case 3:
        
            if(raiz == NULL)
            {
                printf("Arvore vazia!\n");
            }
            else
            {
                printf("Digite o numero que deseja excluir:\n");
                scanf("%d\n", &numero);
                achou = 0;
                achou = consultar(raiz, numero, achou);
                if(achou == 0)
                {
                    printf("Numero nao encontrado na arvore\n");
                }
                else
                {
                    raiz = remover(raiz, numero);
                    printf("Numero excluido da arvore!\n");
                }
            }
            
            case 4:
                return 0;
            }   
        }
      clock_t end = clock();
      time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
      printf("Tempo de execucao: %.1f s\n", time_spent);   
    }

        else if(op == 2)
        {
        for(int i=0; i<n; i++)
        {
            preencherVetor(vet, n);
            printf("%d ", vet[i]);
        }
            printf("\n\nMenu de opcoes: \n");
            printf("\n1-Inserir na arvore\n");
            printf("\n2-Consultar um no da arvore\n");
            printf("\n3-Excluir um no da arvore\n");
            printf("\n4-Sair\n\n");
            printf("Digite sua opcao:\n");
            scanf("%d", &op3);
            if(op3 < 1 || op3 > 4)
            {
                printf("Opcao invalida!\n");
            }
            else
            {
                switch(op3)
                {

                case 1:

                printf("Digite o numero a ser inserido na arvore\n");
                scanf("%d", &numero);
                raiz = inserir(raiz, numero);
                printf("\nNumero inserido na arvore!\n");
                break;
                
                case 2:
            
                if(raiz == NULL)
                {
                    printf("A arvore esta vazia!\n");
                }
                else
                {
                    printf("Digite o elemento a ser consultado: \n");
                    scanf("%d", &numero);
                    achou = 0;
                    achou = consultar(raiz, numero, achou);
                    if(achou == 0)
                    {
                        printf("Numero nao encontrado na arvore\n");
                    }
                    else
                    {
                        printf("Numero encontrado na árvore!\n");
                    }
                }

                case 3:
            
                if(raiz == NULL)
                {
                    printf("Arvore vazia!\n");
                }
                else
                {
                    printf("Digite o numero que deseja excluir:\n");
                    scanf("%d\n", &numero);
                    achou = 0;
                    achou = consultar(raiz, numero, achou);
                    if(achou == 0)
                    {
                        printf("Numero nao encontrado na arvore\n");
                    }
                    else
                    {
                        raiz = remover(raiz, numero);
                        printf("Numero excluido da arvore!\n");
                    }
                }
                
                case 4:
                    return 0;
                }   
            }

        }    
        else if(op == 0)
        {
            return 0;
        }
    getch();
    }
    
    return 0;
}    
    
