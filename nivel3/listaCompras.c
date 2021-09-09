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


typedef struct item {
	char nome[20];
	float preco;
	int quantidade;
	float totalItem;
	struct item *next;
}item;

typedef struct lista {
	item *head;
	item *tail;
	int totalLista;
}lista;

void init (lista *alista);
void printTotalLista (lista *alista);
void insere (lista *alista, char nomeItem[20], float valor, int quatidade);

int main(void)
{
	int quantidade;
	char nomeItem[20];
	float valor;

	lista *alista;
	alista = (lista*) malloc(sizeof(lista));

	
	return 0;
}

void insere (lista *alista, char nomeItem[20], float valor, int quantidade)
{	
	item *novo = (item*) malloc(sizeof(item));

	novo->nome[20] = nomeItem;
	novo->preco = valor;
	novo->quantidade = quantidade;
	novo->totalItem = novo->preco * novo->quantidade;
	
	if (alista != NULL) {
		if (alista->head == NULL) {
			alista->head = novo;
			alista->tail = novo;
		}else {
			alista->tail->next = novo;
			alista->tail = novo;
			novo->next = NULL;
		}
		alista->totalLista = alista->totalLista + novo->totalItem;
		
	} else {
		printf("EMPTY STACK!!\n");
	}
}

void init (lista *alista) 
{	
	alista->head = NULL;
	alista->tail = NULL;
	alista->totalLista = 0;
}

void printTotalLista (lista *alista)
{
	item *product = (item*) malloc(sizeof(item));

	for (product = alista->head; product!=NULL; product = product->next) 
		alista->totalLista = product->totalItem + alista->totalLista;

	printf("R$%.2f\n");
}