/*
Implemente uma pilha na qual cada item seja um número variável de inteiros. 
Escolha uma estrutura de dados em C para essa pilha e elabore rotinas push e pop para ela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodeLista {
	int numero;
	struct nodeLista *next;
};

struct nodePilha {
	struct lista *alista;
	struct nodePilha *next;
};

struct pilha {
	struct nodePilha *topo;	
};

struct lista {
	struct nodeLista *head;
};

struct lista criaLista ();

struct lista popPilha (struct pilha *apilha);

void iniciaPilha (struct pilha *apilha);

void pushPilha (struct pilha *apilha);

void printLista (struct lista *alista);

int main(void)
{
	char acao[10];
	struct pilha *apilha;
	apilha = (struct pilha*) malloc(sizeof(struct pilha));
	iniciaPilha (apilha);

	while (scanf("%s", acao) != EOF) {
		// printf("while\n\n");

		if (strcmp(acao, "PUSH") == 0) {
			// printf("opcao1\n");
			pushPilha(apilha);

		} else if (strcmp(acao, "POP") == 0) {
			// printf("opcao2\n");
			popPilha(apilha);
		}
	}

}

struct lista criaLista ()
{
	// printf("crialista\n");
	int numero;
	struct nodeLista *novo;
	struct lista *alista;

	novo = (struct nodeLista*) malloc(sizeof(struct nodeLista));
	alista = (struct lista*) malloc(sizeof(struct lista));

	alista->head = NULL;

	do {
		scanf("%d", &numero);
		novo->numero = numero;


		if (numero) {
			if (alista->head == NULL) {
				alista->head = novo;
				novo->next = NULL;
			} else {
				novo->next = alista->head;
				alista->head = novo->next;
			}
		} else break;

	} while (strcmp((char)numero, NULL) != 0);

	return *alista;

}

void iniciaPilha (struct pilha *apilha) {

	apilha->topo = NULL;
}

void pushPilha (struct pilha *apilha) {
	// printf("push\n");

	struct lista *novaLista;
	struct nodePilha *novo;

	novo = (struct nodePilha*) malloc(sizeof(struct nodePilha));
	*novaLista = criaLista();

	novo->alista = novaLista;
	novo->next = apilha->topo;
	apilha->topo = novo;
}

struct lista popPilha (struct pilha *apilha) {
	struct nodePilha *temp;
	// printf("pop\n");

	if (apilha->topo != NULL) {
		temp = apilha->topo;
		apilha->topo = apilha->topo->next;

		printLista(temp->alista);

	} else 
		printf("EMPTY STACK\n");
	
}

void printLista (struct lista *alista) {
	// printf("print\n");
	struct nodeLista *no;

	if (alista->head != NULL) {
		no = alista->head;

		while (no != NULL) {
			printf("%d", no->numero);
			
			if (no->next == NULL)
				printf("\n");
			else
				printf(" ");
		

			no = no->next;
		}
	} else 
		printf("EMPTY STACK\n");
}