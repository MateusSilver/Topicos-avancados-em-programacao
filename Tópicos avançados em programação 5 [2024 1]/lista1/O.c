#include <stdio.h>
#include <string.h>

void ordena(int* vetor, int n){
    int i, j;
    int aux;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main(){
    char string[101];
    int vetor[101];
    int i = 0;
    int j = 0;

    scanf("%s", string);
    for(i=0; i<strlen(string); i++){
        if(string[i] != '+'){
            vetor[j] = string[i]-'0';
            j++;
        }
    }
    /*for(i=0; i<j; i++){
        printf("%d ", vetor[i]);
    }*/

    ordena(vetor,j);
    for(i=0; i<j; i++){
        printf("%d", vetor[i]);
        if(i<(j-1)){
            printf("+");
        }
    }
    return(0);
}
