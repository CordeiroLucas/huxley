/*

QUESTÃO Lista de Compras

Os monitores de Introdução a Programação tentando fazer a comemoração de fim de ano, começaram a fazer a
 lista de itens que eles comprariam pra a festa pra ter uma ideia de quanto iriam gastar.

O problema é que como o grupo era muito grande, ficava muito difícil de operar a lista porque várias pessoas 
 estavam constantemente inserindo novos itens e removendo, então eles decidiram pedir sua ajuda para que 
 conseguissem computar direitinho o preço total da festa.

Você precisa criar um programa que aceite os seguintes comandos:

INSERIR NOME VALOR QUANTIDADE - insere um novo produto com o Nome, Valor de compra e Quantidade de itens
REMOVER NOME QUANTIDADE - remove uma determinada quantidade de itens (ou todos) de um produto pelo Nome
REMOVERGRUPO VALOR -  remove todos os produtos que tem seu valor total (por item) maiior que VALOR
CONSULTAR - consulta o preço total da Lista até o momento
PROCURAR NOME - procura se o produto de Nome está na lista e retorna seu Nome, Valor e Quantidade de itens
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 40

typedef struct item {
	char nome[TAM];
	float preco;
	int quantidade;
	float totalItem;
	struct item *next;
}item;

typedef struct lista {
	item *head;
	item *tail;
	float totalLista;
}lista;

void init (lista *alista);
float atualizarPrecoLista (lista *alista);
void printItensLista (lista *alista);
void procurarNome (lista *alista, char nomeItem[TAM]);
void inserirItem (lista *alista, char nomeItem[TAM], float valor, int quatidade);
void removerItem (lista *alista, char nomeItem[TAM], int quantidade);
void removerGrupo (lista *alista, float valor);

int main(void)
{
	int quantidade;
	char nomeItem[TAM], selecao[20];
	float valor;

	lista *alista;
	alista = (lista*) malloc(sizeof(lista));

	init(alista);

	while (1) {
		scanf("%s", selecao);

		if (strcmp(selecao, "INSERIR") == 0) {
			scanf("%s %f %d", nomeItem, &valor, &quantidade);
		
			inserirItem (alista, nomeItem, valor, quantidade);

		} else if (strcmp(selecao, "REMOVER") == 0) {
			scanf("%s %d", nomeItem, &quantidade);
		
			removerItem (alista, nomeItem, quantidade);
			atualizarPrecoLista(alista);

		} else if (strcmp(selecao, "REMOVERGRUPO") == 0) {
			scanf("%f", &valor);

			removerGrupo(alista, valor);

		} else if (strcmp(selecao, "CONSULTAR") == 0) {
			atualizarPrecoLista(alista);
			printf("\nAtualmente a lista esta em R$%.2f\n", alista->totalLista);

 		} else if (strcmp(selecao, "PROCURAR") == 0) {
			scanf("%s", nomeItem);

			procurarNome(alista, nomeItem);

		} else if (strcmp(selecao, "ITENS") == 0) {
			printItensLista(alista);

		} else if (strcmp(selecao, "SAIR") == 0) 
			break;
	}
	return 0;
}

float atualizarPrecoLista (lista *alista)
{
	item *node;
	node = (item*) malloc(sizeof(item));
	alista->totalLista = 0;

	if (alista != NULL) {
		for (node=alista->head; node!=NULL; node=node->next)
			alista->totalLista = alista->totalLista + node->totalItem;
	}

}


void init (lista *alista) 
{	
	alista->head = NULL;
	alista->tail = NULL;
	alista->totalLista = 0;
}

void printItensLista (lista *alista)
{
	item *node;
	node = (item*) malloc(sizeof(item));

	if (alista != NULL) {
		for (node=alista->head; node!=NULL; node=node->next)
			printf("|NOME: %s UN: R$%.2f | QUANT.: %d | TOTAL: R$%.2f|\n", node->nome, node->preco, node->quantidade, node->totalItem);
	}

}

void procurarNome (lista *alista, char nomeItem[TAM]) 
{
	item *node;
	node = (item*) malloc(sizeof(item));

	if (alista->head != NULL) {
		for (node=alista->head; node!=NULL; node=node->next) {
			if (strcmp(nomeItem, node->nome) == 0) {
				printf("- R$%.2f\n- %d\n", node->preco, node->quantidade);
				return;
			} else 
				continue;
		}

		printf("%s nao foi encontrado.\n", nomeItem);
	} else 
		printf("Lista Vazia!!\n");
}

void inserirItem (lista *alista, char nomeItem[TAM], float valor, int quantidade)
{	
	item *novo = (item*) malloc(sizeof(item));
	item *node = (item*) malloc(sizeof(item));

	strcpy(novo->nome, nomeItem);
	if (quantidade > 0 && quantidade < 10000 && valor > 0.001) {
		novo->preco = valor;
		novo->quantidade = quantidade;
		novo->totalItem = novo->preco * novo->quantidade;

		if (alista != NULL) {
			if (alista->head == NULL) {
				alista->head = novo;
				alista->tail = novo;
				alista->totalLista = alista->totalLista + novo->totalItem;

			} else {
				alista->tail->next = novo;
				alista->tail = novo;
				novo->next = NULL;
				alista->totalLista = alista->totalLista + novo->totalItem;

			}
			
		} else
			printf("EMPTY STACK!!\n");
	}
}

void removerGrupo (lista *alista, float valor) 
{
	item *node;
	node = (item*) malloc(sizeof(item));

	for (node = alista->head; node->next != NULL; node = node->next) {
		if (node->preco < valor)
			removerItem (alista, node->nome, node->quantidade);
		else 
			continue;
	}
}

// void removerItem1 (lista *alista, char nomeItem[TAM], int quantidade) 
// {
// 	item *node, *temp;
// 	node = (item*) malloc(sizeof(item));
// 	temp = (item*) malloc(sizeof(item));

// 	if (alista->head != NULL) {
// 		for (node = alista->head; node->next != NULL; node = node->next) {

// 			if (strcmp(node->next->nome, nomeItem) == 0) {
// 				/*
// 				Para itens que não estão no head
// 				*/
// 				if (node->next->quantidade > quantidade) { 
// 					node->next->quantidade = node->next->quantidade - quantidade;
// 					node->next->totalItem = node->next->quantidade * node->next->preco;
// 					break;

