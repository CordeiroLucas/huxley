#include <stdio.h>
#include <stdlib.h>


/*
Na execução dessa questão parece que ele transpõe a matriz, mas
é apenas na eliminação que fica invertido. Mas pelo the huxley
ta tudo certo, e depois do estresse que tive p fazer dar certo
lá... mas qualquer sugestão é válida.
*/

/*
Recebe uma matriz[x][y] com 0s e 1s sendo onde houver 1s
significa que há uma célula viva no index indicado.
*/


int main(void)
{

	/*
	Entrada para definir o tamanho da matriz de células
	*/

	int celulas, eliminacoes;
	int x, y;

	/*
	lines and columns
	*/

	int l, c;
	scanf("%d %d", &x, &y);
	int matriz[x][y];


	/*
	A questão pede a quantidade de células vivas no final, assim como caso não
	 tenha mais nenhuma célula restante, ele irá printar a quantidade de eliminações que restaram.
	*/

	celulas = 0;
	for (l=0; l<x; l++){
		for (c=0; c<y; c++){
			scanf("%d", &matriz[l][c]);
			if (matriz[l][c] == 1){
				celulas++;
			}
		}
	}

	/*
	Recebe o número de eliminações que o usuário quer fazer...
	*/

	scanf("%d", &eliminacoes);

	/*
	Se o x da matriz for par, as eliminações serão feitas na horizontal
	caso contrário, na vertical.
	*/

	if (x%2 != 0){
		for (c=0; c<y; c++){
			if (eliminacoes>0){
				for (l=0; l<x; l++){
					if (eliminacoes>0 && matriz[l][c] == 1){
						matriz[l][c] = 0;
						eliminacoes--;
						celulas--;
					}
				}
			}
		}
	}else{
		for (l=0; l<x; l++){
			if (eliminacoes>0){
				for (c=0; c<y; c++){
					if (eliminacoes>0 && matriz[l][c] == 1){
						matriz[l][c] = 0;
						eliminacoes--;
						celulas--;
					}
				} 
			}   
		}
	}

	for (l=0; l<x; l++){
		for (c=0; c<y; c++){
			if (c != 0){
				printf(" ");
			}
			printf("%d", matriz[l][c]);
			
		}
		printf("\n");
	}
	printf("%d %d\n", eliminacoes, celulas);
	return 0;
}