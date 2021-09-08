#include <stdio.h>
#include <string.h>

/*
ENUNCIADO QUESTAO

José Gabriel é um estudante que gosta muito de aprender coisas novas, e a sua mais nova empreitada é aprender a jogar xadrez.
Mas tudo ainda está um pouco confuso para ele, pois apesar de entender muito bem como cada peça pode se movimentar, ele ainda
tem muita dificuldade para perceber se o jogo está em uma situação de xeque (Situação quando o seu rei está sendo atacado por
 alguma peça do seu inimigo). Sua missão então é elaborar um programa que, dada a configuração atual das peças no tabuleiro,
 diga se o rei de José Gabriel está em xeque.
*/

/*DEFINIR TAMANHO MATRIZ XADREZ*/
#define X 8
#define Y 8


typedef struct dadosPosicao {
	int tipo;
	int isDeJose;
	int isRei;
	int isValid;
}dadosPosicao;

int isValid (int x, int y, dadosPosicao aPeca[X][Y]);
int tipoPeca (int x, int y, dadosPosicao aPeca[X][Y]);
int cheque_torre (int x, int y, dadosPosicao aPeca[X][Y], int check);
int isCheque (int x, int y, dadosPosicao aPeca[X][Y]);
int isChequeRei (int x, int y, dadosPosicao aPeca[X][Y]);

int testando (int x, int y, dadosPosicao aPeca[X][Y], int sentido);

