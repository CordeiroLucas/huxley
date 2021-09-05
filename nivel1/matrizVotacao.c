#include <stdio.h>

int main(void) 
{
	int i, j, p, e, votos;

	scanf("%d", &p);
	scanf("%d", &e);

	int matriz[p][e];

	for(j=0;j<e;j++) {
		for(i=0;i<p;i++) {
			scanf("%d", &matriz[i][j]);
		}
	}

	for(i=0;i<p;i++) {
		votos = 0;
		for(j=0;j<e;j++) {
			if (matriz[i][j] == 1) {
				votos++;
			}else {
				continue;
			}
		}
		printf("Princesa %d: %d voto(s)\n", i+1, votos);
	}
	return 0;
}