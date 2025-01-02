#include <stdio.h>

int findrow(int (*matriz)[5][5]){
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if((*matriz)[i][j] == 1){
                //printf("encontrou\n");
                return i;
            }
        }
    }
    return -1;
}

int findcol(int (*matriz)[5][5]){
    int i, j;
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            if((*matriz)[i][j] == 1){
                //printf("encontrou\n");
                return j;
            }
        }
    }
    return -1;
}

void swaprow(int (*v)[5][5], int row, int mod){
    int i, aux;
    for(i=0; i<5; i++){
        aux = (*v)[row][i];
        (*v)[row][i] = (*v)[row+mod][i];
        (*v)[row+mod][i] = aux;
    }
    //printf("trocou\n");
}

void swapcol(int (*v)[5][5], int row, int mod){
    int i, aux;
    for(i=0; i<5; i++){
        aux = (*v)[i][row];
        (*v)[i][row] = (*v)[i][row+mod];
        (*v)[i][row+mod] = aux;
    }
    //printf("trocou\n");
}

int main(){
    int i, j;
    int matriz[5][5];
    int moves = 0;

    int row;
    int col;

    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    while(matriz[2][2] != 1){
        //printf("procurando\n");
        row = findrow(&matriz);
        col = findcol(&matriz);
        if(row > 2){
            swaprow(&matriz, row, -1);
            moves++;
        }
        if(row < 2){
            swaprow(&matriz, row, 1);
            moves++;
        }
        if(col > 2){
            swapcol(&matriz, col, -1);
            moves++;
        }
        if(col < 2){
            swapcol(&matriz, col, 1);
            moves++;
        }
    }
    printf("%d", moves);
    return(0);
}


