#include<stdio.h>

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
}
