/*
/*
Bruna é uma sublime matemática, por isso seus amigos geralmente tentam lhe propor desafios, esperando que
 alguma hora ela não consiga responder. Um de seus colegas, Zelda, a desafiou da seguinte forma: Dada uma matriz NxN (1 <= N <= 100),
 conseguir achar a área do maior quadrado formado por ‘1’ na matriz fornecida.

Como ela é esperta, para que pudesse poupar seu precioso tempo dedicado a assistir séries, jogar e estudar, pediu para que você criasse
 um algoritmo para ela que, fornecida a matriz binária, resolva o problema dado por Zelda.
*/

/*
AINDA NADA
*/

#include <stdio.h>
#include <stdlib.h>

int quadrado(int N, int matriz[N][N]);

int main (void)
{
	int N, i, j, resultado;

	while (1) {
		if (scanf("%d", &N) != EOF) {
			int matriz[N][N];

			for (j = 0; j < N; j++) 
				for (i = 0; i < N; i++)
					scanf("%d", &matriz[i][j]);
		
			printf("\n");
			resultado = quadrado (N, matriz);

			printf("\n%d\n", resultado);

		} else
			return 0;


		
	}
}

int quadrado (int N, int matriz[N][N])
{
	int j, i, quadrado, lengh, posicaoX, posicaoY, tam;

	for (j = 0; j < N; j++) {
		
		for (i = 0; i < N; i++) {
			if (i == 0) {
				lengh = 0;
				if (matriz[i][j] == 1) 
					posicaoX = i;
					lengh++;

			} else {
				if (matriz[i-1][j] == matriz[i][j] && matriz[i][j] == 1) 
					lengh++;
				else if (matriz[i][j] == 1 && i != 0) {
					posicaoX = i;
					lengh = 1;
				}
			}
		}

		if (j > 0) {
				if (matriz[posicaoX][j] == matriz[posicaoX][j-1] && matriz[posicaoX][j] == 1) {
					for (tam = 0; tam <= lengh; tam++) {
						if (matriz[posicaoX + 1][j] == 1) {
							continue;
						} else
							lengh = tam;
							break;
					}
				}
			}
			
		/*
		print para checar se ele está contando certo
		*/
		printf("y[%d] - lengh %d - lengh starts on [%d][%d]", j, lengh, posicaoX, j);
		printf("\n");
	}
	lengh = lengh*lengh;
	return lengh;
}