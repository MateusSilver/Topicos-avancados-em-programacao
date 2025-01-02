#include <stdio.h>
#include <stdbool.h>

struct cell {
    char straw;
    bool e;
};

bool linhalivre(struct cell *matriz, int n, int m){
    int i, j;
    bool evil = false;
    for(i=0; i<n; i++){
        printf("procurando linha\n");
        evil = false;
        for(j=0; j<m; j++){
            if((matriz+(i*m)+j)->straw == 'S'){
                    printf("findstraw\n");
                evil = true;
            }
        }
        if(evil == false){
            for(j=0; j<m; j++){
                (matriz+(i*m)+j)->e = true;
            }
            return true;
        }
    }
    return false;
}

bool colunalivre(struct cell *matriz, int n, int m){
    int i, j;
    bool evil = false;
    for(i=0; i<n; i++){
        printf("procurando coluna\n");
        evil = false;
        for(j=0; j<m; j++){
            if((matriz+(j*m)+i)->straw == 'S'){
                printf("findStraw\n");
                evil = true;
            }
        }
        if(evil == false){
            for(j=0; j<m; j++){
                (matriz+(j*m)+i)->e = true;
            }
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    int i, j;
    int total = 0;
    scanf("%d %d", &n, &m);

    struct cell matriz[n][m];
    getchar();

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            matriz[i][j].straw = getchar();
            matriz[i][j].e = false;
        }
        getchar();
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%c ", matriz[i][j].straw);
        }
        printf("\n");
    }
    while(linhalivre(matriz,n,m) == true && colunalivre(matriz,n,m) == true){
        printf("procura linha e coluna\n");
        total++;
    }
    printf("%d\n", total);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%d ", &matriz[i][j].e);
        }
        printf("\n");
    }
}
