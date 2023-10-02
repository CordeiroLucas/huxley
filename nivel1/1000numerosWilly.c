#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	const int MAX = 1000;
	int i, k, n, num, array[MAX];
	for (i=0;i<=MAX;i++) {
		if (n != -1) {
			if (i!=MAX){
				scanf("%d", &n);
				array[i] = n;
			} else {
				scanf("%d", &n);
				if (n != -1) {
					k=0;
					for (i=0;i<MAX;i++) {
						if (array[i] == n)
							k++;	
					}
					printf("%d appeared %d times\n", n, k);
					scanf("%d", &n);
					i = 0;
					array[i] = n;
				} else {
					break;
				}
			}
		}	
	}
}