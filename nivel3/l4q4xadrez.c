/*
QUESTÃO:

José Gabriel é um estudante que gosta muito de aprender coisas novas, e a sua mais nova empreitada é aprender a jogar xadrez. Mas tudo ainda está um pouco confuso
para ele, pois apesar de entender muito bem como cada peça pode se movimentar, ele ainda tem muita dificuldade para perceber se o jogo está em uma situação de 
xeque (Situação quando o seu rei está sendo atacado por alguma peça do seu inimigo).Sua missão então é elaborar um programa que, dada a configuração atual das 
peças no tabuleiro, diga se o rei de José Gabriel está em xeque.
*/



#include <stdio.h>
#include <string.h>

/*DEFINIR TAMANHO MATRIZ XADREZ*/
#define X 8
#define Y 8


/*
AINDA NÃO CONCLUIDO
*/

typedef struct dadosPosicao {
	int tipo;
	int isDeJose;
	int isRei;
	int isValid;
}dadosPosicao;

int isValid (int x, int y, dadosPosicao aPeca[X][Y]);
int tipoPeca (int x, int y, dadosPosicao aPeca[X][Y]);
int cheque_torre (int x, int y, dadosPosicao aPeca[X][Y]);
int isCheque (int x, int y, dadosPosicao aPeca[X][Y]);

int main(void) 
{
	dadosPosicao peca[X][Y];
	int i, j, pecaValida;
	
	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			pecaValida = 0;
			while (pecaValida == 0) {
				peca[i][j].tipo = getchar();
				
				if (isValid(i, j, peca))  {
					pecaValida = 1;
					break;
				} else 
					continue;
			}
		}
	}

	/*
	ESSA SÉRIE DE PRINTS É PARA CHECAGEM SE O CÓDIGO ESTÁ
	FUNCIONANDO E RECONHECENDO CORRETAMENTE CADA POSIÇÃO
	*/

	/*
	printf("\n\n\nÉ PEÇA?\n");

	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			if (peca[i][j].isValid == 1)
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}
	
	printf("\n\n\nÉ REI?\n");

	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			if (peca[i][j].isRei == 1) 
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}

	printf("\n\n\nÉ DE JOSÉ?\n");

	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {
			if (peca[i][j].isDeJose == 1) 
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}

	printf("\n\n\nTIPO PEÇA\n");

	for (i = 0; i < X; i++) {
		for (j = 0; j < Y; j++) {

			if (peca[i][j].isDeJose == 1 && peca[i][j].isValid == 1) 
				printf("J");

			else if (peca[i][j].isDeJose == 0 && peca[i][j].isValid == 1)
				printf("Ñ");
			
			if (tipoPeca(i, j, peca) == 0) 
				printf("KG");

			else if (tipoPeca(i, j, peca) == 1)
				printf("PE");

			else if (tipoPeca(i, j, peca) == 2)
				printf("TR");

			else if (tipoPeca(i, j, peca) == 3)
				printf("CV");

			else if (tipoPeca(i, j, peca) == 4)
				printf("BP");

			else if (tipoPeca(i, j, peca) == 5)
				printf("QN");

			else
				printf("   ");

			printf(" ");
		}
		printf(" \n");
	}
	*/

	pecaValida = 0;
	for (i = 0; i < X; i++){
		for (j = 0; j < Y; j++){
			if (peca[i][j].isRei == 1 && peca[i][j].isDeJose == 1) {
				pecaValida = 1; 
				break;
			} else 
				continue;
		}

		if (pecaValida) 
			break;
		else
			continue;
	}
	
	if (isCheque(i, j, peca))
		printf("CHEQUE!!\n");
	else 
		printf("Ñ E CHEQUE!!\n");

	return 0;
}


/*
Função "isValid" checa se certa posição na matriz[X][Y] é uma peça válida;
Também atualiza o dados "isRei" e se ela é de José "isDeJose";
Caso ela não encontre uma peça válida, ela coloca os dados como "0" sendo assim, uma posição sem peça;
O else é para caso ele receba qualquer outro caracter que não seja os do Xadrez.
*/

