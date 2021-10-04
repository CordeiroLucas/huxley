#include <stdio.h>
#include <stdlib.h>

int topOrBottom (int matriz[3][3]); 

int main (void)
{
	int matriz[3][3], i, j, tipoMatriz;

	while(1) {
		for (j = 0; j < 3; j++) 
			for (i = 0; i < 3; i++) 
				if (scanf("%d", &matriz[i][j]) != EOF)
					continue;
				else return 0;
				
		if (topOrBottom(matriz) == 0)
			printf("Nao pode atravessar\n");

		else {

			if (topOrBottom(matriz) == 1)
				printf("Por cima\n");

			else if (topOrBottom(matriz) == -1) 
				printf("Por baixo\n");

		}
	}
}

int topOrBottom (int matriz[3][3]) 
{
	int toAvoid, i;
	i = 0; 
	toAvoid = 0;

	if (matriz[1][0] == 0 && matriz[2][0] == 0 && matriz[2][1] == 0) {
		i++;
		toAvoid = 1;
	} 
	
	if (matriz[0][1] == 0 && matriz[0][2] == 0 && matriz[1][2] == 0) {
		i++;
		toAvoid = -1;
	}
	
	if (i > 1)
		return 0;

	return toAvoid;
	
}