int main(void) 
{
	dadosPosicao peca[X][Y];
	int i, j, pecaValida;

	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
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

	printf("\n\n\n(x, y)\n");

	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
			printf("(%d,%d)", i, j);
			printf(" ");
		}
		printf(" \n");
	}


	
	printf("\n\n\nÉ PEÇA?\n");
	
	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
			if (peca[i][j].isValid == 1)
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}
	
	printf("\n\n\nÉ REI?\n");

	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
			if (peca[i][j].isRei == 1) 
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}

	printf("\n\n\nÉ DE JOSÉ?\n");

	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
			if (peca[i][j].isDeJose == 1) 
				printf("Y");
			else 
				printf("Ñ");

			printf(" ");
		}
		printf(" \n");
	}
	
	printf("\n\n\nTIPO PEÇA\n");

	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {

			if (peca[i][j].isDeJose == 1 && peca[i][j].isValid == 1) 
				printf("João ");
			
			if (tipoPeca(i, j, peca) == 0) 
				printf("KinG");

			else if (tipoPeca(i, j, peca) == 1)
				printf("PeãO");

			else if (tipoPeca(i, j, peca) == 2)
				printf("TorrE");

			else if (tipoPeca(i, j, peca) == 3)
				printf("CavaL");

			else if (tipoPeca(i, j, peca) == 4)
				printf("BisP");

			else if (tipoPeca(i, j, peca) == 5)
				printf("QueN");

			else
				printf("   ");

			printf(" ");
		}
		printf(" \n");
	}
	
	*/

	pecaValida = 0;
	for (j = Y-1; j >= 0 ; j--) {
		for (i = 0; i < X; i++) {
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

retornos tipoPeca:

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

int cheque_torre (int x, int y, dadosPosicao aPeca[X][Y], int check)
{
	int i, j;

	if (check == 1) {
		/*
		Para o x+ (x positivo)
		*/
		
		for (i=x;i<X;i++) {
			if ((tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) != -1)
				return 0;
		}

	} else if (check == 2) {
		/*
		Para o y+ (y positivo)
		*/

		for (j=y;j<Y;j++) {
			if ((tipoPeca(x, j, aPeca) == 2 || tipoPeca(x, j, aPeca) == 5) && (aPeca[x][j].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(x, j, aPeca) != -1)
				return 0;
		}

	} else if (check == 3) {

		/*
		Para o x- (x negativo)
		*/

		for (i=x;i>=0;i--) {
			if ((tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) != -1) {
				return 0;
			}
				
		};

	} else if (check == 4) {

		/*
		Para o y- (y negativo)
		*/

		for (j=y;j>=0;j--) {
			if ((tipoPeca(x, j, aPeca) == 2 || tipoPeca(x, j, aPeca) == 5) && (aPeca[x][j].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(x, j, aPeca) != -1)
				return 0;
		}	
	}		
}

int cheque_bispo (int x, int y, dadosPosicao aPeca[X][Y], int lado)
{
	int i, j;


	if (lado == 1) {
	
		/*
		Para a diagonal x+ e y+ (x positivo, y positivo)
		*/

		for (i=x, j=y;i<X, j<Y;i++, j++) {
			if ((tipoPeca(i, j, aPeca) == 4 || tipoPeca(i, j, aPeca) == 5) && (aPeca[i][j].isDeJose != aPeca[x][j].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) == -1) 
				return 0;
		}

	} else if (lado == 2) {

		/*
		Para a diagonal x+ e y- (x positivo, y negativo)
		*/

		for (i=x, j=y;i<X, j>=0;i++, j--) {
			if ((tipoPeca(i, j, aPeca) == 4 || tipoPeca(i, j, aPeca) == 5) && (aPeca[i][j].isDeJose != aPeca[x][j].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) == -1) 
				return 0;
		}

	} else if (lado == 3) {

		/*
		Para a diagonal x- e y+ (x negativo, y positivo)
		*/

		for (i=x, j=y;i>=0, j<Y;i--, j++) {
			if ((tipoPeca(i, y, aPeca) == 4 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) == -1) 
				return 0;
		}	

	} else if (lado == 4) {
		for (i=x, j=y;i>=0, j>=0;i--, j--) {
			if ((tipoPeca(i, y, aPeca) == 4 || tipoPeca(i, y, aPeca) == 5) && (aPeca[i][y].isDeJose != aPeca[x][y].isDeJose))
				return 1;
			else if (tipoPeca(i, y, aPeca) == -1) 
				return 0;
		}		
	}



	

	/*
	Para a diagonal x- e y- (x negativo, y negativo)
	*/




	return 0;
}

// int isChequeRei (int x, int y, dadosPosicao aPeca[X][Y])
// {
// 	int i, j;

// 	/*
// 	Eu só desisti de fazer algo otimizado, aí aqui ele checa todas as posições ao redor do rei primeiro
// 	*/

// 	if ((tipoPeca(i, j, aPeca) == 5 || tipoPeca(i, j, aPeca) == 2 || tipoPeca(i, j, aPeca) == 0) && aPeca[i][j].isDeJose != aPeca[i][j].isDeJose)
// 		return 1;
// 	else if ((tipoPeca(x+1, y, aPeca) == 5 || tipoPeca(x+1, y, aPeca) == 2 || tipoPeca(x+1, y, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x+1][y].isDeJose)
// 		return 1;
// 	else if ((tipoPeca(x, y-1, aPeca) == 5 || tipoPeca(x, y-1, aPeca) == 2 || tipoPeca(x, y-1, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x][y-1].isDeJose)
// 		return 1;
// 	else if ((tipoPeca(x, y+1, aPeca) == 5 || tipoPeca(x, y+1, aPeca) == 2 || tipoPeca(x, y+1, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x][y+1].isDeJose)
// 		return 1;
// 	else if ((tipoPeca(x-1, y-1, aPeca) == 5 || tipoPeca(x-1, y-1, aPeca) == 4 || tipoPeca(x-1, y-1, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x-1][y-1].isDeJose) 
// 		return 1;
// 	else if ((tipoPeca(x+1, y+1, aPeca) == 5 || tipoPeca(x+1, y+1, aPeca) == 4 || tipoPeca(x+1, y+1, aPeca) == 1 || tipoPeca(x+1, y+1, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x+1][y+1].isDeJose) 
// 		return 1;
// 	else if ((tipoPeca(x+1, y-1, aPeca) == 5 || tipoPeca(x+1, y-1, aPeca) == 4 || tipoPeca(x+1, y-1, aPeca) == 0) && aPeca[x][y].isDeJose != aPeca[x+1][y-1].isDeJose) 
// 		return 1;
// 	else if ((tipoPeca(x-1, y+1, aPeca) == 5 || tipoPeca(x-1, y+1, aPeca) == 4 || tipoPeca(x-1, y+1, aPeca) == 1 || tipoPeca(x-1, y+1, aPeca) == 0 ) && aPeca[x][y].isDeJose != aPeca[x-1][y+1].isDeJose) 
// 		return 1;
// 	else
// 		return 0;

// 	return 0;

// }

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
	int i;
	for (i = 1; i < 5; i++) {
		if (testando(x, y, aPeca, i)) 
			return 1;
	}
	return 0;
}

int testando (int x, int y, dadosPosicao aPeca[X][Y], int sentido) 
{
	int i;
	if (sentido == 1) {
		for (i = x; i < X; i++) {
			if (tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) {
				return 1;
			} else if (tipoPeca(i, y, aPeca) != -1) {
				return 0;
			}
		}
	} 
	else if (sentido == 2) {
		for (i = x; i >= 0; i--) {
			if (tipoPeca(i, y, aPeca) == 2 || tipoPeca(i, y, aPeca) == 5) {
				return 1;
			} else if (tipoPeca(i, y, aPeca) != -1) {
				return 0;
			}
		}
	}
	else if (sentido == 3) {
		for (i = y; i < Y; i++) {
			if (tipoPeca(x, i, aPeca) == 2 || tipoPeca(x, i, aPeca) == 5) {
				return 1;
			} else if (tipoPeca(x, i, aPeca) != -1) {
				return 0;
			}
		}	
	}
	else if (sentido == 4) {
		for (i = y; i >= 0; i--) {
			if (tipoPeca(x, i, aPeca) == 2 || tipoPeca(x, i, aPeca) == 5) {
				return 1;
			} else if (tipoPeca(x, i, aPeca) != -1) {
				return 0;
			}
		}		
	}

}