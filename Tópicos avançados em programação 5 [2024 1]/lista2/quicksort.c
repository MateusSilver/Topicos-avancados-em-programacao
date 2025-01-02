#include <stdio.h>


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
}*
