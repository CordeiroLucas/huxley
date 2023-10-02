#include <stdio.h>

int main(void) 
{
	int x, i, MAX = 10;
	scanf("%d", &x);
	for(i=x; i/x <= MAX; i+=x) {
		printf("%d\n", i);
	}
	return 0;
}