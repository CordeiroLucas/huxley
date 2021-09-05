#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int valor;
	struct pilha *next;
};

struct pilha {
	struct node *topo;
	int tamanho;
	int maior, menor;
};

struct pilha *criapilha(void)
{
	struct pilha *apilha;

	apilha = (struct pilha *)malloc(sizeof(struct pilha));

	apilha->topo = NULL;
	apilha->tamanho = 0;

	apilha->menor = 0;
	apilha->maior = 0;

	return apilha;
};

int maior_menor(struct pilha *apilha)
{
	struct node *atual;
	int maior_n = 1000, menor_n = 0, check = 1, i = 1;

	atual = apilha->topo;

	if (apilha->tamanho > 0) {
		while (atual) {
			if (atual->valor >= menor_n && atual->valor < maior_n) {
				if (i == 1) {
					apilha->maior = atual->valor;
					apilha->menor = atual->valor;
					i--;
				}

				if (apilha->maior < atual->valor) {
					apilha->maior = atual->valor;

				} else if (apilha->menor > atual->valor) {
					apilha->menor = atual->valor;
				}
			}
			atual = atual->next;
		}

		printf("%d\n", apilha->maior - apilha->menor);
		free(atual);
	} else {
		printf("EMPTY STACK\n");
		return 0;
	}
}

void push(struct pilha *apilha, int numero)
{
	//DECLARAR
	struct node *novoelemento;
	//ALOCAR
	novoelemento = (struct node *)malloc(sizeof(struct node));
	//GUARDAR
	if (numero >= 0 && numero <= 1000) {
		if (!novoelemento) {
			printf("ERRO DE ALOCA��O\n");
		} else {
			novoelemento->valor = numero;
			novoelemento->next = apilha->topo;

			apilha->topo = novoelemento;
			apilha->tamanho = apilha->tamanho + 1;
		}
	}
}

void pop(struct pilha *apilha)
{
	struct node *aux = NULL;
	int valorRetorno;

	if (apilha->topo) {
		aux = apilha->topo;
		valorRetorno = aux->valor;

		apilha->topo = aux->next;
		apilha->tamanho = apilha->tamanho - 1;

		printf("%d\n", valorRetorno);
	} else {
		printf("EMPTY STACK\n");
	}
}

int main(void)
{
	struct pilha *apilha = criapilha();

	char entrada[4];

	int valor, condicaoParada = 1;

	while (scanf("%s", entrada) != EOF) {
		if (strcmp(entrada, "push") == 0) {
			scanf("%d", &valor);
			push(apilha, valor);

		} else if (strcmp(entrada, "pop") == 0) {
			pop(apilha);
			
		} else if (strcmp(entrada, "abs") == 0) {
			maior_menor(apilha);
			
		} else if (strcmp(entrada, "-1") == 0) {
			break;
		}
	}
	return 0;
}
