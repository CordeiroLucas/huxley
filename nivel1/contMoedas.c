#include <stdio.h>
 #include <stdlib.h>

int main(void) 
{
	float valor, valor_moedas;
	int notas100, notas50, notas20, notas10, notas5, notas2;
	int moedas1, moedas05, moedas025, moedas010, moedas005, moedas001;

	scanf("%f", &valor);

       if (valor >= 100) {
		notas100 = valor / 100;
		printf("%d nota(s) de R$ 100.00\n", notas100);
		valor = valor - (100*notas100);

	} if (valor >= 50) {
		notas50 = valor / 50;
		printf("%d nota(s) de R$ 50.00\n", notas50);
		valor = valor - (50*notas50);

	} if (valor >= 20) {
		notas20 = valor / 20;
		printf("%d nota(s) de R$ 20.00\n", notas20);
		valor = valor - (20*notas20);

	} if (valor >= 10) {
		notas10 = valor / 10;
		printf("%d nota(s) de R$ 10.00\n", notas10);
		valor = valor - (10*notas10);

	} if (valor >= 5) {
		notas5 = valor / 5;
		printf("%d nota(s) de R$ 5.00\n", notas5);
		valor = valor - (5*notas5);

      	} if (valor >= 2) {
		notas2 = valor / 2;
		printf("%d nota(s) de R$ 2.00\n", notas2);
		valor = valor - (2*notas2);

      	} if (valor >= 1) {
		moedas1 = valor / 1;
		printf("%d moeda(s) de R$ 1.00\n", moedas1);
		valor = valor - moedas1;
	}

	valor_moedas = valor * 100;

	if (valor_moedas >= 50) {
		
		moedas05 = valor_moedas / 50;
		printf("%d moeda(s) de R$ 0.50\n", moedas05);
		valor_moedas = valor_moedas - (50*moedas05);

	} if (valor_moedas >= 25) {
		moedas025 = valor_moedas / 25;
		printf("%d moeda(s) de R$ 0.25\n", moedas025);
		valor_moedas = valor_moedas - (25*moedas025);


	} if (valor_moedas >= 10) {
		moedas010 = valor_moedas / 10;
		printf("%d moeda(s) de R$ 0.10\n", moedas010);
		valor_moedas = valor_moedas - (10*moedas010);


	} if (valor_moedas >= 5) {
		moedas005 = valor_moedas / 5;
		printf("%d moeda(s) de R$ 0.05\n", moedas005);
		valor_moedas = valor_moedas - (5*moedas005);


	} if (valor_moedas >= 1) {
		/*ele por algum motivo ta arrendondando para baixo*/
		if ((int)(valor_moedas) - valor_moedas < -0.910) {
			valor_moedas = (int)(valor_moedas) + 1;
		}
		moedas001 = valor_moedas;

		printf("%d moeda(s) de R$ 0.01\n", moedas001);
		
	}
	return 0;
}
