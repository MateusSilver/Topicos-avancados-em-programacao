#include <stdio.h>

void marcar(int *matriz, int n, int m, int i, int j){
    int p;
    // marca linha
    for(p=0; p<n; p++){

        *(matriz+(i*j)+p) += 1;
    }
    // marca coluna
    for(p=0; p<m; p++){
        *(matriz +(i*p)+j) += 1;
    }
}

int main(){
    int n, m;
    int marca = 0;
    scanf("%d", &n);
    scanf("%d", &m);

    char matriz[n][m];
    int marcado[n][m];
    int total = 0;

    int i, j, k, p;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            marcado[i][j] = 0;
        }
    }
    getchar();
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            matriz[i][j] = getchar();
        }
        getchar();
    }
    /*
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }*/
    for(i=0; i<n; i++){
        marca = 0;
        for(j=0; j<m; j++){
            if(matriz[i][j] == 'S'){
                // marca linha
                marca++;
            }
        }
        if(marca==0){
            for(p=0; p<n; p++){
                // marca coluna
                marcado[i][p] += 1;
            }
        }

    }
    for(i=0; i<n; i++){
        marca = 0;
        for(j=0; j<m; j++){
            if(matriz[j][i] == 'S'){
                // marca coluna
                marca++;
            }
        }
        if(marca==0){
            for(p=0; p<n; p++){
                marcado[p][i] += 1;
            }
        }

    }

    // conta os comidos
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(marcado[i][j] != 0){
                total++;
            }
        }
    }
/*
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d", marcado[i][j]);
        }
        printf("\n");
    }
*/
    printf("%d", total);
    return(0);
}