// 				} else {
// 					temp = node->next->next;
// 					node->next = temp;
// 					break;
// 				}

// 			} else if (strcmp(alista->head->nome, nomeItem) == 0) {
// 				/*
// 				Para itens que estão no head
// 				*/
// 				if (node->quantidade > quantidade) {
// 					node->quantidade = node->quantidade - quantidade;
// 					node->totalItem = node->quantidade * node->preco;

// 					break;

// 				} else {
// 					if (node->next != NULL && alista->head == node) {
// 						alista->totalLista = alista->totalLista - node->totalItem;
// 						alista->head = node->next;
						
// 						break;
// 					}
// 					alista->totalLista = 0;
// 					alista->head = NULL;
// 					alista->tail = NULL;
// 				}
// 			} else 
// 				continue;
// 		}
// 	} else 
// 		printf("Lista Vazia!!\n");
// }

void removerItem (lista *alista, char nomeItem[TAM], int quantidade)
{
	item *node;
	node = (item*) malloc(sizeof(item));

	if (alista->head != NULL) {
		for (node = alista->head;node->next != NULL; node = node->next) {
			if (strcmp(node->nome, alista->head->nome) == 0) {
				if (quantidade >= node->quantidade) {
					node->totalItem = 0;
					alista->head = node->next;
					free(node);
					break;
				} else {
					node->quantidade = node->quantidade - quantidade;
					node->totalItem = node->quantidade * node->preco;
					break;
				}
			} else {
				if (strcmp(node->next->nome, nomeItem) == 0) {
					if (quantidade >= node->next->quantidade) {
						node->next->totalItem = 0;
						node->next = node->next->next;
						break;
					} else {
						node->next->quantidade = node->next->quantidade - quantidade;
						node->totalItem = node->next->quantidade * node->next->preco;
						break;
					}
				} else 
					continue;
			}
		}
	}
}