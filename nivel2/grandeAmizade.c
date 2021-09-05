typedef struct dadoAmigo {
	char nome[30];
	int idade;
	struct dadoAmigo *next;
}dadoAmigo;

typedef struct lista {
	dadoAmigo *head;
	int tamanho;
}lista;

void inicializa(lista *alista)
{
	lista *alista = (*alista) malloc(sizeof(lista *alista));
}

int main(void)
{

}