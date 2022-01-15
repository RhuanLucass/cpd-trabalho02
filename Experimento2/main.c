#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

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

//AVL
typedef struct avl
{
    int num, altd, alte;
    struct avl *esq, *dir;
}avl;

avl* rotacao_esquerda(avl* aux)
{
	avl *aux1, *aux2;
	aux1 = aux->dir;
	aux2 = aux1->esq;
	aux->dir = aux2;
	aux1->esq = aux;
	if(aux->dir == NULL)
	{
		aux->altd = 0;
	}
	else if(aux->dir->alte > aux->dir->altd)
	{
		aux->altd = aux->dir->alte+1;
	}
	else
	{
		aux->altd = aux->dir->altd+1;
	}
	if(aux1->esq->alte > aux1->esq->altd)
	{
		aux1->alte = aux1->esq->alte + 1;
	}
	else
	{
		aux1->alte = aux1->esq->altd + 1;
	}
	return aux1;
}

avl* rotacao_direita(avl* aux)
{
	avl *aux1, *aux2;
	aux1 = aux->esq;
	aux2 = aux1->dir;
	aux->esq = aux2;
	aux1->dir = aux;
	if(aux->esq == NULL)
	{
		aux->alte = 0;
	}
	else if(aux->esq->alte > aux->esq->altd)
	{
		aux->alte = aux->esq->alte+1;
	}
	else
	{
		aux->alte = aux->esq->altd+1;
	}
	if(aux1->dir->alte > aux1->dir->altd)
	{
		aux1->altd = aux1->dir->alte + 1;
	}
	else
	{
		aux1->altd = aux1->dir->altd + 1;
	}
	return aux1;
}

avl* balanceamento (avl *aux)
{
	int d, df;
	d = aux->altd - aux->alte;
	if(d == 2)
	{
		df = aux->dir->altd - aux->dir->alte;
		if(df>=0)
		{
			aux = rotacao_esquerda(aux);
		}
		else
		{
			aux->dir = rotacao_direita(aux->dir);
			aux = rotacao_esquerda(aux);
		}

	}
	else if(d == -2)
	{
		df = aux->esq->altd - aux->esq->alte;
		if(df <= 0)
		{
			aux = rotacao_direita(aux);
		}
		else
		{
			aux->esq = rotacao_esquerda(aux->esq);
			aux = rotacao_direita(aux);
		}

	}
	return aux;
}

avl * inserir_avl(avl* aux, int num)
{
    avl *novo;
	if(aux == NULL)
    {
		novo = malloc(sizeof(avl));
        novo->num = num;
        novo->altd = 0;
        novo->alte = 0;
		novo->esq = NULL;
		novo->dir = NULL;
		aux = novo;
    }
    else if(num < aux->num)
    {
        aux->esq = inserir_avl(aux->esq, num);
		if(aux->esq->altd > aux->esq->alte)
		{
			aux->alte = aux->esq->altd + 1;
		}
		else
		{
			aux->alte = aux->esq->alte + 1;
		}
		aux = balanceamento(aux);
    }
    else
    {
        aux->dir = inserir_avl(aux->dir, num);
		if(aux->dir->altd > aux->dir->alte)
		{
			aux->altd = aux->dir->altd + 1;
		}
		else
		{
			aux->altd = aux->dir->alte + 1;
		}
		aux = balanceamento(aux);
    }
    return aux;
}

int consultar_avl(avl * aux, int num, int achou)
{
    if(aux != NULL && achou == 0)
    {
        if(aux->num == num)
        {
            achou = 1;
        }
        else if(num < aux->num)
        {
            achou = consultar_avl(aux->esq, num, achou);
        }
        else
        {
            achou = consultar_avl(aux->dir, num, achou);
        }
    }
    return achou;
}

struct avl * remover_avl(avl * aux, int num)
{
    avl *p, *p2;
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
        aux->dir = remover_avl(aux->dir, num);
    }
    else
    {
        aux->esq = remover_avl(aux->esq, num);
    }
    return aux;
}

