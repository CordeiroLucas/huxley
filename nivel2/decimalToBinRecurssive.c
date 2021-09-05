#include <stdio.h>

int to_binario(int n) {
        int x, bin;

        if (n/2 != 0){
                x = n/2;
                to_binario(x);
                bin = n%2;
                printf("%d\n", bin);
        }else{  
                bin = n%2;
                printf("%d\n", bin);
        }
}

int main(void)
{
        int N;
        scanf("%d", &N);
        to_binario(N);
}