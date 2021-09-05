#include <stdio.h>
#include <math.h>

void parImpar (double n);

int main(void)
{
	double n;

	scanf("%lf", &n);
	if (n <= pow(10, 12)) {
		if (n > 0) {
			printf("POSITIVO ");
			parImpar (n);
		} else if (n == 0) {
			printf("NULO\n");
		} else {
			printf("NEGATIVO ");
			parImpar (n);
		}
	}

	return 0;
}

void parImpar (double n) 
{
	if ((int)n%2 == 0) {
		printf("PAR\n");
	} else {
		printf("IMPAR\n");
	}
}
