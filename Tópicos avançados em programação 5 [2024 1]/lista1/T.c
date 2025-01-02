#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char matriz[n][m];
    int i, j;
    int right = 1;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(i%2 == 0){
                matriz[i][j] = '#';
            } else {
                matriz[i][j] = '.';
            }
        }
    }
    for(i=0; i<n; i++){
        if(i%2 != 0 && right == 1){
            matriz[i][m-1] = '#';
            right = 0;
        } else {
            if(i%2 != 0 && right == 0){
                matriz[i][0] = '#';
                right = 1;
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    return(0);
}

