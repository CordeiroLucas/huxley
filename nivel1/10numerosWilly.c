#include <stdio.h>

int main(void) 
{
	const int MAX = 10;
	int i, n, n_comp, total;

	while (n != -1) {
		if (n != -1) {
			total = 0;
			scanf("%d", &n);
			if (n != -1) {
				for (i=0;i<MAX;i++) {
					scanf("%d", &n_comp);

					if (n_comp == n) {
						total++;
					} else if (n_comp == -1) {
						break;
					}
				}
				printf("%d appeared %d times\n", n, total);
			} else {
				break;
			}
		} else {
			break;
		}
	}

	return 0;
}