#include <stdio.h>
 #include <stdlib.h>

int main(void)
{
	const int proffessors = 7;
	int boxes, i, capsules, total=0, capsules_proffessor, xicaras;
	char box_type;


	while(i<proffessors) {
		scanf("%d", &boxes);
		scanf("%c", &box_type);

		if (box_type == 'P' || box_type == 'p') {
			capsules = boxes * 10;
			total = capsules + total;
			i++;
		} else if (box_type == 'G'|| box_type == 'g') {
			capsules = boxes * 16;
			total = capsules + total;
			i++;
		}
	}
	capsules_proffessor = total / proffessors;
	xicaras = capsules_proffessor * 2;
	printf("%d\n%d\n", total, xicaras);
	return 0;
}
