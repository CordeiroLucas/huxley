#include <stdio.h>

int main(void) 
{
	const int MAX = 20;
	const int QUIT = -1;

	int n, x, eq = 0, i = 0;
	scanf("%d", &n);
	do {
		scanf("%d", &x);
		if (n == x) eq++;
		i++;
	} while (x != QUIT && i != MAX);
	printf("%d aparece %d vezes\n", n, eq);

	return 0;
}