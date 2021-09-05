#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int celulas, eliminacoes;
	int x, y;
	int l, c;
	scanf("%d %d", &x, &y);
	int matriz[x][y];

	celulas = 0;
	for (l=0; l<x; l++){
		for (c=0; c<y; c++){
			scanf("%d", &matriz[l][c]);
			if (matriz[l][c] == 1){
				celulas++;
			}
		}
	}
	scanf("%d", &eliminacoes);

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