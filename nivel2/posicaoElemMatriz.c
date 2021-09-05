#include <stdio.h>

int main(void)
{
	int m, n, i, j, k, q, check, check_1, check_2;

	scanf("%d %d", &m, &n);
	
	if (1<=n && m<=1000) {
		int matriz[m][n];

		for (i=0;i<m;i++) 
			for (j=0;j<n;j++)
				scanf("%d", &matriz[i][j]);

		scanf("%d", &q);

		if (1<=q && q<=500000) {

			int list[q];

			for (i=0;i<q;i++) 
				scanf("%d", &list[i]);

			for (k=0;k<q;k++) {
				check_1 = 0;
				check_2 = 0;
				if (list[k] >= matriz[0][0] && list[k] <= matriz[m-1][n-1]) {

					for (i=0;i<m;i++) {
						if (list[k] <= matriz[i][n-1] && list[k] >= matriz[i][0]) {
							check_1 = 1;
							break;  
						} else 
							continue;
					}

					for (j=0;j<n;j++) {
						if (list[k] == matriz[i][j]) {
							check_2 = 1;
							break;
						} else 
							continue;
					}

					if (check_1 == check_2 && check_1 == 1) {
						printf("YES WITH %d AND %d\n", i+1, j+1);
					} else {
						printf("NO\n");
					}
				} else {
					printf("NO\n");
				}
			}

		}
	}
	return 0;
}