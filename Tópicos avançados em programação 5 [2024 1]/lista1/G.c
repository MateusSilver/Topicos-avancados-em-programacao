#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int i, j;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    char luck[n][101];
    int cont = 0;
    int total = 0;

    for(i=0; i<n; i++){
        scanf("%s", luck[i]);
    }

    for(i=0; i<n; i++){
        cont = 0;

        for(j=0; luck[i][j] != '\0'; j++){
            if(luck[i][j] == '7' || luck[i][j] == '4'){
                cont++;
            }
        }
        if(cont <= k){
            total++;
        }
    }

    printf("%d", total);
    return(0);
}
