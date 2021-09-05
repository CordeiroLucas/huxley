typedef struct dadoAmigo {
	char nome[30];
	int idade;
	struct dadoAmigo *next;
}dadoAmigo;

typedef struct lista {
	dadoAmigo *head;
	int tamanho;
}lista;

/*
NÃO TERMINEI AINDA

Obs.: Tô achando essa muito confusa, então vou terminar logo a "huxley/nivel3/l4q4xadrez.c"
	para tentar terminar essa daqui. (A do xadrez é uma da faculdade e tem um prazo)

Obs2: Assim como está escrito no readme.me, esse código tem o mesmo nome da questão no The Huxley.
*/

void inicializa(lista *alista)
{
	alista = (lista*) malloc(sizeof(lista));


	return 0;
}

int main(void)
{



	return 0;
}