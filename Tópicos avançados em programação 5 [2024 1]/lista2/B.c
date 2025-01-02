#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void sort(char* m, int n){
    int i;
    int j = 0;
    char aux;

    for(i=1; i<n; i++){
        aux = m[i];
        j = i-1;

        while(j>=0 && m[j] > aux){
            m[j+1] = m[j];
            j--;
        }
        m[j+1] = aux;
    }
}*/

/*
void quicksort(char* s, int inicio, int fim){
    int i = inicio;
    int j = fim-1;
    int aux;

    int pivo = s[(inicio+fim)/2];

    while(s[i] < pivo && i<fim){
        i++;
    }
    while(s[j] > pivo && j>0){
        j--;
    }

    if(i<=j){
        aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        i++;
        j--;
    }
    if(j>inicio){
        quicksort(s, inicio, j+1);
    }
    if(i<fim){
        quicksort(s,i, fim);
    }
}*/

int compara(const void *a, const void *b){
    return (*(char*)a - *(char*)b);
}


int main(){
    char string[200001];
    scanf("%s", string);

    qsort(string, strlen(string), sizeof(char), compara);

    printf("%s", string);
    return 0;
}
