#include <stdio.h>

int main(void)
{
	int n_carros = 0, casas_multa = 0, excesso;
	float valor_total = 0.00, multa = 12.89;


	while (n_carros != 999) {
		scanf("%d", &n_carros);
		
		if (n_carros != 999) {
			excesso = n_carros - 2;

			if (excesso > 0) {
				casas_multa++;
				valor_total = valor_total + excesso*multa;
			}
		
		} else 
			break;
	}

	printf("%.2f\n%d\n", valor_total, casas_multa);

	return 0;
}