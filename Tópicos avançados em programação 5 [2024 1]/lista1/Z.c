#include <stdio.h>

int main(){
    int n;
    int j = 1;
    int divisoes = 0;
    scanf("%d", &n);

    while(j < n){
        if(n%j == 0){
            //printf("equipes de [%d], %d equipes com %d lideres cada e %d empregados\n", n/j, j, 1, (n/j)-1);
            divisoes++;
        }
        j++;
    }
    printf("%d", divisoes);
    return 0;
}

