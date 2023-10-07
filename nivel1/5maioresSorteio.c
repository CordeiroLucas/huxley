#include <stdio.h>

const int NMAX = 5;

int check_end(int n, int d);
int insere_ordenado(int n[NMAX], int num);

int main(void)
{
	int i, d, maiores[NMAX], entry;

	for (i = 0; i < NMAX; i++) {
		maiores[i] = -1;
	}

	scanf("%d %d", &i, &d);
	int n[i];	

	if (i >= NMAX && i <= 1000) {
		if (d >= 0 && d <= 9) {
			for (int x = 0; x < i; x++) {
				scanf("%d", &entry);
				n[x] = entry;
			}
		} else return 11;
	} else return 1;

	for (int x = 0; x < i; x++) {
		if (check_end(n[x], d)) {
			insere_ordenado(maiores, n[x]);
		}		
	}

	printf("\n");
	for (int i = 0; i < NMAX; i++) {
		printf("%d\n", maiores[i]);
	}

	return 0;
}

int check_end(int n, int d) 
{
	if ((n-d)%10 == 0) return 1;
	else return 0;
}

int insere_ordenado(int n[NMAX], int num)
{
	for (int i = NMAX-1; i >= 0; i--) {
		if (n[NMAX-1] == -1) {
			n[NMAX-1] = num;
			break;
		} 
		
		if (n[i] <= num) {
			if (i-1 >= 0) {
				n[i-1] = n[i];
				n[i] = num;
				break;
			} else {
				n[i] = num;
				break;
			}
 		} 
	}
	return 0;
}

