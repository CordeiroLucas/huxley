#include <stdio.h>
#include <stdlib.h>

int  divisao (int c, int m, int p);

int main(void)
{
	int c, m, p, i;
	i=0;

	while (scanf("%d %d %d", &c, &m, &p) != EOF) {
		if (divisao (c, m, p)) 
			printf("Sim\n");
		else 
			printf("Nao\n");
	}


}

int  divisao (int c, int m, int p)
{
	if (c == 0) {
		return 1;
	} else {
		if (m - p >= 0) {
			divisao (c-1 ,m-p, p);
		} else {
			return 0;
		}
	}
}