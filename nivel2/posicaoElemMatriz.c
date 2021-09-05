#include <stdio.h>


/*
A questão quer que façamos uma busca de vários elementos numa matriz ORDENADA. 
*/

int main(void)
{
	/*
	Var. para o tamanho da matriz[m][n].
	*/
	int m, n;
	/*
	Var. para percorrer a matriz.
	*/
	int i, j, k;
	/*
	Var. para o tamanho do array de elementos.
	*/
	int q;
	/*
	check_1 retorna 1 caso o elemento atual >= primeiro elemento da linha m e elemento atual <= ultimo da linha m
	check_2 retorna 1 caso o for encontre o elemento na linha m

	Para caso ambas terminarem com 1, significa que o elemento foi encontrado
	Se ambas passarem pela porta AND "line 62", ele printa as coordenadas do elemento.
	 
	*/
	int check_1, check_2;

	scanf("%d %d", &m, &n);
	
	/*
	Verificação para os tamanhos [m][n] da matriz
	*/

	if (1<=n && m<=1000) {
		int matriz[m][n];

		for (i=0;i<m;i++) 
			for (j=0;j<n;j++)
				scanf("%d", &matriz[i][j]);

		scanf("%d", &q);

		/*
		Verificação para o tamanho [q] do array
		*/

		if (1<=q && q<=500000) {

			int list[q];

			/*
			Atribuindo valores ao array de elementos, os quais o código irá buscar na matriz.
			*/

			for (i=0;i<q;i++) 
				scanf("%d", &list[i]);

			
			/*
			Percorrendo o array de elementos para busca na matriz
			*/

			for (k=0;k<q;k++) {
				check_1 = 0;
				check_2 = 0;

				/*
				Checagem para saber se o elemento[k] está inserido no conjunto
				*/

				if (list[k] >= matriz[0][0] && list[k] <= matriz[m-1][n-1]) {

					for (i=0;i<m;i++) {
						if (list[k] <= matriz[i][n-1] && list[k] >= matriz[i][0]) {
							check_1 = 1;
							break;  
						} else 
							continue;
					}

					for (j=0;j<n;j++) {
						if (list[k] == matriz[i][j]) {
							check_2 = 1;
							break;
						} else 
							continue;
					}

					if (check_1 == check_2 && check_1 == 1) {
						printf("YES WITH %d AND %d\n", i+1, j+1);
					} else {
						printf("NO\n");
					}
				} else {
					printf("NO\n");
				}
			}

		}
	}
	return 0;
}