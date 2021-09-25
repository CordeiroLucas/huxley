/*
Imagine uma fila de pessoas esperando para serem atendidas, com prioridade para pessoas idosas (acima de 60 anos). Assim, as pessoas se dividem em duas filas
 distintas, uma para pessoas idosas e outra para não idosas. Sempre que houver disponibilidade para uma nova pessoa ser atendida, uma pessoa deve ser removida
 de uma das filas, de acordo com as seguintes regras:

Caso 'n' pessoas da fila de idosos sejam atendidas de forma consecutiva enquanto existir alguém na fila de não-idosos, a próxima pessoa a ser atendida será a
 que está na fila de não-idosos, e a contagem de atendimentos da fila de idosos é reiniciada (mais 'n' idosos podem ser atendidos em sequência novamente, mesmo
 se existir alguém aguardando na fila de não-idosos). o valor de 'n' deve ser informado como uma das entradas do problema;

Caso não exista ninguém na fila de idosos, o próximo a ser atendido é alguém da fila de não-idosos, e a contagem de idosos atendidos em sequência é zerada;

Caso não exista ninguém na fila de não-idosos, o próximo a ser atendido é alguém da fila de idosos, e a contagem de idosos atendidos em sequência é zerada;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int id;
	int idade;
	struct node *next;
};

struct fila {
	struct node *head;
	struct node *tail;
	int tamanho;
};

void inicializarFila (struct fila *pessoas);
void adicionarFila (struct fila *fila_idosos, struct fila *fila_n_idosos, int id, int idade);
void removerFila (struct fila *pessoas, int nPrioridade);
void imprimirFilas (struct fila *fila_idosos, struct fila *fila_n_idosos);

int main(void) 
{
	struct fila *fila_idosos;
	struct fila *fila_n_idosos;

	fila_idosos = (struct fila*) malloc(sizeof(struct fila));
	fila_n_idosos = (struct fila*) malloc(sizeof(struct fila));

	inicializarFila (fila_idosos);
	inicializarFila (fila_n_idosos);

	int nPrioridade, seqAtendimento, id, idade;
	char *opcao;

	scanf("%d", &nPrioridade);

	strcpy (opcao, "p");

	while (strcmp(opcao, "f") != 0) {
		scanf("%c", opcao);
		
		if (strcmp(opcao, "a") == 0) {
			scanf("%d %d", &id, &idade);

			/*função adicionar na fila*/
			adicionarFila (fila_idosos, fila_n_idosos, id, idade);

		} else if (strcmp(opcao, "r") == 0) {
		
			/*função remover seguindo a ordem de preferência*/
		} else if (strcmp(opcao, "i") == 0 ) {
			
			/*função imprimir as duas filas*/
			imprimirFilas (fila_idosos, fila_n_idosos);
		}else if (strcmp(opcao, "f") == 0) {
			/*finaliza*/
			return 0;
		}
	}
	

	return 0;
}

void inicializarFila (struct fila *pessoas) 
{
	pessoas->head = NULL;
	pessoas->tail = NULL;
	pessoas->tamanho = 0;
}

void adicionarFila (struct fila *fila_idosos, struct fila *fila_n_idosos, int id, int idade) 
{
	struct node *pessoa;
	pessoa = (struct node*) malloc(sizeof(struct node));

	pessoa->id = id;
	pessoa->idade = idade;
	pessoa->next = NULL;

	if (idade > 60) {
		if (fila_idosos->head == NULL) {
			fila_idosos->head = pessoa;
			fila_idosos->tail = pessoa;
			fila_idosos->tamanho++;
		} else {
			fila_idosos->tail->next = pessoa;
			fila_idosos->tail = pessoa;
			fila_idosos->tamanho++;
		}
		
	} else {
		if (fila_n_idosos->head == NULL) {
			fila_n_idosos->head = pessoa;
			fila_n_idosos->tail = pessoa;
			fila_n_idosos->tamanho++;
		} else {
			fila_n_idosos->tail->next = pessoa;
			fila_n_idosos->tail = pessoa;
			fila_n_idosos->tamanho++;
		}
	}

}

void imprimirFilas (struct fila *fila_idosos, struct fila *fila_n_idosos)
{	
	struct node *pessoa;
	pessoa = (struct node*) malloc(sizeof(struct node));

	
	printf("\n%d na fila de idosos:\n", fila_idosos->tamanho);
	if (fila_idosos != NULL) {
		pessoa = fila_idosos->head;

		while (pessoa != NULL) {
			printf("ID: %d IDADE: %d\n", pessoa->id, pessoa->idade);
			pessoa = pessoa->next;
		}
	} else {
		printf("fila vazia!\n");
	}
	
	
	printf("%d na fila de não-idosos:\n", fila_n_idosos->tamanho);
	if (fila_n_idosos != NULL) {
		pessoa = fila_n_idosos->head;

		while (pessoa != NULL) {
			printf("ID: %d IDADE: %d\n", pessoa->id, pessoa->idade);
			pessoa = pessoa->next;
		}
	} else {
		printf("fila vazia!\n");
	}

	printf("----------\n");
}
