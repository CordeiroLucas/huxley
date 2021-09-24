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

int main(void) 
{
	struct fila *idoso;
	struct fila *nIdoso;

	idoso = (struct fila*) malloc(sizeof(struct fila));
	nIdoso = (struct fila*) malloc(sizeof(struct fila));

	int nPrioridade, seqAtendimento, id, idade;
	char opcao;

	scanf("%d", &nPrioridade);

	opcao = ' ';

	while (strcmp(opcao, 'f') != 0) {
		scanf("%c", &opcao);
		
		if (strcmp(opcao, 'a') == 0) {
			scanf("%d %d", &id, &idade);

			/*função adicionar na fila*/
		} else if (strcmp(opcao, 'r') == 0) {
			scanf("%d %d", &id, &idade);

			/*função remover seguindo a ordem de preferência*/
		} else if (strcmp(opcao, 'i') == 0 ) {
			
			/*função imprimir as duas filas*/

			imprimirFilas (idoso, nIdoso);
		}else {
			/*finaliza*/
			return 0;
		}
	}
	

	return 0;
}

void imprimirFilas (struct fila *idosos, struct fila *nIdosos)
{	
	struct node *pessoa;
	pessoa = (struct node*) malloc(sizeof(struct node));

	
	printf("\nfila de idosos:\n");
	if (idosos != NULL) {
		pessoa = idosos->head;

		while (pessoa != NULL) {
			printf("ID: %d IDADE: %d\n", pessoa->id, pessoa->idade);
			pessoa = pessoa->next;
		}
	} else {
		printf("fila vazia!\n");
	}
	
	
	printf("fila de não-idosos:\n");
	if (nIdosos != NULL) {
		pessoa = nIdosos->head;

		while (pessoa != NULL) {
			printf("ID: %d IDADE: %d\n", pessoa->id, pessoa->idade);
			pessoa = pessoa->next;
		}
	} else {
		printf("fila vazia!\n");
	}

	printf("----------\n");
}