struct avl * atualiza(avl *aux)
{
	if(aux != NULL)
	{
		aux->esq = atualiza(aux->esq);
		if(aux->esq == NULL)
		{
			aux->alte = 0;
		}
		else if(aux->esq->alte > aux->esq->altd)
		{
			aux->alte = aux->esq->alte + 1;
		}
		else
		{
			aux->alte = aux->esq->altd + 1;
		}
		aux->dir = atualiza(aux->dir);

		if(aux->dir == NULL)
		{
			aux->altd = 0;
		}
		else if (aux->dir->alte > aux->dir->altd)
		{
			aux->altd = aux->dir->alte + 1;
		}
		else
		{
			aux->altd = aux->dir->altd + 1;
		}
		aux = balanceamento(aux);
	}
	return aux;
}

avl* desalocar(avl* aux)
{
	if(aux != NULL)
	{
		aux->esq = desalocar(aux->esq);
		aux->dir = desalocar(aux->dir);
		free (aux);
	}
	return NULL;
}

void preencherVetor(int vet[], int tam_vet)
{
    for (int i = 0; i < tam_vet; i++)
    {
        vet[i] = rand() % 10000;
    }
}

int main() {
    avl *raiz_avl = NULL;
    int n=10000, vet[10000];
	arvore *raiz = NULL;
    double time_spent;
    int op, achou;
    printf("Escolha um algoritmo! Digite 1 para ABB, 2 para AVL ou caso nao queira nenhum, digite 0 para sair\n");
    scanf("%d", &op);
    if(op < 0 || op > 2)
    {
        printf("Opcao invalida!\n");
    }
    else
    {
		for(int i=0; i<n; i++)
        {
            preencherVetor(vet, n);
            //printf("%d ", vet[i]);
        }
		if(op == 1)
        {
			clock_t begin = clock();
			for (int i = 0; i < n; i++)
			{
				raiz = inserir(raiz, vet[i]);
				//printf("%d ", raiz->num);
			}
			clock_t end = clock();
            time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
            printf("Tempo de insercao: %lf s\n", time_spent);


			clock_t begin2 = clock();
			for(int i = 0; i < n; i++)
			{
				achou = 0;
				achou = consultar(raiz, vet[i], achou);
				/*if(achou == 0)
				{
					printf("Numero nao encontrado na arvore\n");
				}
				else
				{
					printf("Numero encontrado na arvore!\n");
				}*/
			}
			clock_t end2 = clock();
            time_spent = (double) (end2 - begin2) / CLOCKS_PER_SEC;
            printf("Tempo de busca: %lf s\n", time_spent);

			clock_t begin3 = clock();
			for(int i = 0; i < n; i++)
			{
				achou = 0;
				achou = consultar(raiz, vet[i], achou);
				if(achou == 0)
				{
					//printf("Numero nao encontrado na arvore\n");
				}
				else
				{
					raiz = remover(raiz, vet[i]);
					//printf("Numero excluido da arvore!\n");
				}
			}
			clock_t end3 = clock();
            time_spent = (double) (end3 - begin3) / CLOCKS_PER_SEC;
            printf("Tempo de remocao: %lf s\n", time_spent);
		}

		else if(op == 2)
        {
			clock_t begin4 = clock();
			for (int i = 0; i < n; i++)
			{
				raiz_avl = inserir_avl(raiz_avl, vet[i]);
				//printf("%d ", raiz->num);
			}
			clock_t end4 = clock();
            time_spent = (double) (end4 - begin4) / CLOCKS_PER_SEC;
            printf("Tempo de insercao: %lf s\n", time_spent);

			clock_t begin5 = clock();
			for(int i = 0; i < n; i++)
			{
				achou = 0;
				achou = consultar_avl(raiz_avl, vet[i], achou);
				/*if(achou == 0)
				{
					printf("Numero nao encontrado na arvore\n");
				}
				else
				{
					printf("Numero encontrado na arvore!\n");
				}*/
			}
			clock_t end5 = clock();
            time_spent = (double) (end5 - begin5) / CLOCKS_PER_SEC;
            printf("Tempo de busca: %lf s\n", time_spent);

			clock_t begin6 = clock();
			for(int i = 0; i < n; i++)
			{
				achou = 0;
				achou = consultar_avl(raiz_avl, vet[i], achou);
				if(achou == 0)
				{
					//printf("Numero nao encontrado na arvore\n");
				}
				else
				{
					raiz_avl = remover_avl(raiz_avl, vet[i]);
					//printf("Numero excluido da arvore!\n");
				}
			}
			clock_t end6 = clock();
            time_spent = (double) (end6 - begin6) / CLOCKS_PER_SEC;
            printf("Tempo de remocao: %lf s\n", time_spent);
		}

	}
    return 0;
}

