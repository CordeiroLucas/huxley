#include <stdio.h>

int main(void)
{
	int ix, iy, x, y, sumDiagPri = 0, sumDiagSec = 0, diagGet, menoresqZero = 0, maioresqZero = 0;

	scanf("%d %d", &x, &y);
	int matriz[x][y];

	for(ix=0; ix<x; ix++) {
		for(iy=0; iy<y; iy++) {
			scanf("%d", &matriz[ix][iy]);
			if (x == y) {
				diagGet = 1;
				
				if (ix == iy) {
					sumDiagPri = sumDiagPri + matriz[ix][iy];
				} 

				if ((ix + iy) == (x - 1)) {
					sumDiagSec = sumDiagSec + matriz[ix][iy];
				} 

				
			} else {
				diagGet = 0;
			}

			if (matriz[ix][iy] < 0) {
				menoresqZero++;
			} else if (matriz[ix][iy] > 0) {
				maioresqZero++;
			}
		}
	}

	printf("Matriz formada:\n");

	for (ix=0; ix<x; ix++) {
		for (iy=0; iy<y; iy++) {
			if (iy == y-1) {
				printf("%d\n", matriz[ix][iy]);
			} else {
				printf("%d ", matriz[ix][iy]);
			}
		}
	}
	if (diagGet) {
		printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.\n", sumDiagPri, sumDiagSec);
	} else {
		printf("A diagonal principal e secundaria nao pode ser obtida.\n");
	}

	printf("A matriz possui %d numero(s) menor(es) que zero.\n", menoresqZero);
	printf("A matriz possui %d numero(s) maior(es) que zero.\n", maioresqZero);

	return 0;
}