int isValid (int x, int y, dadosPosicao aPeca[X][Y]) 
{
	/* MAIÚSCULO */
	if (aPeca[x][y].tipo > 64 && aPeca[x][y].tipo < 91) {
		aPeca[x][y].isDeJose = 1;
		aPeca[x][y].isValid = 1;

		if (aPeca[x][y].tipo == 75)
			aPeca[x][y].isRei = 1;
		else
			aPeca[x][y].isRei = 0;

		return 1;

	/* MINÚSCULO */
	} else if (aPeca[x][y].tipo > 96 && aPeca[x][y].tipo < 123) {
		aPeca[x][y].isDeJose = 0;
		aPeca[x][y].isValid = 1;

		if (aPeca[x][y].tipo == 107)
			aPeca[x][y].isRei = 1;
		else 
			aPeca[x][y].isRei = 0;
	
		return 1;

	/* CHAR == '-' */
	} else if (aPeca[x][y].tipo == 45) {
		aPeca[x][y].isDeJose = 0;
		aPeca[x][y].isRei = 0;
		aPeca[x][y].isValid = 0;
		
		return 1;

	/* CHAR VAZIO OU INVÁLIDO */
	} else  
		return 0;
}

/*

A função "tipoPeca" terá como retorno as seguintes peças:

'-' -> vazio -> Tipo -1

K/k -> King -> Tipo 0
P/p -> Peão -> Tipo 1
T/t -> Torre -> Tipo 2
C/c -> Cavalo -> Tipo 3
B/b -> Bispo -> Tipo 4
Q/q -> Rainha -> Tipo 5

*/

int tipoPeca (int x, int y, dadosPosicao aPeca[X][Y]) 
{
	if (aPeca[x][y].isRei == 1)
		return 0;

	else if (aPeca[x][y].tipo == 80 || aPeca[x][y].tipo == 112)
		return 1;

	else if (aPeca[x][y].tipo == 84 || aPeca[x][y].tipo == 116)
		return 2;

	else if (aPeca[x][y].tipo == 67 || aPeca[x][y].tipo == 99)
		return 3;

	else if (aPeca[x][y].tipo == 66 || aPeca[x][y].tipo == 98)
		return 4;

	else if (aPeca[x][y].tipo == 81 || aPeca[x][y].tipo == 113)
		return 5;

	else
		return -1;
}




/*
Ainda não concluídas...
*/

int cheque_torre (int x, int y, dadosPosicao aPeca[X][Y])
{
	int i, j;

	for (i=x;i<X;i++) {
		if ((tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
			return 1;
		else if (tipoPeca(i, y, aPeca) == -1)
			continue;
	}
	
	for (j=y;j<Y;j++) {
		if ((tipoPeca(x, j, aPeca) == 2 || tipoPeca(x, j, aPeca) == 5) && (aPeca[x][j].isDeJose != aPeca[x][y].isDeJose))
			return 1;
		else if (tipoPeca(x, j, aPeca) == -1)
			continue;
	}

	for (i=x;i>=0;i--) {
		if ((tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
			return 1;
		else if (tipoPeca(i, y, aPeca) == -1)
			continue;
	}

	for (j=y;j>=0;j--) {
		if ((tipoPeca(x, j, aPeca) == 2 || tipoPeca(x, j, aPeca) == 5) && (aPeca[x][j].isDeJose != aPeca[x][y].isDeJose))
			return 1;
		else if (tipoPeca(x, j, aPeca) == -1)
			continue;
	}

	return 0;	
}

int cheque_bispo (int x, int y, dadosPosicao apeca[X][Y])
{
	return 0;
}

/*
void visao_bispo (int x, int y, dadosPosicao aPeca[X][Y])
{
	int i, j;

	for (i=x; i<X; i++) {
		return 0;
	}
}

void visao_cavalo (int x, int y, dadosPosicao aPeca[X][Y])
{
	int i, j;

	for (i=x; i<X; i++) {
		return 0;
	}
}

void visao_peao (int x, int y, dadosPosicao aPeca[X][Y])
{
	int i, j;

	for (i=x; i<X; i++) {
		return 0;
	}
}

void visao_king (int x, int y, dadosPosicao aPeca[X][Y])
{
	int i, j;

	for (i=x; i<X; i++) {
		return 0;
	}
}
*/

int isCheque (int x, int y, dadosPosicao aPeca[X][Y]) 
{	
	if (cheque_torre(x, y, aPeca) == 1)  
		return 1;
	else 
		return 0;
}