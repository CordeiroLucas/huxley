#include <stdio.h>

int main(void)
{
        int n1, n2;

        scanf("%d %d", &n1, &n2);
        if (n1>n2) {
                printf("%d %d\n", n2, n1);
        } else {
                printf("%d %d\n", n1, n2);
        }

        return 0;
}