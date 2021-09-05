#include <stdio.h>

int main(void)
{
	float a1, a2, a3;
	scanf("%f", &a1);
	scanf("%f", &a2);
	a3 = 180 - (a1+a2);
	printf("3o angulo=%.6f\n", a3);
	return 0;